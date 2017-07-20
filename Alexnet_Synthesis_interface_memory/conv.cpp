//Sub-routines for convolution, relu, max pooling, lrn layers
#include "conv.h"
#include <stdio.h>
#include <iostream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
// To read data array from .mat
#include <fstream>
#include <sstream>
using namespace std;
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

void synthesize()
{
	conv_layer((data_t *)conv1, (data_t *)image, (data_t *)Conv1Kernel, (data_t *)biasData1, CONV1_KERNEL_1_LENGTH, CONV1_STRIDE, Win1,  Hin1,  N1,  M1,  Wout1,  Hout1,  group1);
 //   relu((data_t *)relu1, (data_t *)conv1, CONV1_FMAP_WIDTH, CONV1_FMAPS );
 //  max_pool((data_t *)pool1, (data_t *)relu1, CONV1_FMAP_WIDTH, CONV1_FMAPS,MAX_POOL_KERNEL_SIZE1, MAX_POOL_STRIDE1, poolInSize1, poolOutSize1);
  // lrn((data_t *)lrn1, (data_t *)pool1 , 5, .0001, 0.75, 1, 27, 27, 96);
}

// Convolves weights and N input feature maps for the given point in output Feature map
//  generate M output feature maps

void conv_layer(data_t *conv, data_t *image, data_t *convKernels,
		data_t *bias, data_int CONV_KERNEL_LENGTH, data_int CONV_STRIDE,
		data_int Win, data_int Hin, data_int N, data_int M, data_int Wout, data_int Hout, data_int group)
{
	static data_t inp_temp[CONV1_KERNEL_1_LENGTH][CONV1_KERNEL_1_LENGTH][N1];
//	static data_t kernel_temp[CONV1_KERNEL_1_LENGTH][CONV1_KERNEL_1_LENGTH][N1];

	conv_layer_label12:for(int w=0; w<Wout; w++){
			conv_layer_label11:for(int h=0; h<Hout; h++){
				// input feature map for all the M output feature maps is the same
				// so buffer the input feature map
				int wStart, hStart;
				wStart=w*CONV_STRIDE;
				hStart=h*CONV_STRIDE;
				int ix, jy;
				conv_layer_label0:for(int n1=0;n1<N;n1++)
				{
					ix=0; jy=0;
					conv_layer_label1:for(int h1=hStart; h1< hStart+CONV_KERNEL_LENGTH; h1++, ix++)
					{
						jy=0;
						conv_layer_label2:for(int w1=wStart; w1<wStart+CONV_KERNEL_LENGTH; w1++, jy++)
						{
							inp_temp[ix][jy][n1]= (*(image + n1*Win*Hin + h1*Win + w1));
						}
					}
				}
				// Now for each of the output feature map ( total o/p feature maps=M)
				conv_layer_label10:for(int m=0; m<M; m++)
				{
						//*(conv + m*(Wout*Hout) + h*Wout + w)=0;
						data_t sum=0;
						/*
						conv_layer_label3:for(int n2=0;n2<N;n2++)
						{
							conv_layer_label4:for(int h2=0; h2< CONV_KERNEL_LENGTH; h2++)
							{
								conv_layer_label5:for(int w2=0; w2<CONV_KERNEL_LENGTH; w2++)
								{
									kernel_temp[h2][w2][n2]= (*(convKernels + h2*CONV_KERNEL_LENGTH + w2 + n2*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH + m*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH*N));
								}
							}
						}
						*/

						conv_layer_label9:for(int n=0;n<N;n++)
						{
							data_t temp_sum1=0;
							// interchanging hStart wStart loops should give same result, take care of i,j incrementing accordingly
							conv_layer1_for_each_inp_n_kernel_label1:for(int i=0; i<CONV_KERNEL_LENGTH; i++)
							{
										data_t temp_sum0=0;
									conv_layer1__mac_11_unroll_label0:for(int j=0; j<CONV_KERNEL_LENGTH; j++)
										{

										temp_sum0 += inp_temp[i][j][n] * (*(convKernels + i*CONV_KERNEL_LENGTH + j + n*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH + m*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH*N));//kernel_temp[i][j][n];
										}
									temp_sum1 += temp_sum0;
							}
							sum += temp_sum1;
						}
						*(conv + m*(Wout*Hout) + h*Wout + w)= sum + *(bias+m);

				}
			}
		}

}
// relu
void relu( data_t *relu, data_t *conv, data_int CONV_FMAP_WIDTH, data_int CONV_FMAPS )
{
	data_t temp;
    relu_label11:for(int m=0; m<CONV_FMAPS; m++)
    {
        relu_label10:for(int w=0; w<CONV_FMAP_WIDTH; w++)
        {
            relu_label9:for(int h=0; h<CONV_FMAP_WIDTH; h++)
            {
            	*(relu + m*(CONV_FMAP_WIDTH*CONV_FMAP_WIDTH) + h*CONV_FMAP_WIDTH + w) = *( conv + m*(CONV_FMAP_WIDTH*CONV_FMAP_WIDTH) + h*CONV_FMAP_WIDTH + w)>0  ? *(conv + m*(CONV_FMAP_WIDTH*CONV_FMAP_WIDTH) + h*CONV_FMAP_WIDTH + w) : 0;
            //    temp=relu[w][h][m];
            }
        }
 //      printf("element of relu at 0 0 %d is %f\n",relu[0][0][m]);
    }
}

