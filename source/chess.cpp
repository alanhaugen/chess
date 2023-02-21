#include "chess.h"

#ifdef TILTFIVE
#include "tilt5/TiltFiveNative.h"
#endif

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
    fps       = new FPSCounter();
    board     = new Board();

    fpsCamera->UpdateCamera();

    components.Add(camera);
    //components.Add(fpsCamera);
    components.Add(fps);
    components.Add(board);

    dragging = false;
    activePiece = NULL;

    rotation = 0.0f;
}

void Chess::Update()
{
#ifdef TILTFIVE
    if (input.Head.active)
    {
        //camera->position = glm::vec3(-9.683014 + (input.Head.x * 10), 16.498363 + (input.Head.y * 10), 7.318779 + (input.Head.z * 10));

        rotation += 0.5f;

        //camera->pitch = -41.0f + (input.Head.pitch * 5);
        //camera->yaw = rotation;//input.Head.yaw;
        //camera->roll = rotation;//input.Head.roll;

        //fpsCamera->UpdateCamera();
        //camera->forward.x = 2.0f + input.Head.pitch;//cos(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
        //camera->forward.y = -41.0f + input.Head.yaw; //sin(glm::radians(camera->pitch));
        camera->forward.x = input.Head.roll; //sin(glm::radians(camera->yaw)) * cos(glm::radians(camera->pitch));
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

void Chess::UpdateLate()
{

}
