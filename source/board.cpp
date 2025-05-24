#include "board.h"
#include "chessmove.h"

Board::Board()
{
    board = new Actor();
    board->Add(new Mesh("data/blender/board.blend",
                        "data/simple.vert",
                        "data/simple.frag"));
    board->matrix.Translate(glm::vec3(.5, 0, -3));

    String vert = "data/phong.vert";
    String frag = "data/phong.frag";

    king = new Actor();
    king->matrix.Translate(glm::vec3(3 * 4, 0, -3));
    king->Add(new Mesh("data/blender/king.blend", vert, frag));
    king->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));

    bishop1 = new Actor();
    bishop1->matrix.Translate(glm::vec3(3 * 2, 0, -3));
    bishop1->Add(new Mesh("data/blender/bishop.blend", vert, frag));
    bishop1->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));

    bishop2 = new Actor();
    bishop2->Add(new Mesh("data/blender/bishop.blend", vert, frag));
    bishop2->matrix.Translate(glm::vec3(3 * 5, 0, -3));
    bishop2->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));

    knight1 = new Actor();
    knight1->Add(new Mesh("data/blender/knight.blend", vert, frag));
    knight1->matrix.Translate(glm::vec3(3 * 1, 0, -3));
    knight1->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));

    knight2 = new Actor();
    knight2->Add(new Mesh("data/blender/knight.blend", vert, frag));
    knight2->matrix.Translate(glm::vec3(3 * 6, 0, -3));
    knight2->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));

    rook1 = new Actor();
    rook1->Add(new Mesh("data/blender/rook.blend", vert, frag));
    rook1->matrix.Translate(glm::vec3(3 * 0, 0, -3));
    rook1->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));

    rook2 = new Actor();
    rook2->Add(new Mesh("data/blender/rook.blend", vert, frag));
    rook2->matrix.Translate(glm::vec3(3 * 7, 0, -3));
    rook2->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));

    pawn1 = new Actor();
    pawn2 = new Actor();
    pawn3 = new Actor();
    pawn4 = new Actor();
    pawn5 = new Actor();
    pawn6 = new Actor();
    pawn7 = new Actor();
    pawn8 = new Actor();

    pawn1->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    pawn1->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));
    pawn2->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    pawn2->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));
    pawn3->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    pawn3->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));
    pawn4->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    pawn4->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));
    pawn5->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    pawn5->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));
    pawn6->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    pawn6->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));
    pawn7->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    pawn7->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));
    pawn8->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    pawn8->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));

    pawn1->matrix.Translate(glm::vec3(3 * 0, 0, 0));
    pawn2->matrix.Translate(glm::vec3(3 * 1, 0, 0));
    pawn3->matrix.Translate(glm::vec3(3 * 2, 0, 0));
    pawn4->matrix.Translate(glm::vec3(3 * 3, 0, 0));
    pawn5->matrix.Translate(glm::vec3(3 * 4, 0, 0));
    pawn6->matrix.Translate(glm::vec3(3 * 5, 0, 0));
    pawn7->matrix.Translate(glm::vec3(3 * 6, 0, 0));
    pawn8->matrix.Translate(glm::vec3(3 * 7, 0, 0));

    queen = new Actor();
    queen->Add(new Mesh("data/blender/queen.blend", vert, frag));
    queen->matrix.Translate(glm::vec3(3 * 3, 0, -3));
    queen->Uniform("colour", glm::vec4(0.4, 0.7, 0.4, 1.0));

    components.Add(board);
    components.Add(king);
    components.Add(pawn1);
    components.Add(pawn2);
    components.Add(pawn3);
    components.Add(pawn4);
    components.Add(pawn5);
    components.Add(pawn6);
    components.Add(pawn7);
    components.Add(pawn8);
    components.Add(bishop1);
    components.Add(bishop2);
    components.Add(knight1);
    components.Add(knight2);
    components.Add(rook1);
    components.Add(rook2);
    components.Add(queen);





    pking = new Actor();
    pking->Add(new Mesh("data/blender/king.blend", vert, frag));
    pking->matrix.Translate(glm::vec3(3 * 4, 0, 19));
    pking->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));

    pbishop1 = new Actor();
    pbishop1->Add(new Mesh("data/blender/bishop.blend", vert, frag));
    pbishop1->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    pbishop1->matrix.Translate(glm::vec3(3 * 2, 0, 19));

    pbishop2 = new Actor();
    pbishop2->Add(new Mesh("data/blender/bishop.blend", vert, frag));
    pbishop2->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    pbishop2->matrix.Translate(glm::vec3(3 * 5, 0, 19));

    pknight1 = new Actor();
    pknight1->Add(new Mesh("data/blender/knight.blend", vert, frag));
    pknight1->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    pknight1->matrix.Translate(glm::vec3(3 * 1, 0, 19));

    pknight2 = new Actor();
    pknight2->Add(new Mesh("data/blender/knight.blend", vert, frag));
    pknight2->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    pknight2->matrix.Translate(glm::vec3(3 * 6, 0, 19));

    prook1 = new Actor();
    prook1->Add(new Mesh("data/blender/rook.blend", vert, frag));
    prook1->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    prook1->matrix.Translate(glm::vec3(3 * 0, 0, 19));

    prook2 = new Actor();
    prook2->Add(new Mesh("data/blender/rook.blend", vert, frag));
    prook2->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    prook2->matrix.Translate(glm::vec3(3 * 7, 0, 19));

    ppawn1 = new Actor();
    ppawn2 = new Actor();
    ppawn3 = new Actor();
    ppawn4 = new Actor();
    ppawn5 = new Actor();
    ppawn6 = new Actor();
    ppawn7 = new Actor();
    ppawn8 = new Actor();

    ppawn1->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    ppawn1->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    ppawn2->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    ppawn2->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    ppawn3->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    ppawn3->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    ppawn4->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    ppawn4->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    ppawn5->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    ppawn5->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    ppawn6->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    ppawn6->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    ppawn7->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    ppawn7->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    ppawn8->Add(new Mesh("data/blender/pawn.blend", vert, frag));
    ppawn8->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));

    ppawn1->matrix.Translate(glm::vec3(3 * 0, 0, 15));
    ppawn2->matrix.Translate(glm::vec3(3 * 1, 0, 15));
    ppawn3->matrix.Translate(glm::vec3(3 * 2, 0, 15));
    ppawn4->matrix.Translate(glm::vec3(3 * 3, 0, 15));
    ppawn5->matrix.Translate(glm::vec3(3 * 4, 0, 15));
    ppawn6->matrix.Translate(glm::vec3(3 * 5, 0, 15));
    ppawn7->matrix.Translate(glm::vec3(3 * 6, 0, 15));
    ppawn8->matrix.Translate(glm::vec3(3 * 7, 0, 15));

    pqueen = new Actor();
    pqueen->Add(new Mesh("data/blender/queen.blend", vert, frag));
    pqueen->Uniform("colour", glm::vec4(.3, .3, .3, 1.0));
    pqueen->matrix.Translate(glm::vec3(3 * 3, 0, 19));

    components.Add(pking);
    components.Add(ppawn1);
    components.Add(ppawn2);
    components.Add(ppawn3);
    components.Add(ppawn4);
    components.Add(ppawn5);
    components.Add(ppawn6);
    components.Add(ppawn7);
    components.Add(ppawn8);
    components.Add(pbishop1);
    components.Add(pbishop2);
    components.Add(pknight1);
    components.Add(pknight2);
    components.Add(prook1);
    components.Add(prook2);
    components.Add(pqueen);

    UpdateTags();
}

