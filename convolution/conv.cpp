//Sub-routines for convolution, relu, max pooling, lrn layers
#include "conv.h"
#include <stdio.h>
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////
/*
void conv_layer(data_t (&conv)[Wout][Hout][OPFMapsCnt], data_t (&image)[Win][Hin][InpFMapCnt], data_t (&convKernels)[WKer][HKer][InpFMapCnt][OPFMapsCnt],
		data_t (&bias)[0][0][0][OPFMapsCnt], data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE, data_int M, data_int Wout, data_int Hout, data_int Win, data_int Hin, data_int N, data_int group)
		// N= inp fMaps count, M=output Fmaps count
{
	for(int w=0; w<Wout; w++){
		for(int h=0; h<Hout; h++){
			for(int m=0; m<M; m++){
			conv[w][h][m]=0;
			}
		}
	}
	// compute based on which group the convolution layer below to
	if(group==1)
	{
	int wStart, hStart;
	for(int w=0; w<Wout; w++){
		for(int h=0; h<Hout; h++){
			wStart=w*CONV_STRIDE;
			hStart=h*CONV_STRIDE;
			for(int m=0; m<M; m++){
				conv[w][h][m]=mult_acc(image, wStart, hStart, CONV_KERNEL_LENGTH,convKernels, m, 1 );
				conv[w][h][m]+=bias[0][0][0][m];
			}
		}
	}
	}
	else if(group==2)
	{
	// for 0 to M/2 feature maps
	int wStart, hStart;
	for(int w=0; w<Wout; w++){
		for(int h=0; h<Hout; h++){
			wStart=w*CONV_STRIDE;
			hStart=h*CONV_STRIDE;
			for(int m=0; m< int(M/2); m++){
				conv[w][h][m]=mult_acc(image, wStart, hStart, CONV_KERNEL_LENGTH,convKernels, m, 2 );
				conv[w][h][m]+=bias[0][0][0][m];
			}
		}
	}
	// for M/2 + 1 to M feature maps
	int wStart, hStart;
	for(int w=0; w<Wout; w++){
		for(int h=0; h<Hout; h++){
			wStart=w*CONV_STRIDE;
			hStart=h*CONV_STRIDE;
			for(int m=(int(M/2)+1); m<M; m++){
				conv[w][h][m]=mult_acc(image, wStart, hStart, CONV_KERNEL_LENGTH,convKernels, m, 3 );
				conv[w][h][m]+=bias[0][0][0][m];
			}
		}
	}
	}
}
*/
// Convolves weights and input feature maps for the given point in output Feature map
/*
data_t mult_acc (data_t (&image)[Win][Hin][InpFMapCnt],data_t wStart, data_t hStart, data_t CONV_KERNEL_LENGTH, data_t (&convKernels)[WKer][HKer][InpFMapCnt][OPFMapsCnt], data_int m, data_int InpFMapCnt, data_int group )
{
	data_t sum=0;
	int i,j, nStart, nEnd;

	switch(group) {
		case 1:
				nStart=0;
				nEnd=InpFMapCnt;
				break;
		case 2:
				nStart=0;
				nEnd=int(InpFMapCnt/2);
				break;
		case 3:
				nStart=int(InpFMapCnt/2)+1;
				nEnd=InpFMapCnt;
				break;
		default:
				nStart=0;
				nEnd=0;
	}

	for(int n=nStart;n<nEnd;n++)
    {
        i=0;j=0;
        // interchanging hStart wStart loops should give same result, take care of i,j incrementing accordingly
        for(int h=hStart; h<hStart+CONV_KERNEL_LENGTH; h++,i++)
        {
            for(int w=wStart; w<wStart+CONV_KERNEL_LENGTH; w++,j++)
            {
                sum += image[h][w][n]*convKernels[i][j][n][m];
            }
            j=0;
        }
        i=0;
    }
	return sum;
}
/////////////////////////////////////////////////////////////////
*/
// Convolve the whole image to generate M output feature map

