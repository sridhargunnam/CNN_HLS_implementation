#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <string>
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
data_t image[3][227][227];
data_t data[33][1056]; // to read matlab kernel weights ; Conv1Kernel data from matlab
data_t Conv1Kernel[96][3][11][11]; //[11][11][3][96];
data_t biasData1[1][1][1][96];
data_t conv1[55][55][96];
data_t relu1[55][55][96];
data_t pool1[27][27][96];
data_t lrn1[27][27][96];
// layer 2
data_t Conv2Kernel[256][48][5][5];
data_t biasData2[2][2][2][96];
data_t conv2[55][55][96];
data_t relu2[55][55][96];
data_t pool2[27][27][96];
data_t lrn2[27][27][96];
data_t Conv3Kernel[384][256][5][5];
data_t Conv4Kernel[384][192][5][5];
data_t Conv5Kernel[256][192][5][5];

int main()
{
	readToArray();
	for(int w=0; w<55; w++){
			for(int h=0; h<55; h++){
				for(int m=0; m<96; m++){
					conv1[w][h][m]=0;
				}
			}
	}
	///
	conv_layer((data_t *)conv1, (data_t *)image, (data_t *)Conv1Kernel, (data_t *)biasData1, CONV1_KERNEL_1_LENGTH, CONV1_STRIDE, Win1,  Hin1,  N1,  M1,  Wout1,  Hout1,  group1);
    relu((data_t *)relu1, (data_t *)conv1, CONV1_FMAP_WIDTH, CONV1_FMAPS );
    max_pool((data_t *)pool1, (data_t *)relu1, CONV1_FMAP_WIDTH, CONV1_FMAPS,MAX_POOL_KERNEL_SIZE1, MAX_POOL_STRIDE1);
    lrn((data_t *)lrn1, (data_t *)pool1 , 5, .0001, 0.75, 1);
    ///
	conv_layer((data_t *)conv2, (data_t *)lrn1, (data_t *)Conv2Kernel, (data_t *)biasData2, CONV2_KERNEL_2_LENGTH, CONV2_STRIDE, Win2,  Hin2,  N2,  M2,  Wout2,  Hout2,  group2);
	//relu((data_t *)relu2, (data_t *)conv2, CONV2_FMAP_WIDTH, CONV2_FMAPS );
	//max_pool((data_t *)pool2, (data_t *)relu2, CONV2_FMAP_WIDTH, CONV2_FMAPS,MAX_POOL_KERNEL_SIZE2, MAX_POOL_STRIDE2);
	//lrn((data_t *)lrn2, (data_t *)pool2 , 5, .0002, 0.75, 2);
	///
    writeData();
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
    int Mps=96, Len=55, Wid=55;
//    int Mps=256, Len=27, Wid=27;

    for (int m = 0; m < Mps; m++)
        {
    	for (int h = 0; h < Len; h++)
    		{
    			for (int w = 0; w < Wid; w++)
                {

    				output << *((data_t *)conv1 + m*(Len*Wid) + h*Wid + w)  << " ";
    	    	}
    			    output << "\n" ;
            }
    	}
    output.close();
   //////////////////////////////
/*
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
*/
}


std::string IntToString ( int number )
{
  std::ostringstream oss;

  // Works just like cout
  oss<< number;

  // Return the underlying string
  return oss.str();
}


/// read data
void readToArray()
{	// reading kernel weights

	//int sizeKer[5][4] = { {11 11 3 96}, { 5     5    48   256}, { 3     3   256   384}, {3     3   192   384}, {3     3   192   256}} ;
	std::ifstream file("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\conv1KernelWeights.dat");
	//std::ifstream file("/home/gunman/Downloads/summer17/alexnet/conv1KernelWeights.dat");
    int dim=3; // 3 dimensions, one for each RGB
   // int tempa;
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
			//tempa=data[row][col];
		}
	}
	file.close();