Board::~Board()
{
}

void MovePiece(Actor *piece, String word)
{
    ChessMove move(word);

    float xpos, ypos;

    xpos = (int(move.position.startPos.x) - 1) * 3;
    ypos = (int(move.position.startPos.y) * 3) - 6;

    // Put piece in position based on fen
    piece->matrix.matrix[3] = glm::vec4(xpos, 0.0f, ypos, 1.0f);

    // Disable piece
    piece->tag = "";
}

void Board::UpdateTags()
{
    pqueen->tag = "queen";
    ppawn1->tag = "pawn1";
    ppawn2->tag = "pawn2";
    ppawn3->tag = "pawn3";
    ppawn4->tag = "pawn4";
    ppawn5->tag = "pawn5";
    ppawn6->tag = "pawn6";
    ppawn7->tag = "pawn7";
    ppawn8->tag = "pawn8";
    prook2->tag = "rook2";
    prook1->tag = "rook1";
    pknight2->tag = "knight2";
    pknight1->tag = "knight1";
    pbishop2->tag = "bishop2";
    pbishop1->tag = "bishop1";
    pking->tag = "king";
    queen->tag = "QUEEN";
    rook2->tag = "ROOK2";
    rook1->tag = "ROOK1";
    knight2->tag = "KNIGHT2";
    knight1->tag = "KNIGHT1";
    bishop2->tag = "BISHOP2";
    bishop1->tag = "BISHOP1";
    king->tag = "KING";
    pawn1->tag = "PAWN1";
    pawn2->tag = "PAWN2";
    pawn3->tag = "PAWN3";
    pawn4->tag = "PAWN4";
    pawn5->tag = "PAWN5";
    pawn6->tag = "PAWN6";
    pawn7->tag = "PAWN7";
    pawn8->tag = "PAWN8";
}

void Board::Position(String fen)
{
    Array<String> words = fen.ToWords();

    for (unsigned int j = 0; j < components.Size(); j++)
    {
        Actor *piece = dynamic_cast<Actor*>(*components[j]);

        if (piece->tag.Empty() == false)
        {
            piece->matrix.matrix[3] = glm::vec4(-100.0f, 0.0f, -100.0f, 1.0f); // hack to remove defeated pieces
        }
    }

    // Search fen for piece position and state information
    for (unsigned int i = 0; i < words.Size(); i++)
    {
        String word = words[i];

        int type = word.At(0);

        bool success = false;

        for (unsigned int j = 0; j < components.Size() && success == false; j++)
        {
            Actor *piece = dynamic_cast<Actor*>(*components[j]);

            switch (type)
            {
            case 'K':
                if (piece->tag.IndexOf("KING") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'Q':
                if (piece->tag.IndexOf("QUEEN") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'R':
                if (piece->tag.IndexOf("ROOK") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'P':
                if (piece->tag.IndexOf("PAWN") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'N':
                if (piece->tag.IndexOf("KNIGHT") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'B':
                if (piece->tag.IndexOf("BISHOP") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'k':
                if (piece->tag.IndexOf("king") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'b':
                if (piece->tag.IndexOf("bishop") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'p':
                if (piece->tag.IndexOf("pawn") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'r':
                if (piece->tag.IndexOf("rook") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'n':
                if (piece->tag.IndexOf("knight") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            case 'q':
                if (piece->tag.IndexOf("queen") != -1)
                {
                    MovePiece(piece, word);
                    success = true;
                }
                break;
            //default:
            //    LogWarning("Piece code unknown");
            }
        }
    }

    UpdateTags();
}
