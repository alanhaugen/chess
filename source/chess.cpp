#include "chess.h"

Chess::Chess()
{
}

Chess::~Chess()
{
    delete board;
    delete fpsCamera;
    delete camera;
}

void Chess::Init()
{
    camera    = new Camera(glm::vec3(-9.683014, 16.498363, 7.318779), glm::vec3(0.0, 1.0, 0.0), 2, -41, 0);
    fpsCamera = new FPSCamera(camera);
    board     = new Board();

    fpsCamera->UpdateCamera();

    components.Add(camera);
    //components.Add(fpsCamera);
    components.Add(board);

    dragging = false;
    activePiece = NULL;
}

void Chess::Update()
{
    if (input.Mouse.Released)
    {
        dragging = false;
        input.Mouse.Dragging = false;
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
                    dragging = true;
                    break;
                }
            }
        }
    }
}

void Chess::UpdateLate()
{

}
