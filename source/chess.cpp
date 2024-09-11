#include "chess.h"

Chess::Chess()
{
}

Chess::~Chess()
{
}

void Chess::Init()
{
    camera    = new Camera(glm::vec3(-9.683014, 16.498363, 7.318779), glm::vec3(0.0, 1.0, 0.0), 2, -41, 0);
    fpsCamera = new FPSCamera(camera);
    fps       = new FPSCounter();
    board     = new Board();
    bg        = new Background(
                "data/cubemap_yoko/negz.jpg",
                "data/cubemap_yoko/posz.jpg",
                "data/cubemap_yoko/posy.jpg",
                "data/cubemap_yoko/negy.jpg",
                "data/cubemap_yoko/negx.jpg",
                "data/cubemap_yoko/posx.jpg",
                camera);

    light     = new PointLight(glm::vec3(-9.683014, 16.498363, 7.318779));
    text      = new Text("CHESS GAME", 100, 100, 3.0f, 3.0f);
    pointer   = new Sprite("data/cursor.png", 0, 0, 0.5, 0.5);

    fpsCamera->UpdateCamera();

    components.Add(text);
    components.Add(pointer);
    components.Add(camera);
    //components.Add(fpsCamera);
    components.Add(fps);
    components.Add(bg);
    components.Add(board);
    components.Add(light);

    dragging = false;
    activePiece = NULL;
    timer = Application::GetTime();

    check = false;
    gameOver = false;
    isWhitesTurn = true;
    moveQuantity = 0;

    playing = true;
    fenPosition = 0;

    chess = new Grid(8, 8);

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

    // Update board state based on chess grid
    board->Position(FEN());

    // Adding tiles to scene to do *collision against
    boardTileCollisionBoxes.Resize(8*8);
    float tileSize = 64.0f;
    float x = 0.0f;
    float y = 0.0f;

    for (unsigned int i = 0; i < 8 * 8; i++)
    {
        boardTileCollisionBoxes[i] = new Actor();
        boardTileCollisionBoxes[i]->matrix.Translate(glm::vec3(x * tileSize, y * tileSize, 0));
        components.Add(boardTileCollisionBoxes[i]);

        x++;

        if (i % 8 == 0)
        {
            y++;
            x = 0;
        }
    }
}

void Chess::Move(ChessMove move)
{
    unsigned int type1 = chess->At(move.position.startPos.x, move.position.startPos.y);
    unsigned int type2 = chess->At(move.position.endPos.x, move.position.endPos.y);

    chess->At(move.position.startPos.x, move.position.startPos.y) = Grid::EMPTY;
    chess->At(move.position.endPos.x, move.position.endPos.y) = type1;

    if (check)
    {
        GetMoves();

        if (check)
        {
            // Move back, still in check...
            chess->At(move.position.startPos.x, move.position.startPos.y) = type1;
            chess->At(move.position.endPos.x, move.position.endPos.y) = type2;

            return;
        }
    }

    isWhitesTurn = !isWhitesTurn;

    GetMoves();

    if (check)
    {
        // Move back, putting yourself in check is illegal
        chess->At(move.position.startPos.x, move.position.startPos.y) = type1;
        chess->At(move.position.endPos.x, move.position.endPos.y) = type2;

        isWhitesTurn = !isWhitesTurn;

        return;
    }

    moveQuantity++;
}

bool Chess::CheckMove(ChessMove &move)
{
    // Moving to an empty space is always legal
    if (chess->At(move.position.endPos.x, move.position.endPos.y) == Grid::EMPTY)
    {
        return true;
    }
    // Moving to an enemy space is legal for all pieces except for pawn
    else if ((move.type >= pawn &&
              (chess->At(move.position.endPos.x, move.position.endPos.y) <= KING)) ||
             (move.type < pawn &&
              (chess->At(move.position.endPos.x, move.position.endPos.y) >= pawn &&
               chess->At(move.position.endPos.x, move.position.endPos.y) <= king)))
    {
        // Pawn is a special case as they can't attack moving forwards
        if (move.type == pawn || move.type == PAWN)
        {
            if (move.position.startPos.x == move.position.endPos.x)
            {
                return false;
            }
        }

        move.capture = true;

        // If this move kills the king, the king is in check
        if (chess->At(move.position.endPos.x, move.position.endPos.y)== KING ||
            chess->At(move.position.endPos.x, move.position.endPos.y) == king)
        {
            check = true;
        }

        return true;
    }

    return false;
}