void conv_layer1(data_t *conv, data_t (&image)[227][227][3], data_t (&convKernels)[11][11][3][96],
		data_t *bias, data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE)
//void conv_layer1(data_t *conv, data_t *image, data_t *convKernels,
//		data_t *bias, data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE)
{
//	std::cout << "Line 10" << bias[0][0][0][0] << endl;
	int M=96; //int pad=0;
	int Wout=55, Hout=55, wStart, hStart;
	float temp, temp1, *tempAddr;
 //   Win=227; Hin=227;
    // Padding required for conv layers other than 1st conv layer.

//	std::cout <<  "Line 24" << bias[0][0][0][0] << endl;
	for(int w=0; w<Wout; w++){
		for(int h=0; h<Hout; h++){
			for(int m=0; m<M; m++){
				*( conv + m*(Wout*Hout) + h*Wout + w)=0;
			}
		}
	}
	//int conv1[55][55][96]=0;
	// for each output featuremap, for each output pixel in that Fmap compute
	// Lets say each output feature map is of size Wout X Hout
//	std::cout << "Line 35" << bias[0][0][0][0] << endl;
	for(int w=0; w<Wout; w++){
		for(int h=0; h<Hout; h++){
			wStart=w*CONV_STRIDE;
			//wEnd=wStart+CONV_KERNEL_LENGTH-1;
			hStart=h*CONV_STRIDE;
            //hEnd=hStart+CONV_KERNEL_LENGTH-1;
			// Now for each of the output feature map ( total o/p feature maps=M)
			for(int m=0; m<M; m++){
				*(conv + m*(Wout*Hout) + h*Wout + w)=mult_acc(image, wStart, hStart, CONV_KERNEL_LENGTH,convKernels, m );
			//	temp=*(conv + m*(Wout*Hout) + h*Wout + w) ;
			//	printf("conv at %d %d %d is %f \n",w,h,m,*(conv + m*(Wout*Hout) + h*Wout + w) );
//				conv[w][h][m]+=bias[1][1][1][m];
			}
		}
	}

	// adding Bias
//	std::cout << "Line 51 " << bias[0][0][0][0] << endl;
    for(int m=0; m<M; m++){
		for(int h=0; h<Hout; h++){
			for(int w=0; w<Wout; w++){
				*( conv + m*(Wout*Hout) + h*Wout + w)+=*(bias+m);
				temp=*(conv + m*(Wout*Hout) + h*Wout + w) ;
		//		temp1=conv[w][h][m];
		//		tempAddr = &conv + m*(Wout*Hout) + h*Wout + w;
			//	printf("conv at %d %d %d is %f \n",w,h,m,*(conv + m*(Wout*Hout) + h*Wout + w) );
			}
		}
	}
	//std::cout << bias[0][0][0][0] << endl;
}
// Convolves weights and input feature maps for the given point in output Feature map
data_t mult_acc (data_t (&image)[227][227][3],data_t wStart, data_t hStart, data_t CONV_KERNEL_LENGTH, data_t (&convKernels)[11][11][3][96], int m )
{
	data_t sum=0;
	int i,j;
	for(int n=0;n<3;n++)
    {
        i=0;j=0;
        // interchanging hStart wStart loops should give same result, take care of i,j incrementing accordingly
        for(int h=hStart; h<hStart+CONV_KERNEL_LENGTH; h++,i++)
        {
            for(int w=wStart; w<wStart+CONV_KERNEL_LENGTH; w++,j++)
            {
//                printf("conv kernel at w=%d h=%d i/p map=%d = %f, input image=%f \n",w,h,n,convKernels[i][j][n][m],image[w][h][n]);
                sum += image[h][w][n]*convKernels[i][j][n][m];
                //j=j+1;
            }
            j=0;
            //i=i+1;
 //       printf("element of O/P FM at = %f \n",sum);
        }
        i=0;
//        printf("element of O/P FM at = %d \n",sum);

    }
	return sum;
}

