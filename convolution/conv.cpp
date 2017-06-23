// matrix dot product and summation
#include "conv.h"
int conv(data_t a[11][11], data_t b[11][11])
{
	int sum=0;
	data_t i,j;
	data_t temp[11];
	for(i=0; i<11; i++)
	{
		temp[i]=0;
		for(j=0; j<11; j++)
		{
			temp[i]=temp[i]+a[i][j]*b[i][j];
		}
	}
	sum=0;
	for(j=0; j<11; j++)
			{
				sum=sum+temp[j];
			}
	return sum;
}