// max pooling
void max_pool(data_t *poolx, data_t *relu, data_int CONV_FMAP_WIDTH, data_int CONV_FMAPS, data_int MAX_POOL_KERNEL_SIZE, data_int MAX_POOL_STRIDE, data_int poolxInSize, data_int poolxOutSize )
{
    int  Wout, Hout, hStart, wStart;
    Wout = (CONV_FMAP_WIDTH-MAX_POOL_KERNEL_SIZE)/MAX_POOL_STRIDE + 1;
    Hout = Wout ; // since we are dealing with square Feature maps
    max_pool_label16:for(int m=0; m < int(CONV_FMAPS); m++)
    {
        max_pool_label17:max_pool_label18:for(int h=0; h<Hout; h++)
        {
            hStart = h*MAX_POOL_STRIDE;
         //   hEnd=hStart+MAX_POOL_KERNEL_SIZE;
            max_pool_label15:for(int w=0; w<Wout; w++)
            {
                wStart = (w)*MAX_POOL_STRIDE;
           //     wEnd=wStart+MAX_POOL_KERNEL_SIZE;
                //poolx[w][h][m]=0;
                *(poolx + m*(poolxOutSize*poolxOutSize) + w*poolxOutSize + h)=0;
                max_pool_label13:for(int hk=hStart; hk<hStart+MAX_POOL_KERNEL_SIZE; hk++)     // hk, wk are poolx kernel size
                {
                    max_pool_label12:for(int wk=wStart; wk<wStart+MAX_POOL_KERNEL_SIZE; wk++)
                    {
                    //poolx[w][h][m]=(poolx[w][h][m]>relu[wk][hk][m])? poolx[w][h][m] : relu[wk][hk][m];
                    *(poolx + m*(poolxOutSize*poolxOutSize) + w*poolxOutSize + h)= (*(poolx + m*(poolxOutSize*poolxOutSize) + w*poolxOutSize + h)>*(relu + m*(poolxInSize*poolxInSize) + wk*poolxInSize + hk)) ? *(poolx + m*(poolxOutSize*poolxOutSize) + w*poolxOutSize + h) : *(relu + m*(poolxInSize*poolxInSize) + wk*poolxInSize + hk);
                    }
                }
            }
        }
    }
}

