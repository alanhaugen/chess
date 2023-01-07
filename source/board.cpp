#include "board.h"

Board::Board()
{
    board = new Actor();
    board->Add(new Mesh("data/blender/board.blend"));
    board->matrix.Translate(glm::vec3(.5, 0, -3));

    king = new Actor();
    king->Add(new Mesh("data/blender/king.blend"));
    king->matrix.Translate(glm::vec3(3 * 4, 0, -3));
    king->tag = "king";

    bishop1 = new Actor();
    bishop1->Add(new Mesh("data/blender/bishop.blend"));
    bishop1->matrix.Translate(glm::vec3(3 * 2, 0, -3));
    bishop1->tag = "bishop1";

    bishop2 = new Actor();
    bishop2->Add(new Mesh("data/blender/bishop.blend"));
    bishop2->matrix.Translate(glm::vec3(3 * 5, 0, -3));
    bishop2->tag = "bishop2";

    knight1 = new Actor();
    knight1->Add(new Mesh("data/blender/knight.blend"));
    knight1->matrix.Translate(glm::vec3(3 * 1, 0, -3));
    knight1->tag = "knight1";

    knight2 = new Actor();
    knight2->Add(new Mesh("data/blender/knight.blend"));
    knight2->matrix.Translate(glm::vec3(3 * 6, 0, -3));
    knight2->tag = "knight2";

    rook1 = new Actor();
    rook1->Add(new Mesh("data/blender/rook.blend"));
    rook1->matrix.Translate(glm::vec3(3 * 0, 0, -3));
    rook1->tag = "rook1";

    rook2 = new Actor();
    rook2->Add(new Mesh("data/blender/rook.blend"));
    rook2->matrix.Translate(glm::vec3(3 * 7, 0, -3));
    rook2->tag = "rook2";

    pawn1 = new Actor();
    pawn2 = new Actor();
    pawn3 = new Actor();
    pawn4 = new Actor();
    pawn5 = new Actor();
    pawn6 = new Actor();
    pawn7 = new Actor();
    pawn8 = new Actor();

    pawn1->Add(new Mesh("data/blender/pawn.blend"));
    pawn2->Add(new Mesh("data/blender/pawn.blend"));
    pawn3->Add(new Mesh("data/blender/pawn.blend"));
    pawn4->Add(new Mesh("data/blender/pawn.blend"));
    pawn5->Add(new Mesh("data/blender/pawn.blend"));
    pawn6->Add(new Mesh("data/blender/pawn.blend"));
    pawn7->Add(new Mesh("data/blender/pawn.blend"));
    pawn8->Add(new Mesh("data/blender/pawn.blend"));

    pawn1->matrix.Translate(glm::vec3(3 * 0, 0, 0));
    pawn2->matrix.Translate(glm::vec3(3 * 1, 0, 0));
    pawn3->matrix.Translate(glm::vec3(3 * 2, 0, 0));
    pawn4->matrix.Translate(glm::vec3(3 * 3, 0, 0));
    pawn5->matrix.Translate(glm::vec3(3 * 4, 0, 0));
    pawn6->matrix.Translate(glm::vec3(3 * 5, 0, 0));
    pawn7->matrix.Translate(glm::vec3(3 * 6, 0, 0));
    pawn8->matrix.Translate(glm::vec3(3 * 7, 0, 0));

    pawn1->tag = "pawn1";
    pawn2->tag = "pawn2";
    pawn3->tag = "pawn3";
    pawn4->tag = "pawn4";
    pawn5->tag = "pawn5";
    pawn6->tag = "pawn6";
    pawn7->tag = "pawn7";
    pawn8->tag = "pawn8";

    queen = new Actor();
    queen->Add(new Mesh("data/blender/queen.blend"));
    queen->matrix.Translate(glm::vec3(3 * 3, 0, -3));
    queen->tag = "queen";

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
}

Board::~Board()
{
    delete board;
    delete king;
    delete pawn1;
    delete pawn2;
    delete pawn3;
    delete pawn4;
    delete pawn5;
    delete pawn6;
    delete pawn7;
    delete pawn8;
    delete bishop1;
    delete bishop2;
    delete knight1;
    delete knight2;
    delete rook1;
    delete rook2;
    delete queen;
}
