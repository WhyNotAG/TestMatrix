#include "Field.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h>


void Field::StartPlay()
{
	Array.resize(YSize);
    for (int i = 0; i < YSize; i++) {
	    Array[i].resize(XSize);
        for (int j = 0; j < XSize; j++) {
	        Array[i][j] = new Object({ i, j }, 0, false);
        }
    }
}

void Field::Check()
{
    for (int i = 0; i < YSize; i++) {
        for (int j = 0; j < XSize; j++) {
            int yCor = max(i, ActiveCoordinates.y) - min(i, ActiveCoordinates.y);
            int xCor = max(j, ActiveCoordinates.x) - min(j, ActiveCoordinates.x);
            int dist = max(yCor, xCor);
            Array[i][j]->SetDistance(dist);
        }
    }

}

void Field::SetCoordinates(Coordinates coordinates)
{
    ActiveCoordinates.x = abs(coordinates.x);
    ActiveCoordinates.y = abs(coordinates.y);

    if (ActiveCoordinates.x > XSize && ActiveCoordinates.x != 0) ActiveCoordinates.x = XSize - 1;
    else if (ActiveCoordinates.x > XSize) ActiveCoordinates.x = 0;

    if (ActiveCoordinates.y > YSize && ActiveCoordinates.y != 0) ActiveCoordinates.y = YSize - 1;
    else if (ActiveCoordinates.y > YSize) ActiveCoordinates.y = 0;
}

void Field::PrintField()
{
    

    for (int i = 0; i < YSize; i++) {

        int lineLength = 0;

        for (int j = 0; j < XSize; j++) {
            lineLength += std::to_string(Array[i][j]->GetDistance()).length() + 4;
            std::cout << std::setw(2) << Array[i][j]->GetDistance() << std::setw(3) << " | ";
        }

        std::cout << std::endl;
        for (int k = 0; k < lineLength; k++) {
            std::cout << "-" ;
        }

        std::cout << std::endl;
    }
}
