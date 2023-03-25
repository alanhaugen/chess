#ifndef CHESS_H
#define CHESS_H

#include <core/application.h>
#include "core/components/cell.h"
#include <core/components/camera.h>
#include <core/components/fpscamera.h>
#include <core/components/fpscounter.h>
#include <core/components/background.h>
#include <core/components/pointlight.h>
#include "chessmove.h"
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

    enum
    {
        PAWN,
        BISHOP,
        KNIGHT,
        ROOK,
        QUEEN,
        KING,
        pawn, // NOTE: As according to FEN chess notation, lower-case => black pieces
        bishop,
        knight,
        rook,
        queen,
        king
    };

    Cell *chess;

    bool dragging;
    Actor *activePiece;
    ITime *timer;

    bool gameOver;
    bool isWhitesTurn;
    int moves;

    void Move(ChessMove);
    void MakeRandomMove();
    Array<ChessMove> GetMoves();
    String FEN();

public:
    Chess();
    ~Chess();

    void Init();
    void Update();
    void UpdateAfterPhysics(); // UpdatePhysics
};

#endif // CHESS_H