/* lrn : Local Response Normalization across nearby channels
function [ lrn ] = lrn( pool, localSize, alpha, beta, k )
%Local Response Normalization across nearby channels.
%pool is a 3d matrix: W x H x M.
%lrn is a 3d matrix: W x H x M.
%localSize, alpha, beta and k are integers.
%The output pixels depend only on pixels of nearby feature maps at the same position
%(same w/h coordinates).
%Formula:
%lrn_xy_i=pool_xy_i/(k+alpha/localSize*sum_i(pool_xy_i^2))^beta.
%The padding pixels consist of zeros.
*/
void lrn(data_t *lrn, data_t *pool, data_int localSize, data_t alpha, data_t beta, data_int k, data_int W, data_int H, data_int M )
{
    //int W=27, H=27, M=96;
    // set lrn to zero
    /*for(int w=0; w<W; w++)
    {
        for(int h=0; h<H; h++)
        {
            for(int m=0; m<M; m++)
            {
             //   lrn[w][h][m]= 0;
            	*(lrn + m*(W*H) + w*H + h)=0;
            	//pool[w][h][m]=0;
            	// *(pool + m*(27*27) + w*27 + h)=0;
            }
        }
    }*/
    // compute lrn
    int lsby2=localSize/2; // local size by 2
  //  std::cout << " lsby2 = " << lsby2 << "\n" ;
    lrn_label8:for(int w=0; w<W; w++)
    {
        lrn_label7:for(int h=0; h<H; h++)
        {
            lrn_label6:for(int m=0; m<M; m++)
            {
                // formulae
            	*(lrn + m*(W*H) + w*H + h)=0;
                // lrn[w][h][m] = pool[w][h][m] / ((k+alpha/localSize*sum(pool(w,h,mStart:mEnd).^2))^beta)
                data_t mStart, mEnd, mMinuslsby2, mPluslsby2, sum2=0, temp,expTempBeta;
                mMinuslsby2=m-lsby2;
                mPluslsby2=m+lsby2;
                mStart=(mMinuslsby2 > 0)?(mMinuslsby2):0;
                mEnd=(mPluslsby2 < (M-1))? mPluslsby2 : (M-1);
                //sum2_lrn_kernel(sum2, pool, w, h, mStart, mEnd);
                data_t temp_sum2=0;
                lrn_label5:for(int k1=mStart; k1<=mEnd; k1++)
                    {
                    //temp_sum2 += pool[w][h][k1]*pool[w][h][k1];
                	temp_sum2 += (*(pool + k1*(W*H) + w*H + h))*(*(pool + k1*(W*H) + w*H + h)) ;
                    }
                sum2=temp_sum2;
         //       std::cout << " sum2 = " << sum2 << "\n" ;
                temp = ( k + alpha/localSize*sum2 ) ;
          //      std::cout << " temp = " << temp << "\n" ;
                expTempBeta=pow(temp,beta);
          //      std::cout << " expTempBeta = " << expTempBeta << "\n" ;
               // exponent(expTempBeta, temp , beta);
                //lrn[w][h][m] = pool[w][h][m] / ( exponent(( k + alpha/localSize*sum2 ) , beta));//(((k + (alpha/localSize*sum2))^beta)
          //      std::cout << " temp = pool[w][h][m] / (expTempBeta) " << pool[w][h][m] / (expTempBeta)<< "\n" ;
             //   lrn[w][h][m] = pool[w][h][m] / (expTempBeta) ;//(((k + (alpha/localSize*sum2))^beta)
                *(lrn + m*(W*H) + w*H + h)= (*(pool + m*(W*H) + w*H + h)) / expTempBeta;
            }
        }
    }
}
// sum of dot product of lru kernel
/*
void sum2_lrn_kernel(data_t sum2, data_t (&pool)[27][27][96],
                     int w, int h, int mStart, int mEnd)
{
    data_t temp_sum2=0;
    for(int m=mStart; m<=mEnd; m++)
        {
            temp_sum2 += pool[w][h][m]*pool[w][h][m];
        }
        sum2=temp_sum2;
}

void exponent(data_t expTempBeta, data_t temp, data_t beta)
{
    expTempBeta=pow(temp,beta);
}

*/

//writeData
void writeData()
{
	float temp1;

    if( remove( "D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\Output.txt" ) != 0 )
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );

    std::ofstream output("D:\\sridhar\\workdir\\CNN_HLS_implementation\\convolution\\data\\Output.txt");
    int Mps=96, Len=55, Wid=55; // conv1
  //  int Mps=96, Len=27, Wid=27; //pool1
   //   int Mps=256, Len=27, Wid=27; // lrn1
//       int Mps=256, Len=27, Wid=27; //conv2; relu2
    //    int Mps=96, Len=31, Wid=31; //lrn1 padded;
   //  int Mps=256, Len=13, Wid=13; // norm2 lrn2, pool2,
   // int Mps=256, Len=13, Wid=13;  //  conv3
    // int Mps=256, Len=15, Wid=15; // lrn2 padded
   //  int Mps=256, Len=6, Wid=6;	// pool5

    for (int m = 0; m < Mps; m++)
        {
    	for (int h = 0; h < Len; h++)
    		{
    			for (int w = 0; w < Wid; w++)
                {
    				output <<  *((data_t *)conv1 + m*(Len*Wid) + h*Wid + w)  << " "; //  lrn2Padded[h][w][m]; //
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
	for(int ker=0; ker<=0 ; ker++)
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
