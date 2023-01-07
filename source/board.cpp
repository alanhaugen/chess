#include "board.h"
#include <core/application.h>

Board::Board()
{
    king = new Actor();
    king->Add(new Mesh("data/blender/king.blend"));
    king->matrix.Translate(glm::vec3(3 * 4, 0, 0));

    bishop1 = new Actor();
    bishop1->Add(new Mesh("data/blender/bishop.blend"));
    bishop1->matrix.Translate(glm::vec3(3 * 2, 0, 0));

    bishop2 = new Actor();
    bishop2->Add(new Mesh("data/blender/bishop.blend"));
    bishop2->matrix.Translate(glm::vec3(3 * 5, 0, 0));

    /*knight1 = new Actor();
    knight1->Add(new Mesh("data/blender/knight.blend"));
    knight1->matrix.Translate(glm::vec3(3 * 1, 0, 0));

    knight2 = new Actor();
    knight2->Add(new Mesh("data/blender/knight.blend"));
    knight2->matrix.Translate(glm::vec3(3 * 6, 0, 0));*/

    /*rook1 = new Actor();
    rook1->Add(new Mesh("data/blender/rook.blend"));
    rook1->matrix.Translate(glm::vec3(3 * 0, 0, 0));

    rook2 = new Actor();
    rook2->Add(new Mesh("data/blender/rook.blend"));
    rook2->matrix.Translate(glm::vec3(3 * 8, 0, 0));*/

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

    pawn1->matrix.Translate(glm::vec3(3 * 0, 0, -3));
    pawn2->matrix.Translate(glm::vec3(3 * 1, 0, -3));
    pawn3->matrix.Translate(glm::vec3(3 * 2, 0, -3));
    pawn4->matrix.Translate(glm::vec3(3 * 3, 0, -3));
    pawn5->matrix.Translate(glm::vec3(3 * 4, 0, -3));
    pawn6->matrix.Translate(glm::vec3(3 * 5, 0, -3));
    pawn7->matrix.Translate(glm::vec3(3 * 6, 0, -3));
    pawn8->matrix.Translate(glm::vec3(3 * 7, 0, -3));

    //queen = new Actor();
    //queen->Add(new Mesh("data/blender/queen.blend"));

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
    //scene->components.Add(knight1);
    //scene->components.Add(knight2);
    //scene->components.Add(rook1);
    //scene->components.Add(rook2);
    //scene->components.Add(queen);
}

Board::~Board()
{
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
