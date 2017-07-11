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
data_t lrn1Padded[31][31][96];
data_t lrn2Padded[15][15][256];

// layer 2
data_t Conv2Kernel[256][48][5][5];
//data_t biasData2[2][2][2][96];
data_t conv2[27][27][256];
data_t relu2[27][27][256];
data_t pool2[27][27][256];
data_t lrn2[13][13][256];
data_t Conv3Kernel[384][256][3][3];
data_t Conv4Kernel[384][192][3][3];
data_t Conv5Kernel[256][192][3][3];
data_t biasData2[1][1][1][256];
data_t biasData3[1][1][1][384];
data_t biasData4[1][1][1][384];
data_t biasData5[1][1][1][256];
data_t conv3[13][13][384];
data_t conv4[13][13][384];
data_t conv5[13][13][256];
data_t relu3[13][13][384];// 13, 13, 384
data_t relu3Padded[15][15][384];
data_t relu4[13][13][384];// 13, 13, 384
data_t relu4Padded[15][15][384];
data_t relu5[13][13][256];
data_t pool5[6][6][256];

// 	int sizeKer[5][4] = {conv1{11, 11, 3, 96}, conv2{5, 5, 48, 256},conv3{3,3,256,384},conv4{3,3,192,384}, conv5{3,3,192,256}} ;
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
///////////////////////////////////////////////////// stage 1 ////////////////////////////////////////////////////////////////////////////////////////////////
	//synthesize();
	conv_layer((data_t *)conv1, (data_t *)image, (data_t *)Conv1Kernel, (data_t *)biasData1, CONV1_KERNEL_1_LENGTH, CONV1_STRIDE, Win1,  Hin1,  N1,  M1,  Wout1,  Hout1,  group1);
    relu((data_t *)relu1, (data_t *)conv1, CONV1_FMAP_WIDTH, CONV1_FMAPS );
    max_pool((data_t *)pool1, (data_t *)relu1, CONV1_FMAP_WIDTH, CONV1_FMAPS,MAX_POOL_KERNEL_SIZE1, MAX_POOL_STRIDE1, poolInSize1, poolOutSize1);
    lrn((data_t *)lrn1, (data_t *)pool1 , 5, .0001, 0.75, 1, 27, 27, 96);
    /////////// padding lrn1 before conv2 operation
    int  Mps=96, Len=31, Wid=31; //lrn1 padded;
    int pad = 2;
    for (int m = 0; m < Mps; m++)
        {
    	for (int h = pad; h < Len-pad; h++)
    		{
    			for (int w = pad; w < Wid-pad; w++)
                {
    				 *((data_t *)lrn1Padded + m*(Len*Wid) + h*Wid + w) = *((data_t *)lrn1 + m*((Len-2*pad)*(Wid-2*pad)) + (h-pad)*(Wid-2*pad) + (w-pad));
    	    	}
            }
    	}
    //////////////////////////////////////////////////// stage 2 /////////////////////////////////////////////////////////////////////////////////////////////////
    conv_layer((data_t *)conv2, (data_t *)lrn1Padded, (data_t *)Conv2Kernel, (data_t *)biasData2, CONV2_KERNEL_2_LENGTH, CONV2_STRIDE, Win2,  Hin2,  N2,  M2,  Wout2,  Hout2,  group2);
	relu((data_t *)relu2, (data_t *)conv2, CONV2_FMAP_WIDTH, CONV2_FMAPS );
	max_pool((data_t *)pool2, (data_t *)relu2, CONV2_FMAP_WIDTH, CONV2_FMAPS,MAX_POOL_KERNEL_SIZE2, MAX_POOL_STRIDE2, poolInSize2, poolOutSize2);
	lrn((data_t *)lrn2, (data_t *)pool2 , 5, .0001, 0.75, 1, 13, 13, 256);
	///////////// padding lrn 3
	     Mps=256, Len=15, Wid=15;
		    for (int m = 0; m < Mps; m++)
		        {
		    	for (int h = 0; h < Len; h++)
		    		{
		    			for (int w = 0; w < Wid; w++)
		                {
		    				 *((data_t *)lrn2Padded + m*(Len*Wid) + h*Wid + w) = 0;
		    				//*((data_t *)lrn2Padded + m*(Len*Wid) + h*Wid + w) = m*(Len*Wid) + h*Wid + w;
		    	    	}
		            }
		    	}
	    pad = 1;
	    for (int m = 0; m < Mps; m++)
	        {
	    	for (int h = pad; h < Len-pad; h++)
	    		{
	    			for (int w = pad; w < Wid-pad; w++)
	                {
	    				 *((data_t *)lrn2Padded + m*(Len*Wid) + h*Wid + w) = *((data_t *)lrn2 + m*((Len-2*pad)*(Wid-2*pad)) + (h-pad)*(Wid-2*pad) + (w-pad));
	    				 //*((data_t *)lrn2Padded + m*(Len*Wid) + h*Wid + w) ;
	    	    	}
	            }
	    	}
