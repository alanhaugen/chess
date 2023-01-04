#ifndef CHESS_H
#define CHESS_H

#include <core/application.h>
#include <core/components/mesh.h>

class Chess : public IScene
{
public:
    Chess();
    Mesh king;

    void Init();
    void Update();
    void UpdateLate();
};

#endif // CHESS_H
