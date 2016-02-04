/**
 * Simple OpenGL with SFML.
 *
 * Build: g++ -o simple_opengl_sfml simple_opengl_sfml.cpp -lsfml-window -lsfml-system -lGL
 */

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

int main() {
    sf::Window window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Simple OpenGL SFML");
    sf::Event event;

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    bool running = true;
    while (running) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                running = false;
            } else if (event.type == sf::Event::Resized) {
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 1.0f, 0.0f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(-1.0f, -1.0f, 0.0f);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(1.0f, -1.0f, 0.0f);
        glEnd();

        window.display();
    }

    return 0;
}