////////////////////////////////////////////////////////stage 3 /////////////////////////////////////////////////////////////////////////////////////////////
	    conv_layer((data_t *)conv3, (data_t *)lrn2Padded, (data_t *)Conv3Kernel, (data_t *)biasData3, CONV3_KERNEL_3_LENGTH, CONV3_STRIDE, Win3,  Hin3,  N3,  M3,  Wout3,  Hout3,  group3); //3, 1, 15,  15,  256,  384,  13,  13,  1);
	    relu((data_t *)relu3, (data_t *)conv3, CONV3_FMAP_WIDTH, CONV3_FMAPS );
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	     Mps=384, Len=15, Wid=15;
		    for (int m = 0; m < Mps; m++)
		        {
		    	for (int h = 0; h < Len; h++)
		    		{
		    			for (int w = 0; w < Wid; w++)
		                {
		    				 *((data_t *)relu3Padded + m*(Len*Wid) + h*Wid + w) = 0;
		    				//*((data_t *)lrn2Padded + m*(Len*Wid) + h*Wid + w) = m*(Len*Wid) + h*Wid + w;
		    	    	}
		            }
		    	}
	    pad = 1;
	    for (int m = 0; m < Mps; m++)
	        {
	    	for (int h = pad; h < Len-pad; h++)
	    		{
	    			for (int w = pad; w < Wid-pad; w++)
	                {
	    				 *((data_t *)relu3Padded + m*(Len*Wid) + h*Wid + w) = *((data_t *)relu3 + m*((Len-2*pad)*(Wid-2*pad)) + (h-pad)*(Wid-2*pad) + (w-pad));
	    				 //*((data_t *)lrn2Padded + m*(Len*Wid) + h*Wid + w) ;
	    	    	}
	            }
	    	}
	   conv_layer((data_t *)conv4, (data_t *)relu3Padded, (data_t *)Conv4Kernel, (data_t *)biasData4, CONV4_KERNEL_4_LENGTH, CONV4_STRIDE, Win4,  Hin4,  N4,  M4,  Wout4,  Hout4,  group4);
		relu((data_t *)relu4, (data_t *)conv4, CONV4_FMAP_WIDTH, CONV4_FMAPS );
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	     Mps=384, Len=15, Wid=15;
		    for (int m = 0; m < Mps; m++)
		        {
		    	for (int h = 0; h < Len; h++)
		    		{
		    			for (int w = 0; w < Wid; w++)
		                {
		    				 *((data_t *)relu4Padded + m*(Len*Wid) + h*Wid + w) = 0;
		    	    	}
		            }
		    	}
	    pad = 1;
	    for (int m = 0; m < Mps; m++)
	        {
	    	for (int h = pad; h < Len-pad; h++)
	    		{
	    			for (int w = pad; w < Wid-pad; w++)
	                {
	    				 *((data_t *)relu4Padded + m*(Len*Wid) + h*Wid + w) = *((data_t *)relu4 + m*((Len-2*pad)*(Wid-2*pad)) + (h-pad)*(Wid-2*pad) + (w-pad));
	    	    	}
	            }
	    	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    conv_layer((data_t *)conv5, (data_t *)relu4Padded, (data_t *)Conv5Kernel, (data_t *)biasData5, CONV5_KERNEL_5_LENGTH, CONV5_STRIDE, Win5,  Hin5,  N5,  M5,  Wout5,  Hout5,  group5);
	relu((data_t *)relu5, (data_t *)conv5, CONV5_FMAP_WIDTH, CONV5_FMAPS );
	max_pool((data_t *)pool5, (data_t *)relu5, CONV5_FMAP_WIDTH, CONV5_FMAPS,MAX_POOL_KERNEL_SIZE5, MAX_POOL_STRIDE5, poolInSize5, poolOutSize5);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
//    int Mps=96, Len=55, Wid=55; // conv1
  //  int Mps=96, Len=27, Wid=27; //pool1
   //   int Mps=256, Len=27, Wid=27; // lrn1
//       int Mps=256, Len=27, Wid=27; //conv2; relu2
    //    int Mps=96, Len=31, Wid=31; //lrn1 padded;
   //  int Mps=256, Len=13, Wid=13; // norm2 lrn2, pool2,
   // int Mps=256, Len=13, Wid=13;  //  conv3
    // int Mps=256, Len=15, Wid=15; // lrn2 padded
     int Mps=256, Len=6, Wid=6;	// pool5

    for (int m = 0; m < Mps; m++)
        {
    	for (int h = 0; h < Len; h++)
    		{
    			for (int w = 0; w < Wid; w++)
                {
    				output <<  *((data_t *)pool5 + m*(Len*Wid) + h*Wid + w)  << " "; //  lrn2Padded[h][w][m]; //
    	    	}
    			    output << "\n" ;
            }
    	}
    output.close();
   //////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////

	int sizeKer[5][4] = {{11, 11, 3, 96}, {5, 5, 48, 256},{3,3,256,384},{3,3,192,384}, {3,3,192,256}} ;
	for(int ker=0; ker<=5 ; ker++)
	{
		    int ROW_MAX=sizeKer[ker][0];
		    int COL_MAX=sizeKer[ker][1];
		    int inpfmaps=sizeKer[ker][2];
		    int fmaps=sizeKer[ker][3];


		switch(ker+1){
		case 1:{
						std::cout << " ker=" << ker << "ROW_MAX= " << ROW_MAX << "COL_MAX =" << COL_MAX << "inpfmaps " << inpfmaps << "fmaps =" << fmaps << "\n" ;
						std::ifstream filek1("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv1Kernel.dat");
						for (int row = 0; row < (ROW_MAX*inpfmaps*fmaps) ; ++row)
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
								//convertork1 >> Conv1Kernel[0][0][row][col];
								convertork1 >> Conv1Kernel[(row/ROW_MAX)%fmaps][row/(fmaps*ROW_MAX)][row%(COL_MAX)][col] ;
								//convertork1 >> Conv1Kernel[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];
								//data_t Conv1Kernel[96][3][11][11]; //[11][11][3][96];   [row%(ROW_MAX)][col]

							}
						}
						filek1.close();
						break;
		}
		case 2:{

						std::ifstream filek2("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv2Kernel.dat");
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
								convertork2 >> Conv2Kernel[(row/ROW_MAX)%fmaps][row/(fmaps*ROW_MAX)][row%(COL_MAX)][col] ;//[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];

							}
						}
						filek2.close();
						break;
		}
		case 3: {
								std::ifstream filek3("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv3Kernel.dat");
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
								convertork3 >> Conv3Kernel[(row/ROW_MAX)%fmaps][row/(fmaps*ROW_MAX)][row%(COL_MAX)][col] ;//[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];
									//temp = Conv3Kernel[row%(ROW_MAX*inpfmaps*fmaps)][row%(ROW_MAX*inpfmaps)][row][col];
							}
						}
						filek3.close();
						break;
		}
		case 4:{
						std::ifstream filek4("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv4Kernel.dat");
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
								convertork4 >> Conv4Kernel[(row/ROW_MAX)%fmaps][row/(fmaps*ROW_MAX)][row%(COL_MAX)][col] ; ;//[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];
									//temp = Conv4Kernel[row%(ROW_MAX*inpfmaps*fmaps)][row%(ROW_MAX*inpfmaps)][row][col];
							}
						}
						filek4.close();
						break;
		}
		case 5:
		{
						std::ifstream filek5("D:\\sridhar\\workdir\\designs\\matlab-alexnet\\alexnet matlab - golden\\alexnet-forwardpath-master\\alexnet-forwardpath-master\\conv5Kernel.dat");
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
								convertork5 >> Conv5Kernel[(row/ROW_MAX)%fmaps][row/(fmaps*ROW_MAX)][row%(COL_MAX)][col] ; //[row/(ROW_MAX*COL_MAX*inpfmaps)][row/(ROW_MAX*COL_MAX)][row%(ROW_MAX)][col];
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
			std::stringstream convertor1(val1);
			convertor1 >>biasData1[0][0][0][col];
		}
	}
	file1.close();
	/////////////// bias 2
	std::ifstream file2xxx("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\conv2Bias.dat");
	for (int row = 0; row < 2; ++row)
	{
		std::string line2xxx;
		std::getline(file2xxx, line2xxx);
		if (!file2xxx.good())
			break;
		std::stringstream iss2xxx(line2xxx);
		for (int col = 0; col < 256; ++col)
		{
			std::string val2xxx;
			std::getline(iss2xxx, val2xxx, ',');
			std::stringstream convertor2xxx(val2xxx);
			convertor2xxx >>biasData2[0][0][0][col];
		}
	}
	file2xxx.close();
	////// bias3
	std::ifstream file3xxx("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\conv3Bias.dat");
	for (int row = 0; row < 3; ++row)
	{
		std::string line3xxx;
		std::getline(file3xxx, line3xxx);
		if (!file3xxx.good())
			break;
		std::stringstream iss3xxx(line3xxx);
		for (int col = 0; col < 356; ++col)
		{
			std::string val3xxx;
			std::getline(iss3xxx, val3xxx, ',');
			std::stringstream convertor3xxx(val3xxx);
			convertor3xxx >>biasData3[0][0][0][col];
		}
	}
	file3xxx.close();
	////// bias4
	std::ifstream file4xxx("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\conv4Bias.dat");
	for (int row = 0; row < 4; ++row)
	{
		std::string line4xxx;
		std::getline(file4xxx, line4xxx);
		if (!file4xxx.good())
			break;
		std::stringstream iss4xxx(line4xxx);
		for (int col = 0; col < 456; ++col)
		{
			std::string val4xxx;
			std::getline(iss4xxx, val4xxx, ',');
			std::stringstream convertor4xxx(val4xxx);
			convertor4xxx >>biasData4[0][0][0][col];
		}
	}
	file4xxx.close();
	////// bias5
	std::ifstream file5xxx("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\conv5Bias.dat");
	for (int row = 0; row < 5; ++row)
	{
		std::string line5xxx;
		std::getline(file5xxx, line5xxx);
		if (!file5xxx.good())
			break;
		std::stringstream iss5xxx(line5xxx);
		for (int col = 0; col < 556; ++col)
		{
			std::string val5xxx;
			std::getline(iss5xxx, val5xxx, ',');
			std::stringstream convertor5xxx(val5xxx);
			convertor5xxx >>biasData5[0][0][0][col];
		}
	}
	file5xxx.close();
	//////

// converting kernel weights to proper Array Format
// Restructures array to make to easily usable with indexing
// we need weights in array of size 11 X 11 X 3 X 96 from 33 X 1056 format

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
