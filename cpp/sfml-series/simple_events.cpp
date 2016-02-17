/**
 * Simple Events with SFML.
 *
 * Build: g++ -o simple_events simple_events.cpp -lsfml-window -lsfml-system -lGL
 */

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#define WINDOW_WIDTH 320
#define WINDOW_HEIGHT 240

using namespace std;

int main() {
    sf::Window window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Simple Events SFML");
    sf::Event event;

    bool running = true;
    while (running) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                cout << "Window close event fired!\n";
                running = false;
            } else if (event.type == sf::Event::Resized) {
                cout << "Window resized. New size (" << event.size.width << ", " << event.size.height << ")\n";
            } else if (event.type == sf::Event::LostFocus) {
                cout << "Window lost focus. Where is my glasses?\n";
            } else if (event.type == sf::Event::GainedFocus) {
                cout << "AHA! I found my glasses ^o^\n";
            } else if (event.type == sf::Event::TextEntered) {
                cout << "User typed " << static_cast<char>(event.text.unicode) << endl;
            } else if (event.type == sf::Event::KeyPressed) {
                cout << "Key pressed with code " << event.key.code << endl;
            } else if (event.type == sf::Event::KeyReleased) {
                cout << "Key released with code " << event.key.code << endl;
            } else if (event.type == sf::Event::MouseWheelScrolled) {
                cout << "Mouse scrolled.\n";
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    cout << "   type: vertical" << endl;
                } else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel) {
                    cout << "   type: horizontal" << endl;
                } else {
                    cout << "   type: unknown" << endl;
                }
                cout << "   Delta: " << event.mouseWheelScroll.delta << endl;
            } else if (event.type == sf::Event::MouseButtonPressed) {
                cout << "Mouse button pressed.\n";
                cout << "   Button: ";
                if (event.mouseButton.button == sf::Mouse::Right) {
                    cout << "Right";
                } else if (event.mouseButton.button == sf::Mouse::Left) {
                    cout << "Left";
                } else if (event.mouseButton.button == sf::Mouse::Middle) {
                    cout << "Middle";
                }
                cout << endl;
                cout << "   position (" << event.mouseButton.x << ", " << event.mouseButton.y << ")\n";
            } else if (event.type == sf::Event::MouseButtonReleased) {
                cout << "Mouse button released.\n";
                cout << "   Button: ";
                if (event.mouseButton.button == sf::Mouse::Right) {
                    cout << "Right";
                } else if (event.mouseButton.button == sf::Mouse::Left) {
                    cout << "Left";
                } else if (event.mouseButton.button == sf::Mouse::Middle) {
                    cout << "Middle";
                }
                cout << endl;
                cout << "   position (" << event.mouseButton.x << ", " << event.mouseButton.y << ")\n";
            } else if (event.type == sf::Event::MouseMoved) {
                cout << "Mouse moved\n";
                cout << "   position (" << event.mouseMove.x << ", " << event.mouseMove.y << ")\n";
            } else if (event.type == sf::Event::MouseEntered) {
                cout << "Mouse enter window\n";
            } else if (event.type == sf::Event::MouseLeft) {
                cout << "Mouse left window\n";
            }
        }
    }
    return 0;
}
