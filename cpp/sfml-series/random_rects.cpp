/**
 * Random shapes in SFML.
 *
 * Build: g++ -o random_rects random_rects.cpp -lsfml-graphics -lsfml-window -lsfml-system --std=c++11
 */

#include <random>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

class Random {
    public:
        int nextInt() {
            mt19937 rng(device());
            uniform_int_distribution<> uniform;
            return uniform(rng);
        }
        int nextInt(int min, int max) {
            mt19937 rng(device());
            uniform_int_distribution<> uniform(min, max);
            return uniform(rng);
        }
        float nextFloat() {
            mt19937 rng(device());
            uniform_real_distribution<> uniform;
            return uniform(rng);
        }
        float nextFloat(float min, float max) {
            mt19937 rng(device());
            uniform_real_distribution<> uniform(min, max);
            return uniform(rng);
        }
    private:
        random_device device;
};

sf::Color makeRandomColor() {
    Random random;
    return sf::Color(random.nextInt(0, 255), random.nextInt(0, 255), random.nextInt(0, 255));
}

sf::Vector2f makeRandomPosition(int minX=0, int maxX=WINDOW_WIDTH,
        int minY=0, int maxY=WINDOW_HEIGHT) {
    Random random;
    float x = static_cast<float>(random.nextInt(minX, maxX));
    float y = static_cast<float>(random.nextInt(minY, maxY));
    return sf::Vector2f(x, y);
}

sf::Vector2f makeRandomSize(int minX=0, int maxX=WINDOW_WIDTH,
        int minY=0, int maxY=WINDOW_HEIGHT) {
    Random random;
    float x = static_cast<float>(random.nextInt(minX, maxX));
    float y = static_cast<float>(random.nextInt(minY, maxY));
    return sf::Vector2f(x, y);
}

void randomizeShape(sf::RectangleShape& shape) {
    Random random;
    sf::Vector2f size = makeRandomSize(50, WINDOW_WIDTH, 50, WINDOW_HEIGHT);
    sf::Vector2f position = makeRandomPosition(0, WINDOW_WIDTH - size.x, 0, WINDOW_HEIGHT - size.y);

    shape.setSize(size);
    shape.setFillColor(makeRandomColor());
    shape.setPosition(position);
}

int main() { 
    Random random;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Random Rectangles");
    sf::Event event; 
    sf::RectangleShape rect;

    window.setVerticalSyncEnabled(true);
    
    bool running = true;
    while (running) { 
        while (window.pollEvent(event)) { 
            if (event.type == sf::Event::Closed) {
                running = false;
            }
        }

        randomizeShape(rect);

        window.draw(rect);
        window.display();
    }
    
    return 0;
}
