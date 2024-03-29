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
        unsigned int x, y;
    };

    struct Move
    {
        Pos startPos;
        Pos endPos;
    };

    String from;
    String to;

    String pieceType;

    String CreateAlgebreicNotation(Pos position, String type);
    String CreateAlgebreicNotation(Pos position, unsigned int type);
    Pos CreatePosition(String word);

public:
    ChessMove();
    ChessMove(String word);
    ChessMove(unsigned int type);
    ChessMove(unsigned int x, unsigned int y, unsigned int type);
    ChessMove(String from_, String to_, String type_);
    ChessMove(unsigned int startX, unsigned int startY, unsigned int x, unsigned int y, unsigned int type);

    String algebraicNotation;
    Move position;
    unsigned int type;
    bool capture;

    ChessMove &Move(unsigned int x, unsigned int y);

    void Execute();
    void Undo();
    void Redo();
};

#endif // CHESSMOVE_H
