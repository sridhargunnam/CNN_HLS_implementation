// matrix dot product and summation
#include "conv.h"
void conv(data_t (&a)[11][11], data_t (&b)[11][11], data_t* c)
{
	data_t sum = 0;
	data_t temp[11];
	for(int i=0; i<11; i++)
	{
		//temp[i]=0;
		for(int j=0; j<11; j++)
		{
			//temp[i]=temp[i]+*a[i][j]*b[i][j];
			sum += a[i][j] * b[i][j];
			//sum += (*(a+11*i+j)) * (*(b+11*i+j));
		}
	}
	*c = sum;
}


	// Convolve the whole image
	//int conv_layer1(data_t image,data_t convKernels1,data_t bias1, data_t stride);
	/*int conv_layer1(data_t image[227][227][3])//, data_t convKernels1[11][11][3][96],data_t bias1[96], data_t FMap1[55][55][96])
{

	return 0;
}
*/

void conv_layer1(data_t (&conv1)[55][55][96], data_t (&image)[227][227][3], data_t (&convKernels)[11][11][3][96],
		data_t (&bias)[1][1][1][96], data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE)
{
	int M=1;
	//int conv1[55][55][96]=0;
	// for each output featuremap, for each output pixel in that Fmap compute
	// Lets say each output feature map is of size Wout X Hout
	for(int w=0; w<Wout; w++){
		for(int h=0; h<Hout; h++){
			// Now for each of the output feature map ( total o/p feature maps=M)
			for(int m=0; m<M; m++){
				wstart=w*CONV_STRIDE;
				//wEnd=wStart+CONV_KERNEL_LENGTH-1;
				hStart=h*CONV_STRIDE;
				//hEnd=hStart+CONV_KERNEL_LENGTH-1;
				conv1[w][h][m]=mult_acc(image, wStart, hStart, CONV_KERNEL_LENGTH, &convKernels, m );
			}
		}
	}
}


data_t mult_acc(&image[][][], wStart,hStart, CONV_KERNEL_LENGTH, &convKernels, m )
{
	data_t sum=0;
	int i=0;j=0;
	for(int w=wStart; w<wStart+CONV_KERNEL_LENGTH; w++)
	{
		for(int h=hStart; h<hStart+CONV_KERNEL_LENGTH; h++)
			{
			sum += image[w][h]*convKernels[i][j];
			j=j+1;
			}
		i=i+1;
	}
}
