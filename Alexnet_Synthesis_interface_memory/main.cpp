#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <string>
#include "conv.h"
// for random matrix generation

//
using namespace std;



// 	int sizeKer[5][4] = {conv1{11, 11, 3, 96}, conv2{5, 5, 48, 256},conv3{3,3,256,384},conv4{3,3,192,384}, conv5{3,3,192,256}} ;
int main()
{
 	readToArray();
/*	for(int w=0; w<55; w++){
			for(int h=0; h<55; h++){
				for(int m=0; m<96; m++){
					conv1[w][h][m]=0;
				}
			}
	}*/
///////////////////////////////////////////////////// stage 1 ////////////////////////////////////////////////////////////////////////////////////////////////
	synthesize();
    writeData();
    printf("********************END***********************");
return 0;
}
