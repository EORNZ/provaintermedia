#include <iostream>
#include "Date.h"

int main()
{
    Date a;
    Date aa(28,02,2023);
    Date a2(28,02,2023);
    Date a3(05,02,2003);

    aa=a3;

    std::cout << aa;
}

