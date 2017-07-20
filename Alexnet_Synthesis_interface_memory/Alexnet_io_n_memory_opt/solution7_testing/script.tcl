############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Alexnet_io_n_memory_opt
set_top synthesize
add_files conv.cpp
add_files -tb main.cpp
open_solution "solution7_testing"
set_part {xc7vx485tffg1761-2}
create_clock -period 10 -name default
source "./Alexnet_io_n_memory_opt/solution7_testing/directives.tcl"
csim_design -clean
csynth_design
cosim_design
export_design -format ip_catalog
