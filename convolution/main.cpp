#include <stdio.h>
#include <stdlib.h>
#include "conv.h"
// for random matrix generation
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
// To read data array from .mat
#include <fstream>
#include <sstream>
//
using namespace std;
void readToArray();
void writeData();
data_t image[227][227][3];
data_t data[33][1056]; // to read matlab kernel weights ; Conv1Kernel data from matlab
data_t Conv1Kernel[11][11][3][96];
data_t biasData1[1][1][1][96];
data_t conv1[55][55][96];
data_t relu1[55][55][96];
data_t pool1[27][27][96];
data_t lrn1[27][27][96];

// layer 2
data_t data2[33][2056]; // to read matlab kernel weights ; Conv2Kernel data from matlab
data_t Conv2Kernel[22][22][3][96];
data_t biasData2[2][2][2][96];
data_t conv2[55][55][96];
data_t relu2[55][55][96];
data_t pool2[27][27][96];
data_t lrn2[27][27][96];


int main()
{
	// Read data from .dat files generated in matlab to an array
	//cout << biasData1[0][0][0][0] << endl;
	readToArray();
	//cout << biasData1[0][0][0][0] << endl;
	for(int w=0; w<55; w++){
			for(int h=0; h<55; h++){
				for(int m=0; m<96; m++){
					//*( conv + m*(Wout*Hout) + h*Wout + w)=0;
					conv1[w][h][m]=0;
				}
			}
	}
	conv_layer1((data_t *)conv1, image, Conv1Kernel, (data_t *)biasData1, CONV1_KERNEL_1_LENGTH, CONV1_STRIDE);
//	conv_layer1((data_t *)conv1, (data_t *)image, (data_t *)Conv1Kernel, (data_t *)biasData1, CONV1_KERNEL_1_LENGTH, CONV1_STRIDE);

	//cout << biasData1[0][0][0][0] << endl;
    relu((data_t *)relu1, (data_t *)conv1, CONV1_FMAP_WIDTH, CONV1_FMAPS );
    max_pool((data_t *)pool1, (data_t *)relu1, CONV1_FMAP_WIDTH, CONV1_FMAPS,MAX_POOL_KERNEL_SIZE1, MAX_POOL_STRIDE1);
    lrn((data_t *)lrn1, (data_t *)pool1 , 5, .0001, 0.75, 1);
    writeData();
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
return 0;
}
//writeData
void writeData()
{
	float temp1;

    if( remove( "D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\Output.txt" ) != 0 )
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );

    std::ofstream output("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\Output.txt");
/*
    for (int m = 0; m < 96; m++)
        {
    	for (int h = 0; h < 55; h++)
    		{
    			for (int w = 0; w < 55; w++)
                {

    				output << *((data_t *)relu1 + m*(55*55) + h*55 + w)  << " ";  //  space after %f
    				//temp1=conv1[w][h][m];
    				//	temp1Addr = &conv1 + m*(55*55) + j*55 + i;
    				//temp=*(conv + m*(Wout*Hout) + h*Wout + w) ;
    				//	printf("conv at %d %d %d is %f \n",i,j,m,*(conv1 + m*(55*55) + j*55 + i) );
    	    	}
    			    output << "\n" ;
            }
    	}
    output.close();
*/

   //////////////////////////////
    for (int m = 0; m < 96; m++)
	{
	//    output << biasData1[0][0][0][m] << " ";
		for (int i = 0; i < 27; i++)
		{
			for (int j = 0; j < 27; j++)
            {
                //output << lrn1[j][i][m] << " "; //  space after %f   // matlab and c++ store array in different format. In matlab its coloumn wise, in c++ its row wise
				output << *((data_t *)lrn1 + m*(27*27) + i*27 + j)  << " ";
            }
            output << "\n" ;
		}
	}
    output.close();

}


/// read data
void readToArray()
{	// reading kernel weights
	std::ifstream file("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\conv1KernelWeights.dat");
	//std::ifstream file("/home/gunman/Downloads/summer17/alexnet/conv1KernelWeights.dat");
    int dim=3; // 3 dimensions, one for each RGB
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
			convertor >> data[row][col];
		}
	}
	file.close();
	// reading bias
	//std::ifstream file1("/home/gunman/Downloads/summer17/alexnet/git/CNN_HLS_implementation/convolution/data/conv1BiasV2.dat");
	std::ifstream file1("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\conv1BiasV2.dat");
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
//			std::cout << val1<<endl;
//			std::cout << strtof(val1.c_str(), NULL) << endl;
//			biasData1[1][1][1][col] = strtof(val1.c_str(), NULL);
			std::stringstream convertor1(val1);
			convertor1 >>biasData1[0][0][0][col];
//			std::cout  << biasData1[0][0][0][col] <<endl;
 //           printf("bias at %d = %f \n",row,biasData1[1][1][1][row]);
		}
	}
	file1.close();

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
				Conv1Kernel[i][j][dim][m] = data[i+(11*dim)][j+(11*m)];
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
std::ifstream file3("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\Image1.dat");
    int dim3=3; // 3 dimensions, one for each RGB
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
			convertor3 >> image[(row%227)][col][(row/227)];
//            printf("bias at %d %d %d = %f \n",row,col, row/3, image[row][col][int(row/3)]);
		}
//		if(row==228)
 //       {
 //           printf("bias at %d %d %d = %f \n",row,0, row/3, image[0][0][2]);
 //       }
    }
	file3.close();

}
