#include "chess.h"

Chess::Chess()
    : fpsCamera(NULL)
{
    king = Mesh("data/blender/king.blend");
    camera = new Camera();
    fpsCamera = FPSCamera(camera);
}

Chess::~Chess()
{
    delete camera;
}

void Chess::Init()
{

}

void Chess::Update()
{

}

void Chess::UpdateLate()
{

}
