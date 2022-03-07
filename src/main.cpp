#include "Program.h"
#include <sstream>

void help()
{
    std::cout << 
    "Usage: \n"
    " Epicycloid [points] [jump size] [antialiasing level] [radius]\n\n"
    "Arguments:\n"
    " - points              number of points of the circle (default = 300)\n"
    " - jump size           multiplication table to use (default = 2)\n"
    " - antialiasing level  level of antialiasing to use (default = 0)\n"
    " - radius              circle radius lenght in pixels\n";
}

void checkArgument(std::istringstream & stream, unsigned int & argument)
{
    if (!(stream >> argument) || !stream.eof())
    {
        std::cerr << "Invalid argument" << std::endl;
        help();
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    unsigned int points = 300, jump = 2, antialiasingLevel = 0, radius = 400;

    if (argc >= 2)
    {
        std::istringstream pointsStream(argv[1]);
        checkArgument(pointsStream, points);

        if (argc >= 3)
        {
            std::istringstream jumpStream(argv[2]);
            checkArgument(jumpStream, jump);

            if (argc >= 4)
            {
                std::istringstream antialiasingStream(argv[3]);
                checkArgument(antialiasingStream, antialiasingLevel);

                if (argc >= 5)
                {
                    std::istringstream radiusStream(argv[4]);
                    checkArgument(radiusStream, radius);
                }
            }
        }
    }

    Program program(points, jump, antialiasingLevel, radius);

    program.run();

    return EXIT_SUCCESS;
}
