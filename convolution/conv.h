typedef int data_t;

typedef data_t image[227][227][3] ;
typedef data_t FMap1[55][55][96] ; // feature map 1 of conv layer1
typedef data_t kernel_1[11][11];
typedef data_t convKernels1[11][11][3][96];
typedef data_t bias1[96];

data_t conv(data_t a[11][11], data_t b[11][11]);

void conv_layer1(data_t image,data_t convKernels1,data_t bias1);
