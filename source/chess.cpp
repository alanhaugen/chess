#include "chess.h"

Chess::Chess()
{
}

Chess::~Chess()
{
    delete fpsCamera;
    delete camera;
    delete king;
    delete pawn;
    delete bishop;
    delete queen;
}

void Chess::Init()
{
    king = new Actor();
    king->Add(new Mesh("data/blender/king.blend"));

    camera = new Camera();
    fpsCamera = new FPSCamera(camera);

    components.Add(king);
    components.Add(camera);
    components.Add(fpsCamera);
}

void Chess::Update()
{

}

void Chess::UpdateLate()
{

}
