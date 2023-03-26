#include "chess.h"

Chess::Chess()
{
}

Chess::~Chess()
{
    delete board;
    delete fpsCamera;
    delete camera;
    delete bg;
    delete light;
    delete chess;
}

void Chess::Init()
{
    camera    = new Camera(glm::vec3(-9.683014, 16.498363, 7.318779), glm::vec3(0.0, 1.0, 0.0), 2, -41, 0);
    fpsCamera = new FPSCamera(camera);
    fps       = new FPSCounter();
    bg        = new Background(
                "data/cubemap_yoko/negz.jpg",
                "data/cubemap_yoko/posz.jpg",
                "data/cubemap_yoko/posy.jpg",
                "data/cubemap_yoko/negy.jpg",
                "data/cubemap_yoko/negx.jpg",
                "data/cubemap_yoko/posx.jpg",
                camera);

    light     = new PointLight(glm::vec3(-9.683014, 16.498363, 7.318779));
    board     = new Board();

    fpsCamera->UpdateCamera();

    components.Add(camera);
    components.Add(fpsCamera);
    components.Add(fps);
    components.Add(bg);
    components.Add(board);
    components.Add(light);

    dragging = false;
    activePiece = NULL;
    timer = Application::GetTime();

    gameOver = false;
    isWhitesTurn = true;
    moves = 0;

    chess = new Cell(8, 8);

    chess->At(0, 0) = ROOK;
    chess->At(1, 0) = KNIGHT;
    chess->At(2, 0) = BISHOP;
    chess->At(3, 0) = QUEEN;
    chess->At(4, 0) = KING;
    chess->At(5, 0) = BISHOP;
    chess->At(6, 0) = KNIGHT;
    chess->At(7, 0) = ROOK;

    chess->At(0, 7) = rook;
    chess->At(1, 7) = knight;
    chess->At(2, 7) = bishop;
    chess->At(3, 7) = king;
    chess->At(4, 7) = queen;
    chess->At(5, 7) = bishop;
    chess->At(6, 7) = knight;
    chess->At(7, 7) = rook;

    chess->At(0, 1) = PAWN;
    chess->At(1, 1) = PAWN;
    chess->At(2, 1) = PAWN;
    chess->At(3, 1) = PAWN;
    chess->At(4, 1) = PAWN;
    chess->At(5, 1) = PAWN;
    chess->At(6, 1) = PAWN;
    chess->At(7, 1) = PAWN;

    chess->At(0, 6) = pawn;
    chess->At(1, 6) = pawn;
    chess->At(2, 6) = pawn;
    chess->At(3, 6) = pawn;
    chess->At(4, 6) = pawn;
    chess->At(5, 6) = pawn;
    chess->At(6, 6) = pawn;
    chess->At(7, 6) = pawn;
}

void Chess::Move(ChessMove move)
{
}

Array<ChessMove> Chess::GetMoves()
{
    Array<ChessMove> moves;

    for (unsigned int i = 0; i < chess->cells.Size(); i++)
    {
        moves.Add(ChessMove("a1", "a2", "tag"));
    }

    return moves;
}

// Forsyth–Edwards Notation
// https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation
String Chess::FEN()
{
    String fen;

    // Record board pieces state
    for (unsigned int i = 0; i < chess->width; i++)
    {
        for (unsigned int j = 0; j < chess->height; j++)
        {
            int piece = chess->At(i, j);

            if (piece != -1)
            {
                String code;

                switch(piece)
                {
                case PAWN:
                    code.Append("P");
                    break;
                case QUEEN:
                    code.Append("Q");
                    break;
                case KING:
                    code.Append("K");
                    break;
                case BISHOP:
                    code.Append("B");
                    break;
                case ROOK:
                    code.Append("R");
                    break;
                case KNIGHT:
                    code.Append("N");
                    break;
                case pawn:
                    code.Append("p");
                    break;
                case queen:
                    code.Append("q");
                    break;
                case king:
                    code.Append("k");
                    break;
                case bishop:
                    code.Append("b");
                    break;
                case rook:
                    code.Append("r");
                    break;
                case knight:
                    code.Append("n");
                    break;
                default:
                    LogWarning("Unknown chess piece detected");
                }

                switch(i)
                {
                case 0:
                    code.Append("a");
                    break;
                case 1:
                    code.Append("b");
                    break;
                case 2:
                    code.Append("c");
                    break;
                case 3:
                    code.Append("d");
                    break;
                case 4:
                    code.Append("e");
                    break;
                case 5:
                    code.Append("f");
                    break;
                case 6:
                    code.Append("g");
                    break;
                case 7:
                    code.Append("h");
                    break;
                default:
                    LogWarning("Unknown horizontal position of chess piece detected");
                }

                switch(j)
                {
                case 0:
                    code.Append("1");
                    break;
                case 1:
                    code.Append("2");
                    break;
                case 2:
                    code.Append("3");
                    break;
                case 3:
                    code.Append("4");
                    break;
                case 4:
                    code.Append("5");
                    break;
                case 5:
                    code.Append("6");
                    break;
                case 6:
                    code.Append("7");
                    break;
                case 7:
                    code.Append("8");
                    break;
                default:
                    LogWarning("Unknown vertical position of chess piece detected");
                }

                fen.Append(code);
                fen.Append(" ");
            }
        }
    }

    // Record whose turn it is
    if (isWhitesTurn)
    {
        fen.Append("w");
    }
    else
    {
        fen.Append("b");
    }

    // Is castling possible TODO: Add this
    fen.Append(" - ");

    // En passant target squar TODO: Add this
    fen.Append(" - ");

    // Halfmove clock TODO: Add this
    fen.Append(" 0 ");

    // Fullmove number
    fen.Append(moves);

    return fen;
}

