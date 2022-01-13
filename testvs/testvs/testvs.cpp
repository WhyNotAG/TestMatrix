// testvs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <array>
#include <iomanip>

#include "Object.h"
#include <Windows.h>

#include "Field.h"

int main()
{
    clock_t start = clock();

    auto field = Field();

    char isPlay = 'y';
    int x, y;

    while (isPlay == 'y')
    {
        system("cls");

        std::cout << "Enter size of matrix: ";
        std::cin >> x >> y;

        field.SetXSize(x);
        field.SetYSize(y);


        field.StartPlay();
        field.PrintField();

        std::cout << std::endl;

        std::cout << "Enter coordinate: ";
        std::cin >> x >> y;

        field.SetCoordinates({ x, y });

        system("cls");

        clock_t start = clock();

        field.Check();

        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;

        field.PrintField();
        printf("The time: %f seconds\n", seconds);
        std::cout << "Try again? (y/n) ";
        std::cin >> isPlay;
    }
    return 0;
}

