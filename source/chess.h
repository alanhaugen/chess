#ifndef CHESS_H
#define CHESS_H

#include <core/application.h>
#include <core/components/mesh.h>
#include <core/components/camera.h>
#include <core/components/fpscamera.h>

class Chess : public IScene
{
public:
    Chess();
    ~Chess();
    Actor *king;
    Camera *camera;
    FPSCamera *fpsCamera;

    void Init();
    void Update();
    void UpdateLate();
};

#endif // CHESS_H
