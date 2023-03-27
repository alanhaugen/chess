#ifndef CHESSMOVE_H
#define CHESSMOVE_H

#include <core/components/command.h>
#include <core/x-platform/string.h>

class ChessMove : public Command
{
public:
    ChessMove();
    ChessMove(String to_, String type_);
    String algebraicNotation;

    void Execute();
    void Undo();
    void Redo();

private:
    bool capture;
    String to;

    String pieceType;
};

#endif // CHESSMOVE_H
