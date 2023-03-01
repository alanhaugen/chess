#ifndef CHESS_H
#define CHESS_H

#include <core/application.h>
#include <core/components/camera.h>
#include <core/components/fpscamera.h>
#include <core/components/fpscounter.h>
#include <core/components/background.h>
#include <core/components/pointlight.h>
#include "board.h"

class Chess : public IScene
{
private:
    Camera *camera;
    FPSCamera *fpsCamera;
    FPSCounter *fps;
    Board *board;
    Background *bg;
    PointLight *light;


    bool dragging;
    Actor *activePiece;

    float rotation;

public:
    Chess();
    ~Chess();

    void Init();
    void Update();
    void UpdateAfterPhysics(); // UpdatePhysics
};

#endif // CHESS_H
