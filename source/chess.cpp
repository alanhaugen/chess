#include "chess.h"

Chess::Chess()
{
    king = new Actor();
    king->Add(new Mesh("data/blender/king.blend"));

    camera = new Camera();
    fpsCamera = new FPSCamera(camera);

    components.Add(king);
    components.Add(camera);
    components.Add(fpsCamera);
}

Chess::~Chess()
{
    delete fpsCamera;
    delete camera;
    delete king;
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
