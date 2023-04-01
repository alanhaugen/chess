#include "chessmove.h"

ChessMove::ChessMove()
{
    from = "";
    to = "";
    pieceType = "";
    capture = false;
    type = 0;
}

ChessMove::ChessMove(String word)
{
    position.startPos = CreatePosition(word);

    from = "";
    capture = false;
    pieceType = word[0];
    to = CreateAlgebreicNotation(position.startPos, pieceType);
    algebraicNotation = to;
}

ChessMove::ChessMove(unsigned int type)
{
    position.startPos.x = 0;
    position.startPos.y = 0;

    from = "";
    to = "";
    to = CreateAlgebreicNotation(position.startPos, type);
    pieceType = to[0];
    capture = false;
}

ChessMove::ChessMove(unsigned int x, unsigned int y, unsigned int type)
{
    position.startPos.x = x;
    position.startPos.y = y;

    from = "";
    capture = false;
    to = CreateAlgebreicNotation(position.startPos, type);
    pieceType = to[0];
    algebraicNotation = to;
}

ChessMove::ChessMove(unsigned int startX, unsigned int startY, unsigned int x, unsigned int y, unsigned int type)
{
    position.startPos.x = startX;
    position.startPos.y = startY;

    position.endPos.x = x;
    position.endPos.y = y;

    from = "";
    to = "";
    pieceType = "";
    capture = false;
}

ChessMove &ChessMove::Move(unsigned int x, unsigned int y)
{
    position.endPos.x = x;
    position.endPos.y = y;

    return *this;
}

ChessMove::ChessMove(String from_, String to_, String type_ = "")
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

String ChessMove::CreateAlgebreicNotation(Pos position, String type)
{
    String code;

    code.Append(type);

    switch(position.x)
    {
    case 0:
        code.Append("a");
        break;
    case 1:
        code.Append("b");
        break;
    case 2:
        code.Append("c");
        break;
    case 3:
        code.Append("d");
        break;
    case 4:
        code.Append("e");
        break;
    case 5:
        code.Append("f");
        break;
    case 6:
        code.Append("g");
        break;
    case 7:
        code.Append("h");
        break;
    default:
        LogWarning("Unknown horizontal position of chess piece detected");
    }

    switch(position.y)
    {
    case 0:
        code.Append("1");
        break;
    case 1:
        code.Append("2");
        break;
    case 2:
        code.Append("3");
        break;
    case 3:
        code.Append("4");
        break;
    case 4:
        code.Append("5");
        break;
    case 5:
        code.Append("6");
        break;
    case 6:
        code.Append("7");
        break;
    case 7:
        code.Append("8");
        break;
    default:
        LogWarning("Unknown vertical position of chess piece detected");
    }

    return code;
}

String ChessMove::CreateAlgebreicNotation(Pos position, unsigned int type_)
{
    String code;
    type = type_;

    switch(type)
    {
    case PAWN:
        code.Append("P");
        break;
    case QUEEN:
        code.Append("Q");
        break;
    case KING:
        code.Append("K");
        break;
    case BISHOP:
        code.Append("B");
        break;
    case ROOK:
        code.Append("R");
        break;
    case KNIGHT:
        code.Append("N");
        break;
    case pawn:
        code.Append("p");
        break;
    case queen:
        code.Append("q");
        break;
    case king:
        code.Append("k");
        break;
    case bishop:
        code.Append("b");
        break;
    case rook:
        code.Append("r");
        break;
    case knight:
        code.Append("n");
        break;
    default:
        LogWarning("Unknown chess piece detected");
    }

    return CreateAlgebreicNotation(position, code);
}

ChessMove::Pos ChessMove::CreatePosition(String word)
{
    unsigned int positionHorizontal = word[1];
    unsigned int positionVertical   = word[2];

    // Convert char to number
    positionVertical = positionVertical - '0';

    // Skip if dead
    int dead = word.IndexOf("x");
    if (dead != -1)
    {
        capture = true;
        positionVertical   = word[3];
    }

    switch(positionHorizontal)
    {
    case 'a':
        positionHorizontal = 1;
        break;
    case 'b':
        positionHorizontal = 2;
        break;
    case 'c':
        positionHorizontal = 3;
        break;
    case 'd':
        positionHorizontal = 4;
        break;
    case 'e':
        positionHorizontal = 5;
        break;
    case 'f':
        positionHorizontal = 6;
        break;
    case 'g':
        positionHorizontal = 7;
        break;
    case 'h':
        positionHorizontal = 8;
        break;
    default:
        LogWarning("Invalid horizontal position");
    }

    if (positionVertical < 1 || positionVertical > 8)
    {
        LogWarning("Invalid vertical position");
    }

    Pos position;

    position.x = positionHorizontal;
    position.y = positionVertical;

    return position;
}
