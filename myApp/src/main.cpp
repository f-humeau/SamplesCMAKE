// Main examples
#include <iostream>

// include GLOBAL
#include "Globals.h"

// include local
#include "myClass.h"

int main()
{
    std::cout << "IMT main - v" << G_VERSION << std::endl;

    NH::myClass C1;
    std::cout << "Class C1 -" << C1.name() << std::endl;

    std::cout<< std::endl;
    return 0;
}