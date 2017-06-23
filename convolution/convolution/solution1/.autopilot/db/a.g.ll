; ModuleID = 'D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/a.g.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

; [#uses=0]
define void @_Z4convRA11_A11_iS1_Pi([11 x [11 x i32]]* %a, [11 x [11 x i32]]* %b, i32* %c) nounwind {
  %1 = alloca [11 x [11 x i32]]*, align 4         ; [#uses=2 type=[11 x [11 x i32]]**]
  %2 = alloca [11 x [11 x i32]]*, align 4         ; [#uses=2 type=[11 x [11 x i32]]**]
  %3 = alloca i32*, align 4                       ; [#uses=2 type=i32**]
  %sum = alloca i32, align 4                      ; [#uses=4 type=i32*]
  %temp = alloca [11 x i32], align 4              ; [#uses=0 type=[11 x i32]*]
  %i = alloca i32, align 4                        ; [#uses=6 type=i32*]
  %j = alloca i32, align 4                        ; [#uses=6 type=i32*]
  store [11 x [11 x i32]]* %a, [11 x [11 x i32]]** %1, align 4
  call void @llvm.dbg.declare(metadata !{[11 x [11 x i32]]** %1}, metadata !47), !dbg !48 ; [debug line = 3:20] [debug variable = a]
  store [11 x [11 x i32]]* %b, [11 x [11 x i32]]** %2, align 4
  call void @llvm.dbg.declare(metadata !{[11 x [11 x i32]]** %2}, metadata !49), !dbg !50 ; [debug line = 3:41] [debug variable = b]
  store i32* %c, i32** %3, align 4
  call void @llvm.dbg.declare(metadata !{i32** %3}, metadata !51), !dbg !52 ; [debug line = 3:61] [debug variable = c]
  call void @llvm.dbg.declare(metadata !{i32* %sum}, metadata !53), !dbg !55 ; [debug line = 5:9] [debug variable = sum]
  store i32 0, i32* %sum, align 4, !dbg !56       ; [debug line = 5:16]
  call void @llvm.dbg.declare(metadata !{[11 x i32]* %temp}, metadata !57), !dbg !60 ; [debug line = 6:9] [debug variable = temp]
  call void @llvm.dbg.declare(metadata !{i32* %i}, metadata !61), !dbg !63 ; [debug line = 7:10] [debug variable = i]
  store i32 0, i32* %i, align 4, !dbg !64         ; [debug line = 7:13]
  br label %4, !dbg !64                           ; [debug line = 7:13]

; <label>:4                                       ; preds = %31, %0
  %5 = load i32* %i, align 4, !dbg !64            ; [#uses=1 type=i32] [debug line = 7:13]
  %6 = icmp slt i32 %5, 11, !dbg !64              ; [#uses=1 type=i1] [debug line = 7:13]
  br i1 %6, label %7, label %34, !dbg !64         ; [debug line = 7:13]

; <label>:7                                       ; preds = %4
  call void @llvm.dbg.declare(metadata !{i32* %j}, metadata !65), !dbg !68 ; [debug line = 10:11] [debug variable = j]
  store i32 0, i32* %j, align 4, !dbg !69         ; [debug line = 10:14]
  br label %8, !dbg !69                           ; [debug line = 10:14]

; <label>:8                                       ; preds = %27, %7
  %9 = load i32* %j, align 4, !dbg !69            ; [#uses=1 type=i32] [debug line = 10:14]
  %10 = icmp slt i32 %9, 11, !dbg !69             ; [#uses=1 type=i1] [debug line = 10:14]
  br i1 %10, label %11, label %30, !dbg !69       ; [debug line = 10:14]

; <label>:11                                      ; preds = %8
  %12 = load i32* %j, align 4, !dbg !70           ; [#uses=1 type=i32] [debug line = 13:4]
  %13 = load i32* %i, align 4, !dbg !70           ; [#uses=1 type=i32] [debug line = 13:4]
  %14 = load [11 x [11 x i32]]** %1, align 4, !dbg !70 ; [#uses=1 type=[11 x [11 x i32]]*] [debug line = 13:4]
  %15 = getelementptr inbounds [11 x [11 x i32]]* %14, i32 0, i32 %13, !dbg !70 ; [#uses=1 type=[11 x i32]*] [debug line = 13:4]
  %16 = getelementptr inbounds [11 x i32]* %15, i32 0, i32 %12, !dbg !70 ; [#uses=1 type=i32*] [debug line = 13:4]
  %17 = load i32* %16, align 4, !dbg !70          ; [#uses=1 type=i32] [debug line = 13:4]
  %18 = load i32* %j, align 4, !dbg !70           ; [#uses=1 type=i32] [debug line = 13:4]
  %19 = load i32* %i, align 4, !dbg !70           ; [#uses=1 type=i32] [debug line = 13:4]
  %20 = load [11 x [11 x i32]]** %2, align 4, !dbg !70 ; [#uses=1 type=[11 x [11 x i32]]*] [debug line = 13:4]
  %21 = getelementptr inbounds [11 x [11 x i32]]* %20, i32 0, i32 %19, !dbg !70 ; [#uses=1 type=[11 x i32]*] [debug line = 13:4]
  %22 = getelementptr inbounds [11 x i32]* %21, i32 0, i32 %18, !dbg !70 ; [#uses=1 type=i32*] [debug line = 13:4]
  %23 = load i32* %22, align 4, !dbg !70          ; [#uses=1 type=i32] [debug line = 13:4]
  %24 = mul nsw i32 %17, %23, !dbg !70            ; [#uses=1 type=i32] [debug line = 13:4]
  %25 = load i32* %sum, align 4, !dbg !70         ; [#uses=1 type=i32] [debug line = 13:4]
  %26 = add nsw i32 %25, %24, !dbg !70            ; [#uses=1 type=i32] [debug line = 13:4]
  store i32 %26, i32* %sum, align 4, !dbg !70     ; [debug line = 13:4]
  br label %27, !dbg !72                          ; [debug line = 15:3]

; <label>:27                                      ; preds = %11
  %28 = load i32* %j, align 4, !dbg !73           ; [#uses=1 type=i32] [debug line = 10:22]
  %29 = add nsw i32 %28, 1, !dbg !73              ; [#uses=1 type=i32] [debug line = 10:22]
  store i32 %29, i32* %j, align 4, !dbg !73       ; [debug line = 10:22]
  br label %8, !dbg !73                           ; [debug line = 10:22]

; <label>:30                                      ; preds = %8
  br label %31, !dbg !74                          ; [debug line = 16:2]

; <label>:31                                      ; preds = %30
  %32 = load i32* %i, align 4, !dbg !75           ; [#uses=1 type=i32] [debug line = 7:21]
  %33 = add nsw i32 %32, 1, !dbg !75              ; [#uses=1 type=i32] [debug line = 7:21]
  store i32 %33, i32* %i, align 4, !dbg !75       ; [debug line = 7:21]
  br label %4, !dbg !75                           ; [debug line = 7:21]

; <label>:34                                      ; preds = %4
  %35 = load i32* %sum, align 4, !dbg !76         ; [#uses=1 type=i32] [debug line = 23:2]
  %36 = load i32** %3, align 4, !dbg !76          ; [#uses=1 type=i32*] [debug line = 23:2]
  store i32 %35, i32* %36, align 4, !dbg !76      ; [debug line = 23:2]
  ret void, !dbg !77                              ; [debug line = 24:1]
}

; [#uses=11]
declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

; [#uses=0]
define void @_Z11conv_layer1PA227_A3_iPA11_A3_A96_iPiPA55_S2_([227 x [3 x i32]]* %image, [11 x [3 x [96 x i32]]]* %convKernels1, i32* %bias1, [55 x [96 x i32]]* %FMap1) nounwind {
  %1 = alloca [227 x [3 x i32]]*, align 4         ; [#uses=2 type=[227 x [3 x i32]]**]
  %2 = alloca [11 x [3 x [96 x i32]]]*, align 4   ; [#uses=2 type=[11 x [3 x [96 x i32]]]**]
  %3 = alloca i32*, align 4                       ; [#uses=2 type=i32**]
  %4 = alloca [55 x [96 x i32]]*, align 4         ; [#uses=2 type=[55 x [96 x i32]]**]
  store [227 x [3 x i32]]* %image, [227 x [3 x i32]]** %1, align 4
  call void @llvm.dbg.declare(metadata !{[227 x [3 x i32]]** %1}, metadata !78), !dbg !79 ; [debug line = 29:25] [debug variable = image]
  store [11 x [3 x [96 x i32]]]* %convKernels1, [11 x [3 x [96 x i32]]]** %2, align 4
  call void @llvm.dbg.declare(metadata !{[11 x [3 x [96 x i32]]]** %2}, metadata !80), !dbg !81 ; [debug line = 29:52] [debug variable = convKernels1]
  store i32* %bias1, i32** %3, align 4
  call void @llvm.dbg.declare(metadata !{i32** %3}, metadata !82), !dbg !83 ; [debug line = 29:87] [debug variable = bias1]
  store [55 x [96 x i32]]* %FMap1, [55 x [96 x i32]]** %4, align 4
  call void @llvm.dbg.declare(metadata !{[55 x [96 x i32]]** %4}, metadata !84), !dbg !85 ; [debug line = 29:105] [debug variable = FMap1]
  %5 = load [227 x [3 x i32]]** %1, align 4, !dbg !86 ; [#uses=1 type=[227 x [3 x i32]]*] [debug line = 30:2]
  call void (...)* @_ssdm_SpecArrayDimSize([227 x [3 x i32]]* %5, i32 227) nounwind, !dbg !86 ; [debug line = 30:2]
  %6 = load [55 x [96 x i32]]** %4, align 4, !dbg !88 ; [#uses=1 type=[55 x [96 x i32]]*] [debug line = 30:36]
  call void (...)* @_ssdm_SpecArrayDimSize([55 x [96 x i32]]* %6, i32 55) nounwind, !dbg !88 ; [debug line = 30:36]
  %7 = load [11 x [3 x [96 x i32]]]** %2, align 4, !dbg !89 ; [#uses=1 type=[11 x [3 x [96 x i32]]]*] [debug line = 30:69]
  call void (...)* @_ssdm_SpecArrayDimSize([11 x [3 x [96 x i32]]]* %7, i32 11) nounwind, !dbg !89 ; [debug line = 30:69]
  %8 = load i32** %3, align 4, !dbg !90           ; [#uses=1 type=i32*] [debug line = 30:109]
  call void (...)* @_ssdm_SpecArrayDimSize(i32* %8, i32 96) nounwind, !dbg !90 ; [debug line = 30:109]
  ret void, !dbg !91                              ; [debug line = 33:1]
}

; [#uses=4]
declare void @_ssdm_SpecArrayDimSize(...) nounwind

!llvm.dbg.cu = !{!0}
!opencl.kernels = !{!34, !41}
!hls.encrypted.func = !{}

!0 = metadata !{i32 786449, i32 0, i32 4, metadata !"D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/conv.pragma.2.cpp", metadata !"D:\5Cvenky\5Cworkdir\5Cdesigns\5Cconvolution", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !1} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5, metadata !18}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"conv", metadata !"conv", metadata !"_Z4convRA11_A11_iS1_Pi", metadata !6, i32 3, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void ([11 x [11 x i32]]*, [11 x [11 x i32]]*, i32*)* @_Z4convRA11_A11_iS1_Pi, null, null, metadata !16, i32 4} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"conv.cpp", metadata !"D:\5Cvenky\5Cworkdir\5Cdesigns\5Cconvolution", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{null, metadata !9, metadata !9, metadata !15}
!9 = metadata !{i32 786448, null, null, null, i32 0, i64 0, i64 0, i64 0, i32 0, metadata !10} ; [ DW_TAG_reference_type ]
!10 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 3872, i64 32, i32 0, i32 0, metadata !11, metadata !13, i32 0, i32 0} ; [ DW_TAG_array_type ]
!11 = metadata !{i32 786454, null, metadata !"data_t", metadata !6, i32 1, i64 0, i64 0, i64 0, i32 0, metadata !12} ; [ DW_TAG_typedef ]
!12 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!13 = metadata !{metadata !14, metadata !14}
!14 = metadata !{i32 786465, i64 0, i64 10}       ; [ DW_TAG_subrange_type ]
!15 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !11} ; [ DW_TAG_pointer_type ]
!16 = metadata !{metadata !17}
!17 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!18 = metadata !{i32 786478, i32 0, metadata !6, metadata !"conv_layer1", metadata !"conv_layer1", metadata !"_Z11conv_layer1PA227_A3_iPA11_A3_A96_iPiPA55_S2_", metadata !6, i32 29, metadata !19, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void ([227 x [3 x i32]]*, [11 x [3 x [96 x i32]]]*, i32*, [55 x [96 x i32]]*)* @_Z11conv_layer1PA227_A3_iPA11_A3_A96_iPiPA55_S2_, null, null, metadata !16, i32 30} ; [ DW_TAG_subprogram ]
!19 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !20, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!20 = metadata !{null, metadata !21, metadata !26, metadata !15, metadata !30}
!21 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !22} ; [ DW_TAG_pointer_type ]
!22 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 21792, i64 32, i32 0, i32 0, metadata !11, metadata !23, i32 0, i32 0} ; [ DW_TAG_array_type ]
!23 = metadata !{metadata !24, metadata !25}
!24 = metadata !{i32 786465, i64 0, i64 226}      ; [ DW_TAG_subrange_type ]
!25 = metadata !{i32 786465, i64 0, i64 2}        ; [ DW_TAG_subrange_type ]
!26 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !27} ; [ DW_TAG_pointer_type ]
!27 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 101376, i64 32, i32 0, i32 0, metadata !11, metadata !28, i32 0, i32 0} ; [ DW_TAG_array_type ]
!28 = metadata !{metadata !14, metadata !25, metadata !29}
!29 = metadata !{i32 786465, i64 0, i64 95}       ; [ DW_TAG_subrange_type ]
!30 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !31} ; [ DW_TAG_pointer_type ]
!31 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 168960, i64 32, i32 0, i32 0, metadata !11, metadata !32, i32 0, i32 0} ; [ DW_TAG_array_type ]
!32 = metadata !{metadata !33, metadata !29}
!33 = metadata !{i32 786465, i64 0, i64 54}       ; [ DW_TAG_subrange_type ]
!34 = metadata !{void ([11 x [11 x i32]]*, [11 x [11 x i32]]*, i32*)* @_Z4convRA11_A11_iS1_Pi, metadata !35, metadata !36, metadata !37, metadata !38, metadata !39, metadata !40}
!35 = metadata !{metadata !"kernel_arg_addr_space", i32 0, i32 0, i32 1}
!36 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none"}
!37 = metadata !{metadata !"kernel_arg_type", metadata !"data_t (&)[11][11]", metadata !"data_t (&)[11][11]", metadata !"data_t*"}
!38 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !""}
!39 = metadata !{metadata !"kernel_arg_name", metadata !"a", metadata !"b", metadata !"c"}
!40 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!41 = metadata !{void ([227 x [3 x i32]]*, [11 x [3 x [96 x i32]]]*, i32*, [55 x [96 x i32]]*)* @_Z11conv_layer1PA227_A3_iPA11_A3_A96_iPiPA55_S2_, metadata !42, metadata !43, metadata !44, metadata !45, metadata !46, metadata !40}
!42 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1, i32 1, i32 1}
!43 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!44 = metadata !{metadata !"kernel_arg_type", metadata !"data_t [227][3]*", metadata !"data_t [11][3][96]*", metadata !"data_t*", metadata !"data_t [55][96]*"}
!45 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !""}
!46 = metadata !{metadata !"kernel_arg_name", metadata !"image", metadata !"convKernels1", metadata !"bias1", metadata !"FMap1"}
!47 = metadata !{i32 786689, metadata !5, metadata !"a", metadata !6, i32 16777219, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!48 = metadata !{i32 3, i32 20, metadata !5, null}
!49 = metadata !{i32 786689, metadata !5, metadata !"b", metadata !6, i32 33554435, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!50 = metadata !{i32 3, i32 41, metadata !5, null}
!51 = metadata !{i32 786689, metadata !5, metadata !"c", metadata !6, i32 50331651, metadata !15, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!52 = metadata !{i32 3, i32 61, metadata !5, null}
!53 = metadata !{i32 786688, metadata !54, metadata !"sum", metadata !6, i32 5, metadata !11, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!54 = metadata !{i32 786443, metadata !5, i32 4, i32 1, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!55 = metadata !{i32 5, i32 9, metadata !54, null}
!56 = metadata !{i32 5, i32 16, metadata !54, null}
!57 = metadata !{i32 786688, metadata !54, metadata !"temp", metadata !6, i32 6, metadata !58, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!58 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 352, i64 32, i32 0, i32 0, metadata !11, metadata !59, i32 0, i32 0} ; [ DW_TAG_array_type ]
!59 = metadata !{metadata !14}
!60 = metadata !{i32 6, i32 9, metadata !54, null}
!61 = metadata !{i32 786688, metadata !62, metadata !"i", metadata !6, i32 7, metadata !12, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!62 = metadata !{i32 786443, metadata !54, i32 7, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!63 = metadata !{i32 7, i32 10, metadata !62, null}
!64 = metadata !{i32 7, i32 13, metadata !62, null}
!65 = metadata !{i32 786688, metadata !66, metadata !"j", metadata !6, i32 10, metadata !12, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!66 = metadata !{i32 786443, metadata !67, i32 10, i32 3, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!67 = metadata !{i32 786443, metadata !62, i32 8, i32 2, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!68 = metadata !{i32 10, i32 11, metadata !66, null}
!69 = metadata !{i32 10, i32 14, metadata !66, null}
!70 = metadata !{i32 13, i32 4, metadata !71, null}
!71 = metadata !{i32 786443, metadata !66, i32 11, i32 3, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!72 = metadata !{i32 15, i32 3, metadata !71, null}
!73 = metadata !{i32 10, i32 22, metadata !66, null}
!74 = metadata !{i32 16, i32 2, metadata !67, null}
!75 = metadata !{i32 7, i32 21, metadata !62, null}
!76 = metadata !{i32 23, i32 2, metadata !54, null}
!77 = metadata !{i32 24, i32 1, metadata !54, null}
!78 = metadata !{i32 786689, metadata !18, metadata !"image", metadata !6, i32 16777245, metadata !21, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!79 = metadata !{i32 29, i32 25, metadata !18, null}
!80 = metadata !{i32 786689, metadata !18, metadata !"convKernels1", metadata !6, i32 33554461, metadata !26, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!81 = metadata !{i32 29, i32 52, metadata !18, null}
!82 = metadata !{i32 786689, metadata !18, metadata !"bias1", metadata !6, i32 50331677, metadata !15, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!83 = metadata !{i32 29, i32 87, metadata !18, null}
!84 = metadata !{i32 786689, metadata !18, metadata !"FMap1", metadata !6, i32 67108893, metadata !30, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!85 = metadata !{i32 29, i32 105, metadata !18, null}
!86 = metadata !{i32 30, i32 2, metadata !87, null}
!87 = metadata !{i32 786443, metadata !18, i32 30, i32 1, metadata !6, i32 5} ; [ DW_TAG_lexical_block ]
!88 = metadata !{i32 30, i32 36, metadata !87, null}
!89 = metadata !{i32 30, i32 69, metadata !87, null}
!90 = metadata !{i32 30, i32 109, metadata !87, null}
!91 = metadata !{i32 33, i32 1, metadata !87, null}
