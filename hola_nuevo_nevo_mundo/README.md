La gravedad es un fenómeno natural por el cual los objetos y campos de materia dotados de masa o energía son atraídos entre sí, efecto mayormente observable en la interacción entre los planetas, galaxias y demás objetos del universo.

En física y química, la densidad es una magnitud escalar referida a la cantidad de masa en un determinado volumen de una sustancia o un objeto sólido.

La fuerza de fricción es la fuerza que existe entre dos superficies en contacto, que se opone al deslizamiento

 Cerca de la superficie de la Tierra, la aceleración gravitacional es de aproximadamente 9.81 m/s2, lo que significa que, ignorando los efectos de la resistencia del aire, la velocidad de un objeto que cae libremente aumentará en aproximadamente 9.81 metros por segundo cada segundo.


```

#include <iostream>
#include <Box2d/Box2d.h>

int main() {
    // Creacion del mundo y de su gravedad(9.81 siendo la gravedad de la tierra)
    b2Vec2 gravity(0.0f, -9.81f);
    b2World world(gravity);

    // Posicion del cuerpo
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Crecion del piso
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Creacion de la forma del cuerpo(50 unidaes de anco y 1 de alto)
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 1.0f);

	//Densidad del cuerpo
    groundBody ->CreateFixture(&groundBox, 0.0f);

	//Posicion del cuerpo
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 20.0f);

    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

	//Densidad y friccion
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    body ->CreateFixture(&fixtureDef);

    float timeStep = 1.0f/60.0f;

    int32 velocityIterations = 6;
    int32 positionIteration = 2;

    for (int32 i = 0; i <60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIteration);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
}
```
