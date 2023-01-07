#include "chess.h"

Chess::Chess()
{
}

Chess::~Chess()
{
    delete fpsCamera;
    delete camera;
    delete board;
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
    for (unsigned int i = 0; i < board->components.Size(); i++)
    {
        //Log(board->components[i]->tag);
    }
}

void Chess::UpdateLate()
{

}