///////////////////////////////////////////////////////////////////////////////////////////////////////////

	int sizeKer[5][4] = {{11, 11, 3, 96}, {5, 5, 48, 256},{3,3,256,384},{3,3,192,384}, {3,3,192,256}} ;
	for(int ker=1; ker<=5 ; ker++)
	{
		    int ROW_MAX=sizeKer[ker][0];
		    int COL_MAX=sizeKer[ker][1];
		    int inpfmaps=sizeKer[ker][2];
		    int fmaps=sizeKer[ker][3];

		switch(ker){
		case 1:{

						std::ifstream filek1("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv1Kerne1Weights.dat");
						for (int row = 0; row < ROW_MAX*inpfmaps*fmaps; ++row)
						{
							std::string linek1;
							std::getline(filek1, linek1);
							if (!filek1.good())
								break;
							std::stringstream issk1(linek1);
							for (int col = 0; col < COL_MAX; ++col)
							{
								std::string valk1;
								std::getline(issk1, valk1, ',');
								std::stringstream convertork1(valk1);
							//	convertork1 >> Conv1Kernel[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];

							}
						}
						filek1.close();
						break;
		}
		case 2:{

						std::ifstream filek2("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv2Kerne2Weights.dat");
						for (int row = 0; row < ROW_MAX*inpfmaps*fmaps; ++row)
						{
							std::string linek2;
							std::getline(filek2, linek2);
							if (!filek2.good())
								break;
							std::stringstream issk2(linek2);
							for (int col = 0; col < COL_MAX; ++col)
							{
								std::string valk2;
								std::getline(issk2, valk2, ',');
								std::stringstream convertork2(valk2);
								convertork2 >> Conv2Kernel[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];

							}
						}
						filek2.close();
						break;
		}
		case 3: {
								std::ifstream filek3("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv3Kerne3Weights.dat");
						for (int row = 0; row < ROW_MAX*inpfmaps*fmaps; ++row)
						{
							std::string linek3;
							std::getline(filek3, linek3);
							if (!filek3.good())
								break;
							std::stringstream issk3(linek3);
							for (int col = 0; col < COL_MAX; ++col)
							{
								std::string valk3;
								std::getline(issk3, valk3, ',');
								std::stringstream convertork3(valk3);
								convertork3 >> Conv3Kernel[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];
									//temp = Conv3Kernel[row%(ROW_MAX*inpfmaps*fmaps)][row%(ROW_MAX*inpfmaps)][row][col];
							}
						}
						filek3.close();
						break;
		}
		case 4:{
						std::ifstream filek4("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv4Kerne4Weights.dat");
						for (int row = 0; row < ROW_MAX*inpfmaps*fmaps; ++row)
						{
							std::string linek4;
							std::getline(filek4, linek4);
							if (!filek4.good())
								break;
							std::stringstream issk4(linek4);
							for (int col = 0; col < COL_MAX; ++col)
							{
								std::string valk4;
								std::getline(issk4, valk4, ',');
								std::stringstream convertork4(valk4);
								convertork4 >> Conv4Kernel[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];
									//temp = Conv4Kernel[row%(ROW_MAX*inpfmaps*fmaps)][row%(ROW_MAX*inpfmaps)][row][col];
							}
						}
						filek4.close();
						break;
		}
		case 5:
		{
						std::ifstream filek5("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv5Kerne5Weights.dat");
						for (int row = 0; row < ROW_MAX*inpfmaps*fmaps; ++row)
						{
							std::string linek5;
							std::getline(filek5, linek5);
							if (!filek5.good())
								break;
							std::stringstream issk5(linek5);
							for (int col = 0; col < COL_MAX; ++col)
							{
								std::string valk5;
								std::getline(issk5, valk5, ',');
								std::stringstream convertork5(valk5);
								convertork5 >> Conv5Kernel[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];
									//temp = Conv5Kernel[row%(ROW_MAX*inpfmaps*fmaps)][row%(ROW_MAX*inpfmaps)][row][col];
							}
						}
						filek5.close();
						break;
		}
		default:
						break;

		}


	}


///////////////////////////////////////////////////////////////////////////////////////////////////////////
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
				Conv1Kernel[m][dim][i][j] = data[i+(11*dim)][j+(11*m)];
			//	printf("element of array at = %f \n",Conv1Kernel[i][j][dim][m]);
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
			convertor3 >> image[(row/227)][(row%227)][col];
//            printf("bias at %d %d %d = %f \n",row,col, row/3, image[row][col][int(row/3)]);
		}
//		if(row==228)
 //       {
 //           printf("bias at %d %d %d = %f \n",row,0, row/3, image[0][0][2]);
 //       }
    }
	file3.close();

}
