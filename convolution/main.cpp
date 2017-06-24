#include <stdio.h>
#include <stdlib.h>
#include "conv.h"
// for random matrix generation
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
// To read data array
#include <fstream>
#include <sstream>
//
using namespace std;
void readToArray();
data_t data[1056][11];
data_t biasData[1][1][1][96];
data_t Conv1Kernel[11][11][3][96];
data_t image[227][227][3];
int main()
{
	data_t a[11][11], b[11][11];
	data_t c, conv1[55][55][96];
	int i,j,k;
	// Read data from .dat files generated in matlab to an array
	// Image data is all ones now. In matlab I will give similar input image and get the results
	readToArray();

	//conv(a,b,&c);
//	conv1=conv_layer1(image);//,convKernels1,data_t biasData);
	conv_layer1(conv1, image, Conv1Kernel, biasData, 11, 4);

	printf("*******************************************");
	//FMap1=conv_layer1(image,convKernels1,Bias);
return 0;
}


/// read data
void readToArray()
{	// reading kernel weights
	std::ifstream file("D:\\venky\\workdir\\designs\\convolution\\data\\conv1kernels.dat");
	for (int dim = 0; dim < 3; ++dim)
	{
	for (int row = 0; row < 11; ++row)
	{
		std::string line;
		std::getline(file, line);
		if (!file.good())
			break;
		std::stringstream iss(line);
		for (int col = 0; col < 1056; ++col)
		{
			std::string val;
			std::getline(iss, val, ',');

			std::stringstream convertor(val);
			convertor >> data[dim][row][col];
		}
	}
	}
	// reading bias
	std::ifstream file("D:\\venky\\workdir\\designs\\convolution\\data\\conv1Bias.dat");
	for (int row = 0; row < 96; ++row)
	{
		std::string line;
		std::getline(file, line);
		if (!file.good())
			break;
		std::stringstream iss(line);
		iss >> biasData[1][1][1][row];
	}
// converting kernel weights to proper Array Format
// Restructures array to make to easily usable with indexing
	for (int i = 0; i < 96; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			for (int k = 0; k < 11; k++)
			{
				Conv1Kernel[i][j][k] = data[i*11 + j][k];
			}
		}
	}
// making a dummy image all ones
	for (int i = 0; i < 227; i++)
	{
		for (int j = 0; j < 227; j++)
		{
			for (int k = 0; k < 3; k++)
			image[i][j][k]=1;
		}
	}
}
