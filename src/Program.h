#ifndef PROGRAM_H
#define PROGRAM_H

#include <SFML/Graphics.hpp>
#include <iostream>

#define screenWidth 810
#define screenHeight 810

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

        sf::CircleShape circle;
        sf::Vertex line[2];

        unsigned int currentPoint;
        unsigned int jumpSize;

        sf::Clock clockk;
    float lastTime = 0;

        void initWindow(unsigned int antialiasingLevel);
        void initCircle(unsigned int points);
        void reset();

    public:
        Program(unsigned int points, unsigned int jump, unsigned int antialiasingLevel);

        void updateEvents();
        void update();
        void render();
        void run();
};

#endif