Array<ChessMove> Chess::GetKingMoves(unsigned int x, unsigned int y, unsigned int type)
{
    Array<ChessMove> moves;
    ChessMove move(x, y, type);

    if (CheckMove(move.Move(x+1, y)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x-1, y)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x, y+1)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x, y-1)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x+1, y+1)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x-1, y+1)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x+1, y-1)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x-1, y-1)))
    {
        moves.Add(move);
    }

    return moves;
}

Array<ChessMove> Chess::GetPawnMoves(unsigned int x, unsigned int y, unsigned int type)
{
    Array<ChessMove> moves;
    ChessMove move(x, y, type);

    if (type == PAWN) // white pawn
    {
        if (CheckMove(move.Move(x, y+1)))
        {
            moves.Add(move);

            if (y == 1)
            {
                if (CheckMove(move.Move(x, y+2)))
                {
                    moves.Add(move);
                }
            }
        }
        if (CheckMove(move.Move(x+1, y+1)))
        {
            if (move.capture == true)
            {
                moves.Add(move);
            }
        }
        if (CheckMove(move.Move(x-1, y+1)))
        {
            if (move.capture == true)
            {
                moves.Add(move);
            }
        }
    }
    else if (type == pawn) // black pawn
    {
        if (CheckMove(move.Move(x, y-1)))
        {
            moves.Add(move);

            if (y == 6)
            {
                if (CheckMove(move.Move(x, y-2)))
                {
                    moves.Add(move);
                }
            }
        }
        if (CheckMove(move.Move(x+1, y-1)))
        {
            if (move.capture == true)
            {
                moves.Add(move);
            }
        }
        if (CheckMove(move.Move(x-1, y-1)))
        {
            if (move.capture == true)
            {
                moves.Add(move);
            }
        }
    }
    else
    {
        LogError("GetPawnMoves called with illegal type");
    }

    return moves;
}

Array<ChessMove> Chess::GetRookMoves(unsigned int x, unsigned int y, unsigned int type)
{
    Array<ChessMove> moves;
    ChessMove move(x, y, type);

    for (unsigned int i = 1; CheckMove(move.Move(x+i, y)); i++)
    {
        moves.Add(move);

        if (move.capture)
        {
            break;
        }
    }

    for (unsigned int i = 1; CheckMove(move.Move(x-i, y)); i++)
    {
        moves.Add(move);

        if (move.capture)
        {
            break;
        }
    }

    for (unsigned int i = 1; CheckMove(move.Move(x, y+i)); i++)
    {
        moves.Add(move);

        if (move.capture)
        {
            break;
        }
    }

    for (unsigned int i = 1; CheckMove(move.Move(x, y-i)); i++)
    {
        moves.Add(move);

        if (move.capture)
        {
            break;
        }
    }

    return moves;
}

Array<ChessMove> Chess::GetQueenMoves(unsigned int x, unsigned int y, unsigned int type)
{
    Array<ChessMove> moves;

    moves += GetRookMoves(x, y, type);
    moves += GetBishopMoves(x, y, type);

    return moves;
}

Array<ChessMove> Chess::GetBishopMoves(unsigned int x, unsigned int y, unsigned int type)
{
    Array<ChessMove> moves;
    ChessMove move(x, y, type);

    for (unsigned int i = 1; CheckMove(move.Move(x+i, y+i)); i++)
    {
        moves.Add(move);

        if (move.capture)
        {
            break;
        }
    }

    for (unsigned int i = 1; CheckMove(move.Move(x-i, y-i)); i++)
    {
        moves.Add(move);

        if (move.capture)
        {
            break;
        }
    }

    for (unsigned int i = 1; CheckMove(move.Move(x+i, y-i)); i++)
    {
        moves.Add(move);

        if (move.capture)
        {
            break;
        }
    }

    for (unsigned int i = 1; CheckMove(move.Move(x-i, y+i)); i++)
    {
        moves.Add(move);

        if (move.capture)
        {
            break;
        }
    }

    return moves;
}

Array<ChessMove> Chess::GetKnightMoves(unsigned int x, unsigned int y, unsigned int type)
{
    Array<ChessMove> moves;
    ChessMove move(x, y, type);

    if (CheckMove(move.Move(x+1, y+2)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x-1, y+2)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x+2, y+1)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x-2, y+1)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x+2, y-1)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x-2, y-1)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x+1, y-2)))
    {
        moves.Add(move);
    }
    if (CheckMove(move.Move(x-1, y-2)))
    {
        moves.Add(move);
    }

    return moves;
}

