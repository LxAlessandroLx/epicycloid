#ifndef PROGRAM_H
#define PROGRAM_H

#include <SFML/Graphics.hpp>
#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

class Program
{
    private:
        sf::ContextSettings settings;
        sf::RenderWindow window;
        sf::Event event;

        unsigned int screenWidth;
        unsigned int screenHeight;

        sf::CircleShape circle;
        sf::Vertex line[2];

        unsigned int currentPoint;
        unsigned int jumpSize;

        void initWindow(unsigned int antialiasingLevel);
        void initCircle(unsigned int points, unsigned int radius);
        void reset();

    public:
        Program(unsigned int points, unsigned int jump, unsigned int antialiasingLevel, unsigned int radius);

        void updateEvents();
        void update();
        void render();
        void run();
};

#endif
