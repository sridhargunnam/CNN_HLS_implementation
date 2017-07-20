//Sub-routines for convolution, relu, max pooling, lrn layers
#include "conv.h"
#include <stdio.h>
#include <iostream>
using namespace std;

// Convolves weights and N input feature maps for the given point in output Feature map
//  generate M output feature maps
void conv_layer(data_t *conv, data_t *image, data_t *convKernels,
		data_t *bias, data_int CONV_KERNEL_LENGTH, data_int CONV_STRIDE,
		data_int Win, data_int Hin, data_int N, data_int M, data_int Wout, data_int Hout, data_int group)
{
	//int M=96; //int pad=0;
	//int Wout=55, Hout=55,
	int wStart, hStart;
	float temp, temp1, *tempAddr;
	//   Win=227; Hin=227;
    // Padding required for conv layers other than 1st conv layer.

	conv_layer_label8:for(int w=0; w<Wout; w++){
		conv_layer_label7:for(int h=0; h<Hout; h++){
			conv_layer_label6:for(int m=0; m<M; m++){
				*( conv + m*(Wout*Hout) + h*Wout + w)=0;
			}
		}
	}
	// for each output featuremap, for each output pixel in that Fmap compute
	// Lets say each output feature map is of size Wout X Hout
	// compute based on which group the convolution layer below to
	if(group==1)
	{
		int wStart, hStart;
		conv_layer_label12:for(int w=0; w<Wout; w++){
			conv_layer_label11:for(int h=0; h<Hout; h++){
				wStart=w*CONV_STRIDE;
				hStart=h*CONV_STRIDE;
				// Now for each of the output feature map ( total o/p feature maps=M)
				conv_layer_label10:for(int m=0; m<M; m++){
						data_t sum=0;
						int i,j;
						conv_layer_label9:for(int n=0;n<N;n++)
						{
							i=0;j=0;
							// interchanging hStart wStart loops should give same result, take care of i,j incrementing accordingly
							conv_layer1_for_each_inp_n_kernel_label1:for(int h1=hStart; h1<hStart+CONV_KERNEL_LENGTH; h1++,i++)
							{
									conv_layer1__mac_11_unroll_label0:for(int w1=wStart; w1<wStart+CONV_KERNEL_LENGTH; w1++,j++)
										{

										sum += (*(image + n*Win*Hin + h1*Win + w1)) *  (*(convKernels + i*CONV_KERNEL_LENGTH + j + n*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH + m*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH*N));
										}
								j=0;
							}
							i=0;
						}
					*(conv + m*(Wout*Hout) + h*Wout + w)=sum + *(bias+m);
				}
			}
		}
	}
	///////////////////////
	///////////// group 2
	else if(group==2)
	{
		// for 0 to M/2 feature maps
		int wStart, hStart;
		for(int w=0; w<Wout; w++){
			for(int h=0; h<Hout; h++){
				wStart=w*CONV_STRIDE;
				hStart=h*CONV_STRIDE;
				// Now for each of the output feature map ( total o/p feature maps=M)
				for(int m=0; m < data_int(M/2); m++){
						data_t sum=0;
						int i,j;
						for(int n=0;n< data_int(N/2) ;n++)
						{
							i=0;j=0;
							// interchanging hStart wStart loops should give same result, take care of i,j incrementing accordingly
							conv_layer_label2:for(int h=hStart; h<hStart+CONV_KERNEL_LENGTH; h++,i++)
							{
								conv_layer_label3:for(int w=wStart; w<wStart+CONV_KERNEL_LENGTH; w++,j++)
								{
									sum += (*(image + n*Win*Hin + h*Win + w)) *  (*(convKernels + i*CONV_KERNEL_LENGTH + j + n*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH + m*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH*data_int(N/2)));
								}
								j=0;
							}
							i=0;
						}
					*(conv + m*(Wout*Hout) + h*Wout + w)=sum + *(bias+m);
				}
			}
		}
		//////////////////////////////////////////////
			// for M/2 + 1 to M feature maps
		for(int w=0; w<Wout; w++)
		{
			for(int h=0; h<Hout; h++){
				wStart=w*CONV_STRIDE;
				hStart=h*CONV_STRIDE;
				// Now for each of the output feature map ( total o/p feature maps=M)
				for(int m=data_int(M/2); m < M; m++){
						data_t sum=0;
						int i,j;
						for(int n=data_int(N/2);n<N;n++)
						//for(int n=0;n< data_int(N/2) ;n++)
						{
							i=0;j=0;
							// interchanging hStart wStart loops should give same result, take care of i,j incrementing accordingly
							conv_layer_label4:for(int h=hStart; h<hStart+CONV_KERNEL_LENGTH; h++,i++)
							{
								conv_layer_label5:for(int w=wStart; w<wStart+CONV_KERNEL_LENGTH; w++,j++)
								{
									sum += (*(image + n*Win*Hin + h*Win + w)) *  (*(convKernels + i*CONV_KERNEL_LENGTH + j + (n-(data_int(N/2)))*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH + m*CONV_KERNEL_LENGTH*CONV_KERNEL_LENGTH*data_int(N/2)));
								}
								j=0;
							}
							i=0;
						}
					*(conv + m*(Wout*Hout) + h*Wout + w)=sum + *(bias+m);
				}
			}
		}
	}

}
// relu
void relu( data_t *relu, data_t *conv, data_int CONV_FMAP_WIDTH, data_int CONV_FMAPS )
{
	data_t temp;
    for(int m=0; m<CONV_FMAPS; m++)
    {
        for(int w=0; w<CONV_FMAP_WIDTH; w++)
        {
            for(int h=0; h<CONV_FMAP_WIDTH; h++)
            {
            	*(relu + m*(CONV_FMAP_WIDTH*CONV_FMAP_WIDTH) + h*CONV_FMAP_WIDTH + w) = *( conv + m*(CONV_FMAP_WIDTH*CONV_FMAP_WIDTH) + h*CONV_FMAP_WIDTH + w)>0  ? *(conv + m*(CONV_FMAP_WIDTH*CONV_FMAP_WIDTH) + h*CONV_FMAP_WIDTH + w) : 0;
            //    temp=relu[w][h][m];
            }
        }
 //      printf("element of relu at 0 0 %d is %f\n",relu[0][0][m]);
    }
}
// max pooling
void max_pool(data_t *pool, data_t *relu, data_int CONV_FMAP_WIDTH, data_int CONV_FMAPS, data_int MAX_POOL_KERNEL_SIZE, data_int MAX_POOL_STRIDE, data_int poolInSize, data_int poolOutSize )
{
    int  Wout, Hout, hStart, wStart;
    Wout = (CONV_FMAP_WIDTH-MAX_POOL_KERNEL_SIZE)/MAX_POOL_STRIDE + 1;
    Hout = Wout ; // since we are dealing with square Feature maps
    for(int m=0; m < int(CONV_FMAPS); m++)
    {
        for(int h=0; h<Hout; h++)
        {
            hStart = h*MAX_POOL_STRIDE;
         //   hEnd=hStart+MAX_POOL_KERNEL_SIZE;
            for(int w=0; w<Wout; w++)
            {
                wStart = (w)*MAX_POOL_STRIDE;
           //     wEnd=wStart+MAX_POOL_KERNEL_SIZE;
                //pool[w][h][m]=0;
                *(pool + m*(poolOutSize*poolOutSize) + w*poolOutSize + h)=0;
                for(int hk=hStart; hk<hStart+MAX_POOL_KERNEL_SIZE; hk++)     // hk, wk are pool kernel size
                {
                    for(int wk=wStart; wk<wStart+MAX_POOL_KERNEL_SIZE; wk++)
                    {
                    //pool[w][h][m]=(pool[w][h][m]>relu[wk][hk][m])? pool[w][h][m] : relu[wk][hk][m];
                    *(pool + m*(poolOutSize*poolOutSize) + w*poolOutSize + h)= (*(pool + m*(poolOutSize*poolOutSize) + w*poolOutSize + h)>*(relu + m*(poolInSize*poolInSize) + wk*poolInSize + hk)) ? *(pool + m*(poolOutSize*poolOutSize) + w*poolOutSize + h) : *(relu + m*(poolInSize*poolInSize) + wk*poolInSize + hk);
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
    for(int w=0; w<W; w++)
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
    }
    // compute lrn
    int lsby2=localSize/2; // local size by 2
  //  std::cout << " lsby2 = " << lsby2 << "\n" ;
    for(int w=0; w<W; w++)
    {
        for(int h=0; h<H; h++)
        {
            for(int m=0; m<M; m++)
            {
                // formulae
                // lrn[w][h][m] = pool[w][h][m] / ((k+alpha/localSize*sum(pool(w,h,mStart:mEnd).^2))^beta)
                data_t mStart, mEnd, mMinuslsby2, mPluslsby2, sum2=0, temp,expTempBeta;
                mMinuslsby2=m-lsby2;
                mPluslsby2=m+lsby2;
                mStart=(mMinuslsby2 > 0)?(mMinuslsby2):0;
                mEnd=(mPluslsby2 < (M-1))? mPluslsby2 : (M-1);
                //sum2_lrn_kernel(sum2, pool, w, h, mStart, mEnd);
                data_t temp_sum2=0;
                for(int k1=mStart; k1<=mEnd; k1++)
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
