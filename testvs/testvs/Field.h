#pragma once
#include <vector>

#include "Object.h"

class Field
{
	public:
		Field() : XSize(1), YSize(1), ActiveCoordinates({1,1})
		{
			Array.resize(XSize);
		}

		Field(int xSize, int ySize, Coordinates coordinates) : XSize(abs(xSize)), YSize(abs(ySize)), ActiveCoordinates(coordinates)
		{
			Array.resize(XSize);
		}

		void StartPlay();
		void Check();

		int GetXSize() const { return XSize; }
		int GetYSize() const { return YSize; }
		Coordinates GetCoordinates() const { return ActiveCoordinates; }
		std::vector<std::vector<Object*>> GetArray() { return Array; }

		void SetXSize(int xSize) { XSize = abs(xSize); }
		void SetYSize(int ySize) { YSize = abs(ySize); }
		void SetCoordinates(Coordinates coordinates);
		void SetArray(std::vector<std::vector<Object*>> array) { Array = array; }

		void PrintField();

 	private:
		int XSize;
		int YSize;
		Coordinates ActiveCoordinates;
		std::vector<std::vector<Object*>> Array;
};