Array<ChessMove> Chess::GetMoves()
{
    Array<ChessMove> moves;
    check = false;

    for (unsigned int x = 0; x < chess->width; x++)
    {
        for (unsigned int y = 0; y < chess->height; y++)
        {
            int type = chess->At(x, y);

            if (type != -1)
            {
                if (isWhitesTurn)
                {
                    switch(type)
                    {
                    case KING:
                        moves += GetKingMoves(x, y, type);
                        break;
                    case QUEEN:
                        moves += GetQueenMoves(x, y, type);
                        break;
                    case ROOK:
                        moves += GetRookMoves(x, y, type);
                        break;
                    case KNIGHT:
                        moves += GetKnightMoves(x, y, type);
                        break;
                    case BISHOP:
                        moves += GetBishopMoves(x, y, type);
                        break;
                    case PAWN:
                        moves += GetPawnMoves(x, y, type);
                        break;
                    //default:
                    //    LogWarning("Piece either unknown or black");
                    }
                }
                else
                {
                    switch (type)
                    {
                    case king:
                        moves += GetKingMoves(x, y, type);
                        break;
                    case queen:
                        moves += GetQueenMoves(x, y, type);
                        break;
                    case knight:
                        moves += GetKnightMoves(x, y, type);
                        break;
                    case bishop:
                        moves += GetBishopMoves(x, y, type);
                        break;
                    case rook:
                        moves += GetRookMoves(x, y, type);
                        break;
                    case pawn:
                        moves += GetPawnMoves(x, y, type);
                        break;
                    //default:
                    //    LogWarning("Piece either unknown or white");
                    }
                }
            }
        }
    }

    if (moves.Empty())
    {
        gameOver = true;
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
            unsigned int piece = chess->At(i, j);

            if (piece != Grid::EMPTY)
            {
                ChessMove move(i, j, piece);
                String code = move.algebraicNotation;

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
    fen.Append(moveQuantity);

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
    unsigned int randomIdx = random.RandomRange(0, possibleMoves.Size());

    // Updates board state
    Move(possibleMoves[randomIdx]);

    // Changes board visual state
    board->Position(FEN());
}

bool Chess::MakeCapture()
{
    // Chess gives us all the possible moves in an array
    // [ move1, move2, move3 ... ]
    Array<ChessMove> possibleMoves = GetMoves();

    // Exit if the game is over
    if (gameOver == true) return false;

    // Chooses the first capture in the list
    for (unsigned int i = 0; i < possibleMoves.Size(); i++)
    {
        if (possibleMoves[i].capture)
        {
            Move(possibleMoves[i]);

            // Changes board visual state
            board->Position(FEN());

            return true;
        }
    }

    return false;
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

    /*if (int(timer->TimeSinceStarted()) > 1000)
    {
        MakeRandomMove();
        timer->Reset();
    }*/

    // Update mouse cursor graphics position
    *pointer->matrix.x = float(input.Mouse.x - pointer->halfWidth);
    *pointer->matrix.y = float(input.Mouse.y - pointer->halfHeight);

    // Update chess game moves
    if (playing)
    {
        fens.Add(FEN());

        if (MakeCapture() == false)
        {
            MakeRandomMove();
        }
    }
    else
    {
        if (input.Pressed(input.Key.LEFT))
        {
            if (fenPosition > 0)
            {
                fenPosition--;
            }
        }
        if (input.Pressed(input.Key.RIGHT))
        {
            if (fenPosition < int(fens.Size() - 1))
            {
                fenPosition++;
            }
        }

        board->Position(fens[fenPosition]);
    }

    if (input.Released(input.Key.SPACE))
    {
        playing = !playing;

        fenPosition = int(fens.Size() - 1);
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
        Actor *piece = dynamic_cast<Actor*>(*board->components[i]);
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
            Actor *piece = dynamic_cast<Actor*>(*board->components[i]);
            //Log(piece->tag);

            if (piece->tag.Empty() == false) // board itself has tag ""
            {
                Physics::IPhysics::Ray cameraRay = camera->ScreenPointToRay(input.Mouse.x, input.Mouse.y);

                if (physics->Intersect(cameraRay, piece->collisionBox))
                {
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
