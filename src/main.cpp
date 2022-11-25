#include "Program.h"

#include <sstream>
#include <string.h>

void help()
{
    std::cout << 
    "Usage: \n"
    " Epicycloid [options]\n\n"
    "Options:\n"
    " -p, --points              number of points of the circle (default = 300)\n"
    " -j, --jump-size           multiplication table to use (default = 2)\n"
    " -a, --antialiasing-level  level of antialiasing to use (default = 0)\n"
    " -r, --radius              circle radius lenght in pixels (default = 400)\n"
    " -h, --help                display this help\n";
}

void checkArgument(std::istringstream & stream, unsigned int & argument)
{
    if (!(stream >> argument) || !stream.eof())
    {
        std::cerr << "ERROR: Invalid argument" << std::endl;
        help();
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    unsigned int points = 300, jump = 2, antialiasingLevel = 0, radius = 400;

    for (int i = 1; i < argc; i += 2)
    {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
        {
            help();
            return EXIT_SUCCESS;
        }
        else if (argv[i+1])
        {
            std::istringstream stream(argv[i+1]);

            if (!strcmp(argv[i], "-p") || !strcmp(argv[i], "--points"))
            {
                checkArgument(stream, points);
            }
            else if (!strcmp(argv[i], "-j") || !strcmp(argv[i], "--jump-size"))
            {
                checkArgument(stream, jump);
            }
            else if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "--antialiasing-level"))
            {
                checkArgument(stream, antialiasingLevel);
            }
            else if (!strcmp(argv[i], "-r") || !strcmp(argv[i], "--radius"))
            {
                checkArgument(stream, radius);
            }
            else
            {
                std::cerr << "ERROR: '" << argv[i] << "' invalid argument\n";
                return EXIT_FAILURE;
            }
        }
        else
        {
            std::cerr << "ERROR: " << argv[i] << " requires an argument!\nUse --help for more information\n";
            return EXIT_FAILURE;
        }
    }

    Program program(points, jump, antialiasingLevel, radius);

    program.run();

    system(CLEAR);

    return EXIT_SUCCESS;
}
