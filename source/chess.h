#ifndef CHESS_H
#define CHESS_H

#include <core/application.h>
#include <core/components/camera.h>
#include <core/components/fpscamera.h>
#include <core/components/fpscounter.h>
#include <core/components/background.h>
#include "board.h"

class Chess : public IScene
{
private:
    Camera *camera;
    FPSCamera *fpsCamera;
    FPSCounter *fps;
    Board *board;
    Background *bg;

    bool dragging;
    Actor *activePiece;

    float rotation;

public:
    Chess();
    ~Chess();

    void Init();
    void Update();
    void UpdateLate(); // UpdatePhysics
};

#endif // CHESS_H
