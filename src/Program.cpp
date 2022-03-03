#include "Program.h"

using sf::Color;
using sf::Event;
using sf::VideoMode;
using sf::Vector2f;

Program::Program() : currentPoint(0), jumpSize(2)
{
    initWindow();
    initCircle();
    reset();

    line[0].color = (Color){0,255,0,150};
    line[1].color = (Color){0,255,0,150};
}

void Program::initWindow()
{
    settings.antialiasingLevel = 4;
    window.create(VideoMode(screenWidth, screenHeight), "Grafici fighi di cui non so il nome", sf::Style::Titlebar | sf::Style::Close, settings);
}

void Program::initCircle()
{
    circle.setRadius(400);
    circle.setPointCount(30);
    circle.setFillColor((Color){0,0,0,0});
    circle.setOutlineThickness(1);
    circle.setOutlineColor((Color){0,255,0,150});
}
void Program::reset()
{
    window.clear((Color){0,0,0,255});
    window.draw(circle);
    currentPoint = 0;

    // --------DEBUG-------
    std::cout << "Numero di punti : " << circle.getPointCount() << "\n"
              << "Tabellina : " << jumpSize << std::endl;
}

void Program::updateEvents()
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case Event::Closed: 
                window.close(); 
                break;
            case Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        circle.setPointCount(circle.getPointCount()+1);
                        reset();
                        break;
                    case sf::Keyboard::Down:
                        circle.setPointCount(circle.getPointCount()-1);
                        reset();
                        break;
                    case sf::Keyboard::Left:
                        jumpSize--;
                        reset();
                        break;
                    case sf::Keyboard::Right:
                        jumpSize++;
                        reset();
                        break;
                    default: break;
                }
            default: break;
        }
    }
}

void Program::update()
{
    updateEvents();

    if (currentPoint < circle.getPointCount())
    {
        line[0].position = Vector2f(circle.getPoint(currentPoint));
        line[1].position = Vector2f(circle.getPoint(currentPoint*jumpSize % circle.getPointCount()));
        window.draw(line, 2, sf::Lines);
        window.display();
        currentPoint++;
    }
}

void Program::render()
{
    
}

void Program::run()
{
    while (window.isOpen())
    {
        update();
        render();
    }
}
