#include "board.h"

Board::Board()
{
    Mesh *mesh = new Mesh("data/blender/board.blend");
    board = new Actor();
    board->Add(mesh);
    board->matrix.Translate(glm::vec3(.5, 0, -3));
    mesh->SetColorTint(glm::vec4(0.0, 1.0, 0.0, 1.0));

    mesh = new Mesh("data/blender/king.blend");
    king = new Actor();
    king->matrix.Translate(glm::vec3(3 * 4, 0, -3));
    king->Add(mesh);
    king->tag = "king";
    mesh->SetColorTint(glm::vec4(king->matrix.position.x, 1.0, 0.0, 1.0));

    mesh = new Mesh("data/blender/bishop.blend");
    bishop1 = new Actor();
    bishop1->matrix.Translate(glm::vec3(3 * 2, 0, -3));
    bishop1->Add(mesh);
    bishop1->tag = "bishop1";
    mesh->SetColorTint(glm::vec4(bishop1->matrix.position.x / 10, 1.0, 0.0, 1.0));

    mesh = new Mesh("data/blender/bishop.blend");
    bishop2 = new Actor();
    bishop2->Add(mesh);
    bishop2->matrix.Translate(glm::vec3(3 * 5, 0, -3));
    bishop2->tag = "bishop2";
    mesh->SetColorTint(glm::vec4(bishop2->matrix.position.x / 10, 1.0, 0.0, 1.0));

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





    pking = new Actor();
    pking->Add(new Mesh("data/blender/king.blend"));
    pking->matrix.Translate(glm::vec3(3 * 4, 0, 19));
    pking->tag = "king";

    pbishop1 = new Actor();
    pbishop1->Add(new Mesh("data/blender/bishop.blend"));
    pbishop1->matrix.Translate(glm::vec3(3 * 2, 0, 19));
    pbishop1->tag = "bishop1";

    pbishop2 = new Actor();
    pbishop2->Add(new Mesh("data/blender/bishop.blend"));
    pbishop2->matrix.Translate(glm::vec3(3 * 5, 0, 19));
    pbishop2->tag = "bishop2";

    pknight1 = new Actor();
    pknight1->Add(new Mesh("data/blender/knight.blend"));
    pknight1->matrix.Translate(glm::vec3(3 * 1, 0, 19));
    pknight1->tag = "knight1";

    pknight2 = new Actor();
    pknight2->Add(new Mesh("data/blender/knight.blend"));
    pknight2->matrix.Translate(glm::vec3(3 * 6, 0, 19));
    pknight2->tag = "knight2";

    prook1 = new Actor();
    prook1->Add(new Mesh("data/blender/rook.blend"));
    prook1->matrix.Translate(glm::vec3(3 * 0, 0, 19));
    prook1->tag = "rook1";

    prook2 = new Actor();
    prook2->Add(new Mesh("data/blender/rook.blend"));
    prook2->matrix.Translate(glm::vec3(3 * 7, 0, 19));
    prook2->tag = "rook2";

    ppawn1 = new Actor();
    ppawn2 = new Actor();
    ppawn3 = new Actor();
    ppawn4 = new Actor();
    ppawn5 = new Actor();
    ppawn6 = new Actor();
    ppawn7 = new Actor();
    ppawn8 = new Actor();

    ppawn1->Add(new Mesh("data/blender/pawn.blend"));
    ppawn2->Add(new Mesh("data/blender/pawn.blend"));
    ppawn3->Add(new Mesh("data/blender/pawn.blend"));
    ppawn4->Add(new Mesh("data/blender/pawn.blend"));
    ppawn5->Add(new Mesh("data/blender/pawn.blend"));
    ppawn6->Add(new Mesh("data/blender/pawn.blend"));
    ppawn7->Add(new Mesh("data/blender/pawn.blend"));
    ppawn8->Add(new Mesh("data/blender/pawn.blend"));

    ppawn1->matrix.Translate(glm::vec3(3 * 0, 0, 15));
    ppawn2->matrix.Translate(glm::vec3(3 * 1, 0, 15));
    ppawn3->matrix.Translate(glm::vec3(3 * 2, 0, 15));
    ppawn4->matrix.Translate(glm::vec3(3 * 3, 0, 15));
    ppawn5->matrix.Translate(glm::vec3(3 * 4, 0, 15));
    ppawn6->matrix.Translate(glm::vec3(3 * 5, 0, 15));
    ppawn7->matrix.Translate(glm::vec3(3 * 6, 0, 15));
    ppawn8->matrix.Translate(glm::vec3(3 * 7, 0, 15));

    ppawn1->tag = "pawn1";
    ppawn2->tag = "pawn2";
    ppawn3->tag = "pawn3";
    ppawn4->tag = "pawn4";
    ppawn5->tag = "pawn5";
    ppawn6->tag = "pawn6";
    ppawn7->tag = "pawn7";
    ppawn8->tag = "pawn8";

    pqueen = new Actor();
    pqueen->Add(new Mesh("data/blender/queen.blend"));
    pqueen->matrix.Translate(glm::vec3(3 * 3, 0, 19));
    pqueen->tag = "queen";

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