//
//void conv_layer2(data_t (&conv)[Wout2][Wout2][OPFMapsCnt2], data_t (&image)[Win2][Win2][InpFMapCnt2], data_t (&convKernels2)[WKer2][WKer2][InpFMapCnt2][OPFMapsCnt2], data_t (&bias2)[0][0][0][OPFMapsCnt2]data_t CONV_KERNEL_LENGTH2, data_t CONV_STRIDE2, data_int M2, data_int Wout2, data_int Hout2, data_int Win2, data_int Hin2, data_int N2, data_int group2);
//{
//}
//

// relu
void relu( data_t *relu, data_t *conv, data_t CONV1_FMAP_WIDTH, data_t CONV1_FMAPS )
{
	data_t temp;
    for(int m=0; m<CONV1_FMAPS; m++)
    {
        for(int w=0; w<CONV1_FMAP_WIDTH; w++)
        {
            for(int h=0; h<CONV1_FMAP_WIDTH; h++)
            {
            	*(relu + m*(55*55) + h*55 + w) = *( conv + m*(55*55) + h*55 + w)>0  ? *(conv + m*(55*55) + h*55 + w) : 0;
            //    temp=relu[w][h][m];
            }
        }
 //      printf("element of relu at 0 0 %d is %f\n",relu[0][0][m]);
    }
}
// max pooling
void max_pool(data_t *pool, data_t *relu, data_t CONV_FMAP_WIDTH, data_t CONV_FMAPs, data_t MAX_POOL_KERNEL_SIZE, data_t MAX_POOL_STRIDE)
{
    int  Wout, Hout, hStart, wStart;
    Wout = (CONV_FMAP_WIDTH-MAX_POOL_KERNEL_SIZE)/MAX_POOL_STRIDE + 1;
    Hout = Wout ; // since we are dealing with square Feature maps
    for(int m=0; m < int(CONV1_FMAPS); m++)
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
                *(pool + m*(27*27) + w*27 + h)=0;
                for(int hk=hStart; hk<hStart+MAX_POOL_KERNEL_SIZE; hk++)     // hk, wk are pool kernel size
                {
                    for(int wk=wStart; wk<wStart+MAX_POOL_KERNEL_SIZE; wk++)
                    {
                    //pool[w][h][m]=(pool[w][h][m]>relu[wk][hk][m])? pool[w][h][m] : relu[wk][hk][m];
                    *(pool + m*(27*27) + w*27 + h)= (*(pool + m*(27*27) + w*27 + h)>*(relu + m*(55*55) + wk*55 + hk)) ? *(pool + m*(27*27) + w*27 + h) : *(relu + m*(55*55) + wk*55 + hk);
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
void lrn(data_t *lrn, data_t *pool, int localSize, float alpha, float beta, int k)
{
    int W=27, H=27, M=96;
    // set lrn to zero
    for(int w=0; w<W; w++)
    {
        for(int h=0; h<H; h++)
        {
            for(int m=0; m<M; m++)
            {
             //   lrn[w][h][m]= 0;
            	*(lrn + m*(27*27) + w*27 + h)=0;
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
                mEnd=(mPluslsby2 < M)? mPluslsby2 : M;
                //sum2_lrn_kernel(sum2, pool, w, h, mStart, mEnd);
                data_t temp_sum2=0;
                for(int k1=mStart; k1<=mEnd; k1++)
                    {
                    //temp_sum2 += pool[w][h][k1]*pool[w][h][k1];
                	temp_sum2 += (*(pool + k1*(27*27) + w*27 + h))*(*(pool + k1*(27*27) + w*27 + h)) ;
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
                *(lrn + m*(27*27) + w*27 + h)= (*(pool + m*(27*27) + w*27 + h)) / expTempBeta;
            }
        }
    }
}
// sum of dot product of lru kernel
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

