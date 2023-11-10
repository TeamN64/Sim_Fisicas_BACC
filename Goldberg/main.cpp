#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

constexpr float SCALE = 30.0f;

class Cube {
public:
    Cube(b2World &world, float x, float y, bool Dynamic, float h,float w,float ang, float density) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        if(Dynamic) {
            bodydef.type = b2_dynamicBody;
        }
        bodydef.angle = ang * b2_pi;
        OrgAngle = ang * b2_pi;
        body = world.CreateBody(&bodydef);
        origin = b2Vec2(x/SCALE, y/SCALE);
        b2PolygonShape shape;
        shape.SetAsBox((h/2) / SCALE, (w/2) / SCALE);

        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.density = density;
        body->CreateFixture(&fixturedef);

        box.setSize(sf::Vector2f(h, w));

        box.setOrigin(h/2, w/2);
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
        box.setFillColor(sf::Color::Blue);
    }

    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    void color(sf::Color color){
        box.setFillColor(color);
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
    b2Vec2 origin;
    float OrgAngle;
};

class Circle {
public:
    Circle(b2World &world, float x, float y, bool Dynamic, float h,float w,float r,float density) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        if(Dynamic){
            bodydef.type = b2_dynamicBody;
        }

        body = world.CreateBody( &bodydef);
        origin = b2Vec2(x/SCALE, y/SCALE);
        b2CircleShape circle;
        circle.m_p.Set((h/2)/SCALE, (w/2)/SCALE);
        circle.m_radius = r/SCALE;

        b2FixtureDef fixturedef;
        fixturedef.shape = &circle;
        fixturedef.density = density;
        body->CreateFixture(&fixturedef);

        cir.setRadius(r);
        cir.setFillColor(sf::Color::Red);
        cir.setOrigin(h/2, w/2);
    }

    void update() {
        cir.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        cir.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(cir);
    }

    void color(sf::Color color){
        cir.setFillColor(color);
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::CircleShape cir;
    b2Body *body;
    b2Vec2 origin;
};

int main(){
    sf::RenderWindow window(sf::VideoMode(700, 700), "Goldberg");
    b2Vec2 gravity(0.0f, 0.1f);
    b2World world(gravity);

    Circle circulo(world,100,100,true,10,10,10,1);
    Circle circulo2(world,420,75, true,10,10,10,1);

    Circle circulom1(world,610,310, true,30,30,30,1);
    Circle circuloancla1(world,610,510, false,30,30,30,0);
    Circle circulom2(world,560,350, true,30,30,30,1);
    Circle circuloancla2(world,560,510, false,30,30,30,0);
    Circle circulom3(world,505,365, true,30,30,30,1);
    Circle circuloancla3(world,495,510, false,30,30,30,0);

    Cube plataforma1(world,100,200, false,100,10,.25,1);//rampa de la bola chica
    Cube plataforma2(world,190,240, false,100,10,0,1);//plataforma de los rectangulos
    Cube plataforma3(world,450,240, false,50,10,0,1);//plataforma de la bola grande
    Cube plataforma4(world,520,255, false,100,10,.10,1);//rampa de la bola grande
    Cube plataforma5(world,650,255, false,10,100,0,1);//pared para detener la bola
    Cube plataforma6(world,350,475, false,300,10,0,1);//plataforma donde caera la bola
    Cube plataforma7(world,250,575, false,400,10,0,1);//plataforma donde volvera a caer la bola

    Cube poleap1(world,300,340, true,50,10,0,1);//plataforma de polea 1
    Cube poleap2(world,390,340, true,50,10,0,1);//plataforma de polea 2
    Cube poleap3(world,300,540, true,50,10,0,0);//plataforma de polea 1.1
    Cube poleap4(world,390,540, true,50,10,0,0);//plataforma de polea 2.1

    Cube rectangulo1(world,175,205, true,9,50,0,1);
    Cube rectangulo2(world,200,205, true,9,50,0,1);
    Cube rectangulo3(world,225,205, true,9,50,0,1);

    b2PulleyJointDef jointPulley;

    jointPulley.Initialize(poleap1.getBody(),poleap2.getBody(),poleap3.getBody()->GetWorldCenter(),poleap4.getBody()->GetWorldCenter(),poleap1.getBody()->GetWorldCenter(),poleap2.getBody()->GetWorldCenter(), 1);
    world.CreateJoint(&jointPulley);

    b2RevoluteJointDef revoluteJointDef1;
    revoluteJointDef1.Initialize(circulom1.getBody(), circuloancla1.getBody(), circulom1.getBody()->GetWorldCenter());
    revoluteJointDef1.lowerAngle = -0.25f * b2_pi;
    revoluteJointDef1.upperAngle = 0.25f * b2_pi;
    revoluteJointDef1.enableMotor = true;
    revoluteJointDef1.motorSpeed = 2.0f;
    revoluteJointDef1.maxMotorTorque = 1.0f;
    world.CreateJoint(&revoluteJointDef1);

    b2RevoluteJointDef revoluteJointDef2;
    revoluteJointDef2.Initialize(circulom2.getBody(), circuloancla2.getBody(), circulom2.getBody()->GetWorldCenter());
    revoluteJointDef2.lowerAngle = -0.25f * b2_pi;
    revoluteJointDef2.upperAngle = 0.25f * b2_pi;
    revoluteJointDef2.enableMotor = true;
    revoluteJointDef2.motorSpeed = 2.0f;
    revoluteJointDef2.maxMotorTorque = 1.0f;
    world.CreateJoint(&revoluteJointDef2);

    b2RevoluteJointDef revoluteJointDef3;
    revoluteJointDef3.Initialize(circulom3.getBody(), circuloancla3.getBody(), circulom3.getBody()->GetWorldCenter());
    revoluteJointDef3.lowerAngle = -0.25f * b2_pi;
    revoluteJointDef3.upperAngle = 0.25f * b2_pi;
    revoluteJointDef3.enableMotor = true;
    revoluteJointDef3.motorSpeed = 2.0f;
    revoluteJointDef3.maxMotorTorque = 1.0f;
    world.CreateJoint(&revoluteJointDef3);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                window.close();
                return 0;
            }
        }

        world.Step(1 / 60.f, 8, 3);

        circulo.update();
        circulo2.update();

        circulom1.update();
        circulom2.update();
        circulom3.update();

        circuloancla1.update();
        circuloancla2.update();
        circuloancla3.update();

        plataforma1.update();
        plataforma2.update();
        plataforma3.update();
        plataforma4.update();
        plataforma5.update();
        plataforma6.update();
        plataforma7.update();

        poleap1.update();
        poleap2.update();
        poleap3.update();
        poleap4.update();

        rectangulo1.update();
        rectangulo2.update();
        rectangulo3.update();

        window.clear();


        circulo.draw(window);
        circulo2.draw(window);

        circulom1.draw(window);
        circulom2.draw(window);
        circulom3.draw(window);

        circuloancla1.draw(window);
        circuloancla2.draw(window);
        circuloancla3.draw(window);

        plataforma1.draw(window);
        plataforma2.draw(window);
        plataforma3.draw(window);
        plataforma4.draw(window);
        plataforma5.draw(window);
        plataforma6.draw(window);
        plataforma7.draw(window);

        poleap1.draw(window);
        poleap2.draw(window);
        poleap3.draw(window);
        poleap4.draw(window);

        rectangulo1.draw(window);
        rectangulo2.draw(window);
        rectangulo3.draw(window);

        window.display();
    }

    return 0;
}