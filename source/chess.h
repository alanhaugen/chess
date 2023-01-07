#ifndef CHESS_H
#define CHESS_H

#include <core/application.h>
#include <core/components/camera.h>
#include <core/components/fpscamera.h>
#include "board.h"

class Chess : public IScene
{
private:
    Camera *camera;
    FPSCamera *fpsCamera;
    Board *board;

public:
    Chess();
    ~Chess();

    void Init();
    void Update();
    void UpdateLate(); // UpdatePhysics
};

#endif // CHESS_H
