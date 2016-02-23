/**
 * Primitives and shapes in SFML.
 *
 * Build: g++ -o primitives_shapes primitives_shapes.cpp -lsfml-graphics -lsfml-window -lsfml-system --std=c++11
 */

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Random.hpp"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

enum {
    RECTANGLE_TYPE,
    CIRCLE_TYPE,
    LINE_TYPE,
    POINT_TYPE,
    TYPE_SIZE
};

void randomizeCircleShape(sf::CircleShape& shape) {
    Random random;
    int radius = random.nextInt(5, WINDOW_HEIGHT / 2);
    sf::Vector2f position = makeRandomPosition(0, WINDOW_WIDTH - (radius * 2),
            0, WINDOW_HEIGHT - (radius * 2));

    shape.setRadius(radius);
    shape.setFillColor(makeRandomColor());
    shape.setPosition(position);
}

void randomizeRectangleShape(sf::RectangleShape& shape) {
    Random random;
    sf::Vector2f size = makeRandomSize(50, WINDOW_WIDTH, 50, WINDOW_HEIGHT);
    sf::Vector2f position = makeRandomPosition(0, WINDOW_WIDTH - size.x, 
            0, WINDOW_HEIGHT - size.y);

    shape.setSize(size);
    shape.setFillColor(makeRandomColor());
    shape.setPosition(position);
}

void randomizePoint(sf::Vertex& point) {
    Random random;

    point.position = makeRandomPosition(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    point.color = makeRandomColor();
}

void randomizeLine(sf::Vertex& a, sf::Vertex& b) { 
    Random random;

    a.position = makeRandomPosition(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    a.color = makeRandomColor();
    b.position = makeRandomPosition(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    b.color = makeRandomColor();
}

int main() { 
    Random random;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Primitives and Shapes");
    sf::Event event; 

    sf::RectangleShape rect;
    sf::CircleShape circle;
    sf::Vertex point;
    sf::Vertex line[2];

    int shapeType = 0;
    int direction = 1;
    bool clearScreen = false;
    int count = 0;

    window.setVerticalSyncEnabled(true);
    
    bool running = true;
    while (running) { 
        while (window.pollEvent(event)) { 
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }

        count++;
        if (count > 500) {
            shapeType += direction; 
            if (shapeType < 0) {
                shapeType = CIRCLE_TYPE;
                direction = 1;
            } else if (shapeType > TYPE_SIZE - 1) {
                shapeType = TYPE_SIZE - 2;
                direction = -1;
            }
            count = 0;
            clearScreen = true;
        }

        cout << count << endl;

        if (clearScreen) {
            window.clear();
            clearScreen = false;
        }

        switch (shapeType) {
            case RECTANGLE_TYPE:
                randomizeRectangleShape(rect);
                window.draw(rect);
                break;
            case CIRCLE_TYPE:
                randomizeCircleShape(circle);
                window.draw(circle);
                break;
            case LINE_TYPE:
                randomizeLine(line[0], line[1]);
                window.draw(line, 2, sf::PrimitiveType::Lines);
                break;
            case POINT_TYPE:
                randomizePoint(point);
                window.draw(&point, 1, sf::PrimitiveType::Points);
                break;
        }

        window.display();
    }
    
    return 0;
}
