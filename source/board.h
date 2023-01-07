#ifndef BOARD_H
#define BOARD_H

#include <core/components/actor.h>
#include <core/components/mesh.h>

class Board : public Actor
{
public:
    Board();
    ~Board();

    Actor *board;
    Actor *king;
    Actor *queen;
    Actor *pawn1;
    Actor *pawn2;
    Actor *pawn3;
    Actor *pawn4;
    Actor *pawn5;
    Actor *pawn6;
    Actor *pawn7;
    Actor *pawn8;
    Actor *bishop1;
    Actor *bishop2;
    Actor *knight1;
    Actor *knight2;
    Actor *rook1;
    Actor *rook2;
};

#endif // BOARD_H
