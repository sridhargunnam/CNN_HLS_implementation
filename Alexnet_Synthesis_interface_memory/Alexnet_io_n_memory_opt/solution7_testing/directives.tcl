############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_loop_tripcount -max 11 "conv_layer/conv_layer1__mac_11_unroll_label0"
set_directive_loop_tripcount -max 11 "conv_layer/conv_layer1_for_each_inp_n_kernel_label1"
set_directive_loop_tripcount -max 3 "conv_layer/conv_layer_label9"
set_directive_loop_tripcount -max 96 "conv_layer/conv_layer_label10"
set_directive_loop_tripcount -max 55 "conv_layer/conv_layer_label11"
set_directive_loop_tripcount -max 55 "conv_layer/conv_layer_label12"
set_directive_loop_tripcount -max 3 "conv_layer/conv_layer_label0"
set_directive_loop_tripcount -max 11 "conv_layer/conv_layer_label1"
set_directive_loop_tripcount -max 11 "conv_layer/conv_layer_label2"
set_directive_loop_tripcount -max 3 "conv_layer/conv_layer_label3"
set_directive_loop_tripcount -max 11 "conv_layer/conv_layer_label4"
set_directive_loop_tripcount -max 11 "conv_layer/conv_layer_label5"
set_directive_unroll -factor 11 "conv_layer/conv_layer1__mac_11_unroll_label0"
set_directive_unroll -factor 11 "conv_layer/conv_layer1_for_each_inp_n_kernel_label1"
set_directive_unroll -factor 3 "conv_layer/conv_layer_label9"
set_directive_dataflow "synthesize"
set_directive_resource -core RAM_2P_BRAM "synthesize" biasData1
set_directive_resource -core RAM_2P_BRAM "synthesize" image
set_directive_resource -core RAM_2P_BRAM "synthesize" conv1
set_directive_resource -core RAM_2P_BRAM "synthesize" Conv1Kernel
set_directive_resource -core RAM_2P_BRAM "conv_layer" biasData1
set_directive_resource -core RAM_2P_BRAM "conv_layer" image
set_directive_resource -core RAM_2P_BRAM "conv_layer" conv1
set_directive_resource -core RAM_2P_BRAM "conv_layer" Conv1Kernel
set_directive_array_partition -type complete -dim 1 "conv_layer" kernel_temp
set_directive_array_partition -type complete -dim 1 "conv_layer" inp_temp
