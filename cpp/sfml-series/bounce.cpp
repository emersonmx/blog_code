/**
 * Simple Graphics in SFML.
 *
 * Build: g++ -o bounce bounce.cpp -lsfml-graphics -lsfml-window -lsfml-system
 */

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bounce");
    sf::Event event;

    sf::Texture faceTexture;
    if (!faceTexture.loadFromFile("assets/faceX.png")) {
        cout << "Couldn't load the image\n";
    }
    sf::Vector2u faceSize = faceTexture.getSize();
    sf::Vector2f faceVelocity(0.1, 0.1);

    sf::Sprite face(faceTexture);
    face.setPosition(WINDOW_WIDTH / 2 - faceSize.x / 2,
                     WINDOW_HEIGHT / 2 - faceSize.y / 2);

    bool running = true; 
    while (running) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }

        face.move(faceVelocity.x, faceVelocity.y);

        sf::Vector2f position = face.getPosition();
        if (position.x < 0 || position.x + faceSize.x > WINDOW_WIDTH) {
            faceVelocity.x *= -1;
        }
        if (position.y < 0 || position.y + faceSize.y > WINDOW_HEIGHT) {
            faceVelocity.y *= -1;
        }

        window.clear();
        window.draw(face);
        window.display();
    }
    return 0;
}
