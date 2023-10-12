#include <iostream>
#include <Box2D/Box2D.h>

int main() {
    b2PolygonShape polygonShape;

    // Triángulo
    b2Vec2 verticesTriangle[] = {
            b2Vec2(0.0f, 0.0f),
            b2Vec2(1.0f, 0.0f),
            b2Vec2(0.5f, 1.0f)
    };
    polygonShape.Set(verticesTriangle, 3);

    // Rectángulo
    b2Vec2 verticesRectangle[] = {
            b2Vec2(0.0f, 0.0f),
            b2Vec2(1.0f, 0.0f),
            b2Vec2(1.0f, 2.0f),
            b2Vec2(0.0f, 2.0f)
    };
    polygonShape.Set(verticesRectangle, 4);

    //Pentagono
    b2Vec2 verticesPentagon[] = {
            b2Vec2(0.0f, 1.0f),
            b2Vec2(0.5f, 0.0f),
            b2Vec2(1.5f, 0.0f),
            b2Vec2(2.0f, 1.0f),
            b2Vec2(1.0, 2.0f),
    };
    polygonShape.Set(verticesPentagon, 5);
    
    //Hexagono
    b2Vec2 verticesHexagon[] = {
            b2Vec2(0.0f, 1.0f),
            b2Vec2(0.5f, 0.0f),
            b2Vec2(1.5f, 0.0f),
            b2Vec2(2.0f, 1.0f),
            b2Vec2(1.5, 2.0f),
            b2Vec2(0.5, 2.0f)
    };
    polygonShape.Set(verticesHexagon, 6);

    //Octagono
    b2Vec2 verticesOctagon[] = {
            b2Vec2(0.0f, 2.0f),
            b2Vec2(0.5f, 1.0f),
            b2Vec2(1.0f, 0.0f),
            b2Vec2(1.5f, 1.0f),
            b2Vec2(2.0f, 2.0f),
            b2Vec2(1.5, 3.0f),
            b2Vec2(1.0, 4.0f),
            b2Vec2(0.5, 3.0f)
    };
    polygonShape.Set(verticesOctagon, 8);

    return 0;
}