#ifndef CHESS_H
#define CHESS_H

#include <core/application.h>
#include <core/components/grid.h>
#include <core/components/text.h>
#include <core/components/sprite.h>
#include <core/components/camera.h>
#include <core/components/fpscamera.h>
#include <core/components/fpscounter.h>
#include <core/components/background.h>
#include <core/components/pointlight.h>
#include "chessmove.h"
#include "board.h"

#include <fstream>

class Chess : public IScene
{
private:
    Camera *camera;
    Sprite *pointer;
    Text *text;
    FPSCamera *fpsCamera;
    FPSCounter *fps;
    Board *board;
    Background *bg;
    PointLight *light;

    Grid *chess;

    bool dragging;
    Actor *activePiece;
    ITime *timer;

    bool check;
    bool gameOver;
    bool isWhitesTurn;
    int moveQuantity;

    bool playing;
    Array<String> fens;
    int fenPosition;

    void Move(ChessMove);
    void MakeRandomMove();
    bool MakeCapture();
    Array<ChessMove> GetMoves();
    String FEN();

    bool CheckMove(ChessMove &move);

    Array<ChessMove> GetKingMoves(unsigned int x, unsigned int y, unsigned int type);
    Array<ChessMove> GetPawnMoves(unsigned int x, unsigned int y, unsigned int type);
    Array<ChessMove> GetKnightMoves(unsigned int x, unsigned int y, unsigned int type);
    Array<ChessMove> GetQueenMoves(unsigned int x, unsigned int y, unsigned int type);
    Array<ChessMove> GetBishopMoves(unsigned int x, unsigned int y, unsigned int type);
    Array<ChessMove> GetRookMoves(unsigned int x, unsigned int y, unsigned int type);

public:
    Chess();
    ~Chess();

    void Init();
    void Update();
    void UpdateAfterPhysics(); // UpdatePhysics
};

#endif // CHESS_H
