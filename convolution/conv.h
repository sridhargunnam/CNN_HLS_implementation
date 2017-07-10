// Include half-float header file
//#include “hls_half.h”
//#include "hls_math.h"
// Use data-type “half”
//typedef half data_t;
//#include <stdio.h>      /* printf */
//#ifndef _conv_H_
//#define _conv_H_
#include <math.h>       /* pow */
typedef float data_t;
typedef int data_int;
//typedef data_t image[227][227][3] ;
//typedef data_t stride 4;
//typedef data_t FMap1[55][55][96] ; // feature map 1 of conv layer1
//typedef data_t kernel_1[11][11];
//typedef data_t convKernels1[11][11][3][96];
//typedef data_t bias1[1][1][1][96];
const data_int CONV1_KERNEL_1_LENGTH=11;
const data_int CONV1_STRIDE=4;
const data_int CONV1_PAD=0;
const data_int CONV1_GROUP=1;
const data_int CONV1_FMAP_WIDTH=55;
const data_int CONV1_FMAPS=96;
const data_int MAX_POOL_KERNEL_SIZE1=3;
const data_int MAX_POOL_STRIDE1=2;
const data_int WKer1=11;
const data_int Win1=227;
const data_int Hin1=227;
const data_int Wout1=55;
const data_int Hout1=55;
const data_int N1=3; //InpFMapCnt1=3;
const data_int M1=96; //OPFMapCnt1=96;
const data_int group1=1;

// conv2 layer parameters
const data_int CONV2_KERNEL_2_LENGTH=5;
const data_int CONV2_STRIDE=1;
const data_int CONV2_PAD=2;
const data_int CONV2_GROUP=2;
const data_int CONV2_FMAP_WIDTH=27;
const data_int CONV2_FMAPS=256;
const data_int MAX_POOL_KERNEL_SIZE2=3;
const data_int MAX_POOL_STRIDE2=2;
const data_int WKer2=5;
const data_int Win2=31;
const data_int Hin2=31;
const data_int Wout2=27;
const data_int Hout2=27;
const data_int N2=96; //InpFMapCnt2=3;
const data_int M2=256; //OPFMapCnt2=96;
const data_int group2=2;

const data_int poolInSize1=55;
const data_int poolOutSize1=27;

const data_int poolInSize2=27;
const data_int poolOutSize2=13;
//data_t Conv2Kernel[256][48][5][5];
const data_int CONV3_KERNEL_3_LENGTH=3;
const data_int CONV3_STRIDE=1;
const data_int CONV3_PAD=1;
const data_int CONV3_GROUP=1;
const data_int CONV3_FMAP_WIDTH=13;
const data_int CONV3_FMAPS=384;
const data_int WKer3=3;
const data_int Win3=15;
const data_int Hin3=15;
const data_int Wout3=13;
const data_int Hout3=13;
const data_int N3=256;
const data_int M3=384;
const data_int group3=3;

// conv3 layer parameters

/*
const unsigned CONV1_STRIDE=4;
const unsigned CONV1_PAD=0;
const unsigned CONV1_GROUP=1;

const unsigned CONV1_FMAPS=96;
const unsigned MAX_POOL_KERNEL_SIZE1=3;
const unsigned MAX_POOL_STRIDE1=2;
*/
//void conv(data_t (&a)[11][11], data_t (&b)[11][11], data_t *c);

void conv_layer(data_t *conv, data_t *image, data_t *convKernels,
		data_t *bias, data_int CONV_KERNEL_LENGTH, data_int CONV_STRIDE,
		data_int Win, data_int Hin, data_int N, data_int M, data_int Wout, data_int Hout, data_int group);// data_t CONV1_STRIDE, data_t CONV1_PAD, data_t CONV1_GROUP );
//void conv_layer1(data_t *conv, data_t *image, data_t *convKernels,
//		data_t *bias, data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE);// data_t CONV1_STRIDE, data_t CONV1_PAD, data_t CONV1_GROUP );
//void conv_layer2(data_t (&conv2x)[Wout2][Wout2][OPFMapsCnt2], data_t (&imagex)[Win2][Win2][InpFMapCnt2], data_t (&convKernels2x)[WKer2][WKer2][InpFMapCnt2][OPFMapsCnt2], data_t (&bias2)[0][0][0][OPFMapsCnt2]data_t CONV_KERNEL_LENGTH2, data_t CONV_STRIDE2, data_int M2, data_int Wout2, data_int Hout2, data_int Win2, data_int Hin2, data_int N2, data_int group2);

//void conv_layer1(data_t (&conv)[Wout1][Wout1][CONV1_FMAPS], data_t (&image)[Win1][Win1][InpFMapCnt1], data_t (&convKernels)[WKer1][WKer1][InpFMapCnt1][OPFMapsCnt1],
//		data_t (&bias)[0][0][0][OPFMapsCnt1], data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE, data_int M, data_int Wout, data_int Hout, data_int Win, data_int Hin, data_int N, data_int group)

//data_t mult_acc(data_t (&image)[227][227][3],data_t wStart, data_t hStart, data_t CONV_KERNEL_LENGTH, data_t (&convKernels)[11][11][3][96], int m );
void relu( data_t *relu, data_t *conv, data_int CONV_FMAP_WIDTH, data_int CONV_FMAPS );
void max_pool(data_t *pool, data_t *relu, data_int FMAP_WIDTH, data_int FMAPS, data_int MAX_POOL_KERNEL_SIZE, data_int MAX_POOL_STRIDE, data_int poolInSize, data_int poolOutSize);
void lrn(data_t *lrn, data_t *pool ,data_int localSize, float alpha, float beta, data_int k, data_int W, data_int H, data_int M);
void sum2_lrn_kernel(data_t sum2, data_t (&pool)[27][27][96], int w, int h, int mStart, int mEnd);
void exponent(data_t expTempBeta, data_t temp, data_t beta);
