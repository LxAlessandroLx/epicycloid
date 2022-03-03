#ifndef PROGRAM_H
#define PROGRAM_H

#include <SFML/Graphics.hpp>
#include <iostream>

#define screenWidth 800
#define screenHeight 800

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

        void initWindow();
        void initCircle();
        void reset();

    public:
        Program();

        void updateEvents();
        void update();
        void render();
        void run();
};

#endif
