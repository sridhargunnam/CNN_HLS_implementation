// To read data from .dat format to an array in c++
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>

float data[1056][11];

float finalArray[96][11][11];

void print(float matrix[1056][11])
{
	int i, j;
	for (i = 0; i < 1056; ++i)
	{
		for (j = 0; j < 11; ++j)
			printf("%f ", matrix[i][j]);
		printf("\n");
	}
}

void printSmall(float matrix[11][11])
{
	int i, j;
	for (i = 0; i < 11; ++i)
	{
		for (j = 0; j < 11; ++j)
			printf("%f ", matrix[i][j]);
		printf("\n");
	}
}

void readToArray()
{
	std::ifstream file("D:\\venky\\workdir\\designs\\convolution\\data\\conv1kernels.dat");

	for (int row = 0; row < 1056; ++row)
	{
		std::string line;
		std::getline(file, line);
		if (!file.good())
			break;

		std::stringstream iss(line);

		for (int col = 0; col < 11; ++col)
		{
			std::string val;
			std::getline(iss, val, ',');
	
			std::stringstream convertor(val);
			convertor >> data[row][col];
		}
	}
}

void toFinal()
{
	for (int i = 0; i < 96; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			for (int k = 0; k < 11; k++)
			{
				finalArray[i][j][k] = data[i*11 + j][k];
			}
			
		}
		//std::cout << "\n\nsmaller array :: " << i<< "\n";
		//printSmall(finalArray[i]);
	}
}

int main()
{
	readToArray();
	
	//print(data);

	toFinal();

	//std::cout << finalArray[95][10][1];

	std::cin.ignore();

	return 0;
}