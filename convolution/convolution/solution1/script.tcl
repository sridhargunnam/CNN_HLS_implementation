############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project convolution
set_top conv
add_files conv.cpp
add_files -tb main.cpp
open_solution "solution1"
set_part {xc7vx485tffg1761-2} -tool vivado
create_clock -period 10 -name default
#source "./convolution/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
