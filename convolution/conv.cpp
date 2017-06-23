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
	/*sum=0;
	for(j=0; j<11; j++)
			{
				sum=sum+temp[j];
			}
	c=sum; */
	*c = sum;
}


// Convolve the whole image

void conv_layer1(data_t image[227][227][3], data_t convKernels1[11][11][3][96],data_t bias1[96], data_t FMap1[55][55][96])
{

}
