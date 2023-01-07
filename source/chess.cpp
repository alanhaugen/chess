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
    camera    = new Camera();
    fpsCamera = new FPSCamera(camera);
    board     = new Board();

    components.Add(camera);
    components.Add(fpsCamera);
    components.Add(board);
}

void Chess::Update()
{
    if (input.Mouse.Released)
    {
        for (unsigned int i = 0; i < board->components.Size(); i++)
        {
            IComponent *piece = board->components[i];
            //Log(piece->tag);

            if (piece->tag.Empty() == false) // board itself has tag ""
            {
                if (piece->tag == "king")
                {
                    piece->matrix.Translate(glm::vec3(0.0, 0.0, 0.5));
                }
            }
        }
    }
}

void Chess::UpdateLate()
{

}
