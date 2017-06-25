typedef int data_t;

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

//void conv(data_t (&a)[11][11], data_t (&b)[11][11], data_t *c);

void conv_layer1(data_t (&conv1)[55][55][96], data_t (&image)[227][227][3], data_t (&convKernels)[11][11][3][96],
		data_t (&bias)[1][1][1][96], data_t CONV_KERNEL_LENGTH, data_t CONV_STRIDE);// data_t CONV1_STRIDE, data_t CONV1_PAD, data_t CONV1_GROUP );

data_t mult_acc(data_t (&image)[227][227][3],data_t wStart, data_t hStart, data_t CONV_KERNEL_LENGTH, data_t (&convKernels)[11][11][3][96], int m );
void relu( data_t (&relu)[55][55][96], data_t (&conv)[55][55][96], data_t CONV_FMAP_WIDTH, data_t CONV_FMAPS );
void max_pool(data_t (&pool)[27][27][96], data_t (&relu)[55][55][96], data_t FMAP_WIDTH, data_t FMAPS, data_t MAX_POOL_KERNEL_SIZE, data_t MAX_POOL_STRIDE);
void lrn(data_t (&lrn)[27][27][96], data_t (&pool)[27][27][96],int localSize, float alpha, float beta, int k);
void sum2_lrn_kernel(data_t sum2, data_t (&pool)[27][27][96], int w, int h, int mStart, int mEnd);
void exponent(data_t expTempBeta, data_t temp, data_t beta);
