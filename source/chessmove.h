#ifndef CHESSMOVE_H
#define CHESSMOVE_H

#include <core/application.h>
#include <core/components/command.h>
#include <core/x-platform/string.h>

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

class ChessMove : public Command
{
private:
    struct Pos
    {
        int x, y;
    };

    struct Move
    {
        Pos startPos;
        Pos endPos;
    };

    bool capture;
    String from;
    String to;

    String pieceType;

    String CreateAlgebreicNotation(Pos position, String type);
    String CreateAlgebreicNotation(Pos position, int type);
    Pos CreatePosition(String word);

public:
    ChessMove();
    ChessMove(String word);
    ChessMove(int x, int y, int type);
    ChessMove(String from_, String to_, String type_);
    ChessMove(int startX, int startY, int x, int y, int type);

    String algebraicNotation;
    Move position;

    void Execute();
    void Undo();
    void Redo();
};

#endif // CHESSMOVE_H