void Chess::MakeRandomMove()
{
    // Chess gives us all the possible moves in an array
    // [ move1, move2, move3 ... ]
    Array<ChessMove> possibleMoves = GetMoves();

    // Exit if the game is over
    if (gameOver == true) return;

    // Chooses a random index in the list
    unsigned int randomIdx = possibleMoves.Size() - 1; // TODO: Make random

    // Updates board state
    Move(possibleMoves[randomIdx]);

    // Changes board visual state
    board->Position(FEN());
}


void Chess::Update()
{
#ifdef TILTFIVE
    if (input.Head.active)
    {
        camera->position = glm::vec3(input.Head.x, input.Head.y, input.Head.z); // Notice tilt5 uses +Z as a up direction while we use Y
        camera->position *= -10;

        camera->roll  = input.Head.roll;
        camera->pitch = input.Head.pitch;
        camera->yaw   = input.Head.yaw;

        fpsCamera->UpdateCamera();
        /*camera->forward.x = camera->roll;
        camera->forward.y = camera->yaw;
        camera->forward.z = camera->pitch;
        camera->forward = glm::normalize(camera->forward);

        camera->right = glm::normalize(glm::cross(camera->forward, camera->worldUp));
        camera->up = glm::normalize(glm::cross(camera->right, camera->forward));*/
    }
    else
    {
        camera->position = glm::vec3(-9.683014, 16.498363, 7.318779);
        camera->yaw = 2;
        camera->pitch = -41;
        camera->roll = 0;

        fpsCamera->UpdateCamera();
    }

    printf("Glasses position: '%f %f %f\n", input.Head.x, input.Head.y, input.Head.z);
    printf("camera position: '%f %f %f\n", camera->position.x, camera->position.y, camera->position.z);
#endif

    if (int(timer->TimeSinceStarted()) > 5000)
    {
        MakeRandomMove();
        timer->Reset();
    }

    if (input.Mouse.Released)
    {
        dragging = false;
        input.Mouse.Dragging = false;
        if (activePiece)
        {
            activePiece->Uniform("colour", glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
        }
        //input.Mouse.Hidden = false;
    }

    if (dragging)
    {
        input.Mouse.Dragging = true;
        //input.Mouse.Hidden = true;

        if (activePiece)
        {
            activePiece->matrix.Translate(glm::vec3(float(-input.Mouse.dy) / 100.0, 0.0, float(input.Mouse.dx) / 100.0));
        }
    }

    for (unsigned int i = 0; i < board->components.Size(); i++)
    {
        Actor *piece = dynamic_cast<Actor*>(board->components[i]);
        if (piece->tag.Empty() == false) // board itself has tag ""
        {
            piece->Uniform("u_lightPosition", static_cast<glm::vec3>(light->position));
            piece->Uniform("u_cameraPosition", static_cast<glm::vec3>(camera->position));
        }
    }

    if (input.Mouse.Pressed)
    {
        for (unsigned int i = 0; i < board->components.Size(); i++)
        {
            Actor *piece = dynamic_cast<Actor*>(board->components[i]);
            //Log(piece->tag);

            if (piece->tag.Empty() == false) // board itself has tag ""
            {
                IPhysics::Ray cameraRay = camera->ScreenPointToRay(input.Mouse.x, input.Mouse.y);

                if (physics->Intersect(cameraRay, piece->hitbox))
                {
                    Log(piece->tag);
                    activePiece = piece;
                    activePiece->Uniform("colour", glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
                    dragging = true;
                    break;
                }
            }
        }
    }
}

void Chess::UpdateAfterPhysics()
{

}
