#include <stdio.h>
#include <stdlib.h>
#include "conv.h"
// for random matrix generation
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>
//
using namespace std;
int main()
{
	data_t a[11][11], b[11][11];
	data_t c;
	//generate random matrix for inputs a,b for testing
	srand((unsigned)time(NULL));

	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; i < 11; j++)
		{
			a[i][j] = 20 + rand() % 100;
			b[i][j] = 10 + rand() % 100;
		}
	}
		//
	c=conv(a,b);
//	conv_layer1(image,convKernels1,Bias);
return 0;
}
