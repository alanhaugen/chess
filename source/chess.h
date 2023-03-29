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
    Array<ChessMove> GetKingMoves(int x, int y, int type);
    Array<ChessMove> GetPawnMoves(int x, int y, int type);
    Array<ChessMove> GetKnightMoves(int x, int y, int type);
    Array<ChessMove> GetQueenMoves(int x, int y, int type);
    Array<ChessMove> GetBishopMoves(int x, int y, int type);
    Array<ChessMove> GetRookMoves(int x, int y, int type);
    String FEN();

public:
    Chess();
    ~Chess();

    void Init();
    void Update();
    void UpdateAfterPhysics(); // UpdatePhysics
};

#endif // CHESS_H
