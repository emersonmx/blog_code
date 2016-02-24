#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

#include <SFML/Graphics.hpp>

class Random {
    public:
        int nextInt() {
            std::mt19937 rng(device());
            std::uniform_int_distribution<> uniform;
            return uniform(rng);
        }
        int nextInt(int min, int max) {
            std::mt19937 rng(device());
            std::uniform_int_distribution<> uniform(min, max);
            return uniform(rng);
        }
        float nextFloat() {
            std::mt19937 rng(device());
            std::uniform_real_distribution<> uniform;
            return uniform(rng);
        }
        float nextFloat(float min, float max) {
            std::mt19937 rng(device());
            std::uniform_real_distribution<> uniform(min, max);
            return uniform(rng);
        }
    private:
        std::random_device device;
};

sf::Color makeRandomColor() {
    Random random;
    return sf::Color(random.nextInt(0, 255), random.nextInt(0, 255), random.nextInt(0, 255));
}

sf::Vector2f makeRandomPosition(int minX, int maxX, int minY, int maxY) {
    Random random;
    float x = static_cast<float>(random.nextInt(minX, maxX));
    float y = static_cast<float>(random.nextInt(minY, maxY));
    return sf::Vector2f(x, y);
}

sf::Vector2f makeRandomSize(int minX, int maxX, int minY, int maxY) {
    Random random;
    float x = static_cast<float>(random.nextInt(minX, maxX));
    float y = static_cast<float>(random.nextInt(minY, maxY));
    return sf::Vector2f(x, y);
}
#endif /* RANDOM_HPP */
