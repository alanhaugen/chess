#include "chessmove.h"

ChessMove::ChessMove()
{
    from = "";
    to = "";
    pieceType = "";
    capture = false;
}

ChessMove::ChessMove(String from_, String to_, String type_)
{
    from = from_;
    to = to_;
    pieceType = type_;
    capture = true;

    String capture_ = "";

    if (capture)
    {
        capture_ = "x";
    }

    algebraicNotation = pieceType + capture_ + to;
}

void ChessMove::Execute()
{

}

void ChessMove::Undo()
{

}

void ChessMove::Redo()
{

}
