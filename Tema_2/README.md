Para el siguiente ejercicio se pide lo siguiente:
Disparar en la luna una bala de cañon(densidad libre) a una velocidad de 900km/h a un angulo de 60 grados.
El cuerpo se encuentra a una altura diferente y ahora es de carburo de tungsteno.

```
#include <Box2D/Box2D.h>
#include <cmath>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    // Gravedad en la luna (1.625 m/s^2)
    b2Vec2 gravity(0.0f, -1.625f);

    b2World world(gravity);

    // Crea un cuerpo para la bala
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.2f, 0.05f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.001f; // Densidad muy baja (casi nula)
    fixtureDef.friction = 0.3f;

    // Agrega forma al cuerpo
    body->CreateFixture(&fixtureDef);

    // Establece la velocidad inicial de la bala (250 m/s a 60 grados)
    float angle = 60.0f; // Ángulo en grados
    float speed = 250.0f; // Velocidad en m/s
    float vx = speed * std::cos(angle * M_PI / 180.0f);
    float vy = speed * std::sin(angle * M_PI / 180.0f);

    body->SetLinearVelocity(b2Vec2(vx, vy));

    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int i = 0; i < 60; ++i) {
        world.Step(timeStep, velocityIterations, positionIterations);
        std::cout << body->GetPosition().x << " " << body->GetPosition().y << std::endl;
    }

    world.DestroyBody(body);

    return 0;
}

```
