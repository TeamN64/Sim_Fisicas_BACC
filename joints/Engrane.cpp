#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

const float SCALE = 30.0f;

int main() {
    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    b2BodyDef gear1BodyDef, gear2BodyDef;
    gear1BodyDef.type = b2_dynamicBody;
    gear2BodyDef.type = b2_dynamicBody;
    gear1BodyDef.position.Set(200.0f / SCALE, 300.0f / SCALE);
    gear2BodyDef.position.Set(500.0f / SCALE, 300.0f / SCALE);

    b2Body* gear1Body = world.CreateBody(&gear1BodyDef);
    b2Body* gear2Body = world.CreateBody(&gear2BodyDef);

    b2CircleShape gear1Shape, gear2Shape;
    gear1Shape.m_radius = 60.0f / SCALE;
    gear2Shape.m_radius = 90.0f / SCALE;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &gear1Shape;
    gear1Body->CreateFixture(&fixtureDef);
    fixtureDef.shape = &gear2Shape;
    gear2Body->CreateFixture(&fixtureDef);

    b2RevoluteJointDef jointDef;
    jointDef.bodyA = gear1Body;
    jointDef.bodyB = gear2Body;
    jointDef.localAnchorA.Set(60.0f / SCALE, 0);
    jointDef.localAnchorB.Set(-90.0f / SCALE, 0);
    jointDef.collideConnected = false;

    b2RevoluteJoint* joint = (b2RevoluteJoint*)world.CreateJoint(&jointDef);

    gear1Body->SetAngularVelocity(1.0f);

    sf::RenderWindow window(sf::VideoMode(800, 600), "articulación de engranaje");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        world.Step(1.0f / 60.0f, 8, 3);

        window.clear();

        sf::CircleShape gear1ShapeDrawable(60.0f);
        gear1ShapeDrawable.setFillColor(sf::Color::Red);
        gear1ShapeDrawable.setOrigin(60.0f, 60.0f);
        gear1ShapeDrawable.setPosition(gear1Body->GetPosition().x * SCALE, gear1Body->GetPosition().y * SCALE);
        gear1ShapeDrawable.setRotation(gear1Body->GetAngle() * 180 / b2_pi);
        window.draw(gear1ShapeDrawable);

        sf::CircleShape gear2ShapeDrawable(90.0f);
        gear2ShapeDrawable.setFillColor(sf::Color::Blue);
        gear2ShapeDrawable.setOrigin(90.0f, 90.0f);
        gear2ShapeDrawable.setPosition(gear2Body->GetPosition().x * SCALE, gear2Body->GetPosition().y * SCALE);
        gear2ShapeDrawable.setRotation(gear2Body->GetAngle() * 180 / b2_pi);
        window.draw(gear2ShapeDrawable);

        window.display();
    }
    return 0;
}
