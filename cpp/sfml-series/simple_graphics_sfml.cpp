/**
 * Simple Graphics in SFML.
 *
 * Build: g++ -o simple_graphics_sfml simple_graphics_sfml.cpp -lsfml-graphics -lsfml-window -lsfml-system
 */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Simple Graphics SFML");
    sf::Event event;

    sf::VertexArray triangle(sf::Triangles, 3);
    triangle[0].color = sf::Color::Red;
    triangle[0].position = sf::Vector2f(WINDOW_WIDTH / 2, 0);
    triangle[1].color = sf::Color::Green;
    triangle[1].position = sf::Vector2f(0, WINDOW_HEIGHT);
    triangle[2].color = sf::Color::Blue;
    triangle[2].position = sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT);

    bool running = true;
    while (running) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }

        window.clear();

        window.draw(triangle);

        window.display();
    }

    return 0;
}
