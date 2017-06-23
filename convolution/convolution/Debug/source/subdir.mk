################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
D:/venky/workdir/designs/convolution/conv.cpp 

OBJS += \
./source/conv.o 

CPP_DEPS += \
./source/conv.d 


# Each subdirectory must supply rules for building sources it contributes
source/conv.o: D:/venky/workdir/designs/convolution/conv.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -ID:/Xilinx/Vivado_HLS/2017.1/win64/tools/auto_cc/include -ID:/Xilinx/Vivado_HLS/2017.1/win64/tools/systemc/include -ID:/Xilinx/Vivado_HLS/2017.1/include -ID:/venky/workdir/designs/convolution -ID:/Xilinx/Vivado_HLS/2017.1/include/etc -ID:/Xilinx/Vivado_HLS/2017.1/include/ap_sysc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


