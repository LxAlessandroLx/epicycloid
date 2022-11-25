#include "Program.h"

using sf::Color;
using sf::Event;
using sf::VideoMode;
using sf::Vector2f;
using sf::Vector2u;

Program::Program(unsigned int points, unsigned int jump, unsigned int antialiasingLevel, unsigned int radius) 
    : screenWidth(radius*2 + 10), screenHeight(radius*2 + 10), currentPoint(0), jumpSize(jump)
{
    initWindow(antialiasingLevel);
    initCircle(points, radius);
    reset();

    line[0].color = (Color){0,255,0,150};
    line[1].color = (Color){0,255,0,150};
}

void Program::initWindow(unsigned int antialiasingLevel)
{
    settings.antialiasingLevel = antialiasingLevel;
    window.create(VideoMode(screenWidth, screenHeight), "Epicycloid", sf::Style::Close | sf::Style::Titlebar, settings);
}

void Program::initCircle(unsigned int points, unsigned int radius)
{
    circle.setRadius(radius);
    circle.setPointCount(points);
    circle.setFillColor((Color){0,0,0,0});
    circle.setOutlineThickness(1);
    circle.setOutlineColor((Color){0,255,0,150});
    circle.setPosition((sf::Vector2f){5,5});
}

void Program::reset()
{
    window.clear((Color){0,0,0,255});
    window.draw(circle);
    currentPoint = 0;

    system(CLEAR);
    std::cout << "Point count : " << circle.getPointCount() << "\n"
              << "Jump size : " << jumpSize << std::endl;
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
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::F:
                        if (window.getSize() != (Vector2u){VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height})
                        {   
                            window.create(sf::VideoMode::getDesktopMode(), "Epicycloid", sf::Style::Fullscreen, settings);
                            reset();
                        }
                        else
                        {
                            window.create(VideoMode(screenWidth, screenHeight), "Epicycloid", sf::Style::Close | sf::Style::Titlebar, settings);
                            reset();
                        }
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
        line[0].position = Vector2f(circle.getPoint(currentPoint)+(Vector2f){5,5});
        line[1].position = Vector2f(circle.getPoint(currentPoint*jumpSize % circle.getPointCount())+(Vector2f){5,5});
        window.draw(line, 2, sf::Lines);
        currentPoint++;
    }
    else if (currentPoint == circle.getPointCount())
    {
        render();
        currentPoint++;
    }
}

void Program::render()
{
    window.display();
}

void Program::run()
{
    while (window.isOpen())
    {
        update();
    }
}
