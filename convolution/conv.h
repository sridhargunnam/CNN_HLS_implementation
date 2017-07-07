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
const unsigned CONV1_KERNEL_1_LENGTH=11;
const unsigned CONV1_STRIDE=4;
const unsigned CONV1_PAD=0;
const unsigned CONV1_GROUP=1;
const unsigned CONV1_FMAP_WIDTH=55;
const unsigned CONV1_FMAPS=96;
const unsigned MAX_POOL_KERNEL_SIZE1=3;
const unsigned MAX_POOL_STRIDE1=2;
const unsigned WKer1=11;
const unsigned Win1=227;
const unsigned Wout1=55;
const unsigned InpFMapCnt1=3;
const unsigned OPFMapCnt1=3;

// conv2 layer parameters
const unsigned CONV2_KERNEL_2_LENGTH=22;
const unsigned CONV2_STRIDE=4;
const unsigned CONV2_PAD=0;
const unsigned CONV2_GROUP=2;
const unsigned CONV2_FMAP_WIDTH=55;
const unsigned CONV2_FMAPS=96;
const unsigned MAX_POOL_KERNEL_SIZE2=3;
const unsigned MAX_POOL_STRIDE2=2;
const unsigned WKer2=22;
const unsigned Win2=227;
const unsigned Wout2=55;
const unsigned InpFMapCnt2=3;
const unsigned OPFMapsCnt2=3;
/*
const unsigned CONV1_STRIDE=4;
const unsigned CONV1_PAD=0;
const unsigned CONV1_GROUP=1;

const unsigned CONV1_FMAPS=96;
const unsigned MAX_POOL_KERNEL_SIZE1=3;
const unsigned MAX_POOL_STRIDE1=2;
*/
//void conv(data_t (&a)[11][11], data_t (&b)[11][11], data_t *c);

void conv_layer1(data_t *conv, data_t *image, data_t *convKernels,
		data_t *bias, data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE);// data_t CONV1_STRIDE, data_t CONV1_PAD, data_t CONV1_GROUP );
//void conv_layer1(data_t *conv, data_t *image, data_t *convKernels,
//		data_t *bias, data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE);// data_t CONV1_STRIDE, data_t CONV1_PAD, data_t CONV1_GROUP );
//void conv_layer2(data_t (&conv2x)[Wout2][Wout2][OPFMapsCnt2], data_t (&imagex)[Win2][Win2][InpFMapCnt2], data_t (&convKernels2x)[WKer2][WKer2][InpFMapCnt2][OPFMapsCnt2], data_t (&bias2)[0][0][0][OPFMapsCnt2]data_t CONV_KERNEL_LENGTH2, data_t CONV_STRIDE2, data_int M2, data_int Wout2, data_int Hout2, data_int Win2, data_int Hin2, data_int N2, data_int group2);

//void conv_layer1(data_t (&conv)[Wout1][Wout1][CONV1_FMAPS], data_t (&image)[Win1][Win1][InpFMapCnt1], data_t (&convKernels)[WKer1][WKer1][InpFMapCnt1][OPFMapsCnt1],
//		data_t (&bias)[0][0][0][OPFMapsCnt1], data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE, data_int M, data_int Wout, data_int Hout, data_int Win, data_int Hin, data_int N, data_int group)

//data_t mult_acc(data_t (&image)[227][227][3],data_t wStart, data_t hStart, data_t CONV_KERNEL_LENGTH, data_t (&convKernels)[11][11][3][96], int m );
void relu( data_t *relu, data_t *conv, data_t CONV_FMAP_WIDTH, data_t CONV_FMAPS );
void max_pool(data_t *pool, data_t *relu, data_t FMAP_WIDTH, data_t FMAPS, data_t MAX_POOL_KERNEL_SIZE, data_t MAX_POOL_STRIDE);
void lrn(data_t *lrn, data_t *pool ,int localSize, float alpha, float beta, int k);
void sum2_lrn_kernel(data_t sum2, data_t (&pool)[27][27][96], int w, int h, int mStart, int mEnd);
void exponent(data_t expTempBeta, data_t temp, data_t beta);
