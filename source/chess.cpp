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
}

void Chess::Move(ChessMove move)
{
}

Array<ChessMove> Chess::GetMoves()
{
    Array<ChessMove> moves;
    moves.Add(ChessMove("a1", "a2", "pawn"));
    moves.Add(ChessMove("b1", "b2", "pawn"));

    return moves;
}

String Chess::FEN()
{
    return "";
}

void Chess::MakeRandomMove()
{
    // chess gives us all the possible moves in an array
    // [ move1, move2, move3 ... ]
    Array<ChessMove> possibleMoves = GetMoves();

    // exit if the game is over
    if (gameOver == true) return;

    // chooses a random index in the list
    unsigned int randomIdx = possibleMoves.Size() - 1; // TODO: Make random

    // updates board state
    Move(possibleMoves[randomIdx]);

    // changes board visual state
    board->Position(FEN());
}


void Chess::Update()
{
#ifdef TILTFIVE
    if (input.Head.active)
    {
        //camera->position = glm::vec3(-9.683014 + (input.Head.x * 10), 16.498363 + (input.Head.y * 10), 7.318779 + (input.Head.z * 10));

        camera->roll  = 0 + input.Head.roll;
        camera->pitch = -41 + input.Head.pitch;
        camera->yaw   = 2 + input.Head.yaw;

        //fpsCamera->UpdateCamera();
        camera->forward.x = camera->roll;
        camera->forward.y = camera->yaw;
        camera->forward.z = camera->pitch;
        camera->forward = glm::normalize(camera->forward);

        camera->right = glm::normalize(glm::cross(camera->forward, camera->worldUp));
        camera->up = glm::normalize(glm::cross(camera->right, camera->forward));
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
