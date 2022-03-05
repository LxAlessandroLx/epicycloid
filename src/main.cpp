#include "Program.h"
#include <sstream>

void help()
{
    std::cout << 
    "Usage: \n"
    " Epicycloid [points] [jump size] [antialiasing level]\n\n"
    "Arguments:\n"
    " - points              number of points of the circle (default = 300)\n"
    " - jump size           multiplication table to use (default = 2)\n"
    " - antialiasing level  level of antialiasing to use (default = 0)\n";
}

int main(int argc, char *argv[])
{
    unsigned int points = 300, jump = 2, antialiasingLevel = 0;

    if (argc >= 2)
    {
        std::istringstream stream(argv[1]);
        if (!(stream >> points) || !stream.eof())
        {
            std::cerr << "Invalid number: " << argv[1] << '\n';
            help();
            return EXIT_FAILURE;
        }

        if (argc >= 3)
        {
            std::istringstream stream(argv[2]);
            if (!(stream >> jump) || !stream.eof())
            {
                std::cerr << "Invalid number: " << argv[2] << '\n';
                help();
                return EXIT_FAILURE;
            } 

            if (argc >= 4)
            {
                std::istringstream stream(argv[3]);
                if (!(stream >> antialiasingLevel) || !stream.eof())
                {
                    std::cerr << "Invalid number: " << argv[3] << '\n';
                    help();
                    return EXIT_FAILURE;
                } 
            }
        }
    }

    Program program(points, jump, antialiasingLevel);

    program.run();

    return EXIT_SUCCESS;
}
