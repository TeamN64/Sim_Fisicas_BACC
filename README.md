Para el siguiente proyecto se pide lo siguiente:
Diseñar una maquina de Rube Goldberg utilizando Box2D y SFML

Una máquina de Rube Goldberg es un aparato excesivamente sofisticado que realiza una tarea muy simple de una manera deliberadamente indirecta y elaborada

```
#include <box2d/box2d.h>  
#include <SFML/Graphics.hpp>  
  
const float M2P = 10.0f;  
const float P2M = 1.0f / M2P;  
  
class MCube {  
public:  
    MCube(b2World &world, float x, float y, float ancho, float alto, float aungulo, float densidad){  
        b2BodyDef bodydef;  
        bodydef.position.Set(x * P2M, y * P2M);  
        bodydef.angle = aungulo * b2_pi/180.0f;  
        bodydef.type = b2_dynamicBody;  
        body = world.CreateBody(&bodydef);  
  
        b2PolygonShape shape;  
        shape.SetAsBox(ancho/2, alto/2);  
  
        b2FixtureDef fixturedef;  
        fixturedef.shape = &shape;  
        fixturedef.density = densidad;  
        body->CreateFixture(&fixturedef);  
  
        box.setSize(sf::Vector2f(ancho * M2P, alto * M2P));  
        box.setFillColor(sf::Color::Red);  
        box.setOrigin(ancho * M2P/2, alto * M2P/2);  
    }  
  
    void update() {  
        box.setPosition(M2P * body->GetPosition().x, (900 - body->GetPosition().y * M2P));  
        box.setRotation(body->GetAngle()* -180/b2_pi);  
    }  
  
    void draw(sf::RenderWindow &win) const {  
        win.draw(box);  
    }  
  
    b2Body *getBody() {  
        return body;  
    }  
  
private:  
    sf::RectangleShape box;  
    b2Body *body;  
};  
  
class ECube {  
public:  
    ECube(b2World &world, float x, float y, float ancho, float alto, float angulo, float densidad){  
        b2BodyDef groundBodyDef;  
        groundBodyDef.position.Set(x * P2M, y * P2M);  
        groundBodyDef.angle = angulo * b2_pi/180.0f;  
  
        groundBody = world.CreateBody(&groundBodyDef);  
  
        b2PolygonShape groundBox;  
        groundBox.SetAsBox(ancho/2, alto/2);  
  
        groundBody->CreateFixture(&groundBox, densidad);  
  
        box.setSize(sf::Vector2f(ancho * M2P, alto * M2P));  
        box.setFillColor(sf::Color::Red);  
        box.setOrigin(ancho * M2P/2, alto * M2P/2);  
    }  
  
    void update() {  
        box.setPosition(M2P * groundBody->GetPosition().x, (900 - groundBody->GetPosition().y * M2P));  
        box.setRotation(groundBody->GetAngle() * -180/b2_pi);  
    }  
  
    void draw(sf::RenderWindow &win) const {  
        win.draw(box);  
    }  
  
    b2Body *getBody() {  
        return groundBody;  
    }  
  
private:  
    sf::RectangleShape box;  
    b2Body *groundBody;  
};  
  
class Circle {  
    Circle(b2World &world, float x, float y, float ancho, float alto, float densidad){  
        b2BodyDef bodydef;  
        bodydef.position.Set(x * P2M, y * P2M);  
        bodydef.type = b2_dynamicBody;  
        body = world.CreateBody(&bodydef);  
  
        b2PolygonShape shape;  
        shape.SetAsBox(ancho/2, alto/2);  
  
        b2FixtureDef fixturedef;  
        fixturedef.shape = &shape;  
        fixturedef.density = densidad;  
        body->CreateFixture(&fixturedef);  
  
        box.setSize(sf::Vector2f(ancho * M2P, alto * M2P));  
        box.setFillColor(sf::Color::Red);  
        box.setOrigin(ancho * M2P/2, alto * M2P/2);  
    }  
  
    void update() {  
        box.setPosition(M2P * body->GetPosition().x, (900 - body->GetPosition().y * M2P));  
        box.setRotation(body->GetAngle()* -180/b2_pi);  
    }  
  
    void draw(sf::RenderWindow &win) const {  
        win.draw(box);  
    }  
  
    b2Body *getBody() {  
        return body;  
    }  
  
private:  
    sf::RectangleShape box;  
    b2Body *body;  
};  
int main() {  
  
    sf::RenderWindow window(sf::VideoMode(700, 700), "Goldberg");  
    b2Vec2 gravity(0.0f, -0.1f);  
    b2World world(gravity);  
  
    ECube sBody1(world, 20.0f, 700.0f, 10.0f, 1.0f, -45.0f, 1.0f);  
    ECube sBody2(world, 120.0f, 660.0f, 15.0f, 1.0f, 0.0f, 1.0f);  
    ECube sBody3(world, 473.0f, 800.0f, 10.0f, 1.0f, 0.0f, 1.0f);  
    ECube sBody4(world, 580.0f, 775.0f, 15.0f, 1.0f, -20.0f, 1.0f);  
  
    MCube dBody1(world, 20.0f, 900.0f, 1.0f, 1.0f, 0.0f, 2.0f);  
    MCube dBody2(world, 135.0f, 745.0f, 0.5f, 5.0f, 0.0f, 1.0f);  
    MCube dBody3(world, 180.0f, 745.0f, 1.0f, 5.0f, 0.0f, 1.0f);  
    MCube dBody4(world, 424.0f, 830.0f, 1.0f, 6.0f, 0.0f, 0.5f);  
    MCube dBody5(world, 470.0f, 830.0f, 1.0f, 6.0f, 0.0f, 0.5f);  
    MCube dBody6(world, 674.0f, 469.0f, 1.0f, 4.0f, 0.0f, 1.0f);  
    //Circle bola1(world, 20.0f, 900.0f, 1.0f, 1.0f, 2.0f);  
    //Circle bola2(world, 424.0f, 830.0f, 1.0f, 1.0f, 0.5f);  
  
    MCube pulley1(world, 265.0f, 500.0f, 8.0f, 1.0f, 0.0f, 1.0f);  
    MCube pulley2(world, 380.0f, 400.0f, 8.0f, 1.0f, 0.0f, 1.0f);  
    ECube Anchor1(world, 265.0f, 900.0f, 1.0f, 1.0f, 0.0f, 0.0f);  
    ECube Anchor2(world, 380.0f, 900.0f, 1.0f, 1.0f, 0.0f, 0.0f);  
  
    b2PulleyJointDef pulleyJointDef;  
    pulleyJointDef.Initialize(pulley1.getBody(), pulley2.getBody(), Anchor1.getBody()->GetPosition(), Anchor2.getBody()->GetPosition(), pulley1.getBody()->GetWorldCenter(), pulley2.getBody()->GetWorldCenter(), 1.0f);  
  
    b2PulleyJoint *pulleyJoint;  
    pulleyJoint = (b2PulleyJoint*)world.CreateJoint(&pulleyJointDef);  
  
    MCube distancia1(world, 690.0f, 700.0f, 1.0f, 5.0f, 0.0f, 1.0f);  
    ECube distancia2(world, 690.0f, 640.0f, 1.0f, 1.0f, 0.0f, 1.0f);  
  
    b2DistanceJointDef distanceJointDef;  
    distanceJointDef.Initialize(distancia1.getBody(), distancia2.getBody(), distancia1.getBody()->GetWorldCenter(), distancia2.getBody()->GetWorldCenter());  
  
    b2DistanceJoint *distanceJoint;  
    distanceJoint = (b2DistanceJoint*)world.CreateJoint(&distanceJointDef);  
  
    while (window.isOpen()) {  
        sf::Event event{};  
        while (window.pollEvent(event)) {  
            if (event.type == sf::Event::Closed)  
                window.close();  
        }  
  
        sBody1.update();  
        sBody2.update();  
        sBody3.update();  
        sBody4.update();  
        dBody1.update();  
        dBody2.update();  
        dBody3.update();  
        dBody4.update();  
        dBody5.update();  
        pulley1.update();  
        pulley2.update();  
        distancia1.update();  
        distancia2.update();  
        world.Step(1.0f / 60.0f, 6, 2);  
  
        window.clear(sf::Color::Black);  
  
        sBody1.draw(window);  
        sBody2.draw(window);  
        sBody3.draw(window);  
        sBody4.draw(window);  
        dBody1.draw(window);  
        dBody2.draw(window);  
        dBody3.draw(window);  
        dBody4.draw(window);  
        dBody5.draw(window);  
        pulley1.draw(window);  
        pulley2.draw(window);  
        distancia1.draw(window);  
        distancia2.draw(window);  
  
        window.display();  
    }  
    return 0;  
}
```