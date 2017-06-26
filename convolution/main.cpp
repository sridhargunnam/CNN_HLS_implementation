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
data_t image[227][227][3];
data_t data[33][1056]; // to read matlab kernel weights ; Conv1Kernel data from matlab
data_t Conv1Kernel[11][11][3][96];
data_t biasData1[1][1][1][96];
data_t conv1[55][55][96];
data_t relu1[55][55][96];
data_t pool1[27][27][96];
data_t lrn1[27][27][96];
int main()
{
	// Read data from .dat files generated in matlab to an array
	// Image data is all ones now. In matlab I will give similar input image and get the results
	readToArray();
//	std::cout << "Length of array = " << (sizeof(image)/sizeof(*image)) << std::endl;
//  conv(a,b,&c);
	conv_layer1(conv1, image, Conv1Kernel, biasData1, CONV1_KERNEL_1_LENGTH, CONV1_STRIDE);
    //max_pool(pool1, conv1, MAX_POOL_WIN1, MAX_POOL_STRIDE1);
    relu(relu1, conv1, CONV1_FMAP_WIDTH, CONV1_FMAPS );
    max_pool(pool1, relu1, CONV1_FMAP_WIDTH, CONV1_FMAPS,MAX_POOL_KERNEL_SIZE1, MAX_POOL_STRIDE1);
    lrn(lrn1, pool1 , 5, .0001, 0.75, 1);
/*
	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 27; j++)
		{
			for (int k = 0; k < 96; k++)
                printf("element of O/P FM at = %d \n",lrn1[i][j][k]);
		}
	}
*/

    printf("********************END***********************");
	//FMap1=conv_layer1(image,convKernels1,Bias);
return 0;
}


/// read data
void readToArray()
{	// reading kernel weights
	std::ifstream file("D:\\venky\\workdir\\designs\\convolution\\data\\conv1KernelWeights.dat");
	//std::ifstream file("/home/gunman/Downloads/summer17/alexnet/conv1KernelWeights.dat");
	//git/CNN_HLS_implementation/convolution/data/conv1kernels.dat");
	//("D:\\venky\\workdir\\designs\\convolution\\data\\conv1kernels.dat");
    int dim=3; // 3 kerners, one for each RGB
	for (int row = 0; row < 11*dim; ++row)
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
			convertor >> data[row][col];//data[dim][row][col];
     //       printf("bias at %d %d = %f \n",row,col, data[row][col]);
		}
	}

	file.close();

	// reading bias
	//std::ifstream file1("/home/gunman/Downloads/summer17/alexnet/git/CNN_HLS_implementation/convolution/data/conv1Bias.dat");
	std::ifstream file1("D:\\venky\\workdir\\designs\\convolution\\data\\conv1BiasV2.dat");
	for (int row = 0; row < 1; ++row)
	{
		std::string line1;
		std::getline(file1, line1);
		if (!file1.good())
			break;
		std::stringstream iss1(line1);
		for (int col = 0; col < 96; ++col)
		{
			std::string val1;
			std::getline(iss1, val1, ',');
			std::stringstream convertor1(val1);
//			convertor1=10;
			convertor1 >> biasData1[1][1][1][row];//data[dim][row][col];
 //           printf("bias at %d = %f \n",row,biasData1[1][1][1][row]);
		}
	}
	file1.close();
/*	for(int row = 0; row < 96; ++row)
	{
	biasData1[1][1][1][row]=0;
	}
*/
// converting kernel weights to proper Array Format
// Restructures array to make to easily usable with indexing
// we need weights in array of size 11 X 11 X 3 X 96 from 33 X 1056 format
for(int m=0; m<96; m++){
	for (int dim = 0; dim < 3; dim++)
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				Conv1Kernel[i][j][dim][m] = data[i+(11*dim)][j+(11*m)];//[dim*i*11 + j][k];
//				printf("element of array at = %f \n",Conv1Kernel[i][j][dim][m]);
			}
		}
	}
//	printf("element of array at = %f \n",Conv1Kernel[0][0][2][m]);
	}
/*// making a dummy image all ones
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 227; i++)
		{
			for (int j = 0; j < 227; j++)
            {
                image[i][j][k]=1;
     //           printf("element of O/P FM at = %f \n",image[i][j][k]);
            }
		}
	}
*/
//////////////////////////////
//std::ifstream file("D:\\venky\\workdir\\designs\\convolution\\data\\conv1KernelWeights.dat");
std::ifstream file3("D:\\venky\\workdir\\designs\\convolution\\data\\Image.dat");
	//std::ifstream file("/home/gunman/Downloads/summer17/alexnet/conv1KernelWeights.dat");
	//git/CNN_HLS_implementation/convolution/data/conv1kernels.dat");
	//("D:\\venky\\workdir\\designs\\convolution\\data\\conv1kernels.dat");
    int dim3=3; // 3 kerners, one for each RGB
    for (int row = 0; row < 227*(dim3); ++row)
    {
		std::string line3;
		std::getline(file3, line3);
		if (!file3.good())
			break;
		std::stringstream iss3(line3);
		for (int col = 0; col < 227; ++col)
		{
			std::string val3;
			std::getline(iss3, val3, ',');
			std::stringstream convertor3(val3);
			convertor3 >> image[row][col][(row/227)];
//            printf("bias at %d %d %d = %f \n",row,col, row/3, image[row][col][int(row/3)]);
		}
    }
	file3.close();
}
