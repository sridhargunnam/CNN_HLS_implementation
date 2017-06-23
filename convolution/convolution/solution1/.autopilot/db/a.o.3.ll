; ModuleID = 'D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/a.o.3.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

@conv_str = internal unnamed_addr constant [5 x i8] c"conv\00" ; [#uses=1 type=[5 x i8]*]

; [#uses=6]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

; [#uses=0]
define void @conv([121 x i32]* %a, [121 x i32]* %b, i32* %c) nounwind {
  %sum = alloca i32                               ; [#uses=4 type=i32*]
  call void @llvm.dbg.declare(metadata !{i32* %sum}, metadata !13) ; [debug variable = sum]
  call void (...)* @_ssdm_op_SpecBitsMap([121 x i32]* %a) nounwind, !map !28
  call void (...)* @_ssdm_op_SpecBitsMap([121 x i32]* %b) nounwind, !map !34
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %c) nounwind, !map !38
  call void (...)* @_ssdm_op_SpecTopModule([5 x i8]* @conv_str) nounwind
  call void @llvm.dbg.value(metadata !{[121 x i32]* %a}, i64 0, metadata !44), !dbg !45 ; [debug line = 3:20] [debug variable = a]
  call void @llvm.dbg.value(metadata !{[121 x i32]* %b}, i64 0, metadata !46), !dbg !47 ; [debug line = 3:41] [debug variable = b]
  call void @llvm.dbg.value(metadata !{i32* %c}, i64 0, metadata !48), !dbg !49 ; [debug line = 3:61] [debug variable = c]
  store i32 0, i32* %sum
  br label %.loopexit, !dbg !50                   ; [debug line = 7:13]

.loopexit.loopexit:                               ; preds = %.preheader
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %0
  %i = phi i4 [ 0, %0 ], [ %i_1, %.loopexit.loopexit ] ; [#uses=2 type=i4]
  %phi_mul = phi i7 [ 0, %0 ], [ %next_mul, %.loopexit.loopexit ] ; [#uses=2 type=i7]
  %next_mul = add i7 %phi_mul, 11                 ; [#uses=1 type=i7]
  %exitcond1 = icmp eq i4 %i, -5, !dbg !50        ; [#uses=1 type=i1] [debug line = 7:13]
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind ; [#uses=0 type=i32]
  %i_1 = add i4 %i, 1, !dbg !52                   ; [#uses=1 type=i4] [debug line = 7:21]
  call void @llvm.dbg.value(metadata !{i4 %i_1}, i64 0, metadata !53), !dbg !52 ; [debug line = 7:21] [debug variable = i]
  br i1 %exitcond1, label %2, label %.preheader.preheader, !dbg !50 ; [debug line = 7:13]

.preheader.preheader:                             ; preds = %.loopexit
  br label %.preheader, !dbg !54                  ; [debug line = 13:4]

.preheader:                                       ; preds = %1, %.preheader.preheader
  %j = phi i4 [ %j_1, %1 ], [ 0, %.preheader.preheader ] ; [#uses=3 type=i4]
  %j_cast1_cast = zext i4 %j to i7, !dbg !54      ; [#uses=1 type=i7] [debug line = 13:4]
  %tmp_2 = add i7 %phi_mul, %j_cast1_cast, !dbg !54 ; [#uses=1 type=i7] [debug line = 13:4]
  %tmp_2_cast = zext i7 %tmp_2 to i32, !dbg !54   ; [#uses=2 type=i32] [debug line = 13:4]
  %a_addr = getelementptr [121 x i32]* %a, i32 0, i32 %tmp_2_cast, !dbg !54 ; [#uses=1 type=i32*] [debug line = 13:4]
  %b_addr = getelementptr [121 x i32]* %b, i32 0, i32 %tmp_2_cast, !dbg !54 ; [#uses=1 type=i32*] [debug line = 13:4]
  %exitcond = icmp eq i4 %j, -5, !dbg !58         ; [#uses=1 type=i1] [debug line = 10:14]
  %empty_3 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind ; [#uses=0 type=i32]
  %j_1 = add i4 %j, 1, !dbg !59                   ; [#uses=1 type=i4] [debug line = 10:22]
  br i1 %exitcond, label %.loopexit.loopexit, label %1, !dbg !58 ; [debug line = 10:14]

; <label>:1                                       ; preds = %.preheader
  %sum_load_1 = load i32* %sum, !dbg !54          ; [#uses=1 type=i32] [debug line = 13:4]
  %a_load = load i32* %a_addr, align 4, !dbg !54  ; [#uses=1 type=i32] [debug line = 13:4]
  %b_load = load i32* %b_addr, align 4, !dbg !54  ; [#uses=1 type=i32] [debug line = 13:4]
  %tmp = mul nsw i32 %b_load, %a_load, !dbg !54   ; [#uses=1 type=i32] [debug line = 13:4]
  %sum_1 = add nsw i32 %tmp, %sum_load_1, !dbg !54 ; [#uses=1 type=i32] [debug line = 13:4]
  call void @llvm.dbg.value(metadata !{i32 %sum_1}, i64 0, metadata !13), !dbg !54 ; [debug line = 13:4] [debug variable = sum]
  call void @llvm.dbg.value(metadata !{i4 %j_1}, i64 0, metadata !60), !dbg !59 ; [debug line = 10:22] [debug variable = j]
  store i32 %sum_1, i32* %sum, !dbg !54           ; [debug line = 13:4]
  br label %.preheader, !dbg !59                  ; [debug line = 10:22]

; <label>:2                                       ; preds = %.loopexit
  %sum_load = load i32* %sum, !dbg !61            ; [#uses=1 type=i32] [debug line = 23:2]
  call void @_ssdm_op_Write.ap_auto.i32P(i32* %c, i32 %sum_load) nounwind, !dbg !61 ; [debug line = 23:2]
  ret void, !dbg !62                              ; [debug line = 24:1]
}

; [#uses=1]
define weak void @_ssdm_op_Write.ap_auto.i32P(i32*, i32) {
entry:
  store i32 %1, i32* %0
  ret void
}

; [#uses=1]
define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

; [#uses=2]
define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
}

; [#uses=3]
define weak void @_ssdm_op_SpecBitsMap(...) {
entry:
  ret void
}

!opencl.kernels = !{!0, !7}
!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{null, metadata !1, metadata !2, metadata !3, metadata !4, metadata !5, metadata !6}
!1 = metadata !{metadata !"kernel_arg_addr_space", i32 0, i32 0, i32 1}
!2 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none"}
!3 = metadata !{metadata !"kernel_arg_type", metadata !"data_t (&)[11][11]", metadata !"data_t (&)[11][11]", metadata !"data_t*"}
!4 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !""}
!5 = metadata !{metadata !"kernel_arg_name", metadata !"a", metadata !"b", metadata !"c"}
!6 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!7 = metadata !{null, metadata !8, metadata !9, metadata !10, metadata !11, metadata !12, metadata !6}
!8 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1, i32 1, i32 1}
!9 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none", metadata !"none"}
!10 = metadata !{metadata !"kernel_arg_type", metadata !"data_t [227][3]*", metadata !"data_t [11][3][96]*", metadata !"data_t*", metadata !"data_t [55][96]*"}
!11 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !"", metadata !""}
!12 = metadata !{metadata !"kernel_arg_name", metadata !"image", metadata !"convKernels1", metadata !"bias1", metadata !"FMap1"}
!13 = metadata !{i32 786688, metadata !14, metadata !"sum", metadata !16, i32 5, metadata !21, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!14 = metadata !{i32 786443, metadata !15, i32 4, i32 1, metadata !16, i32 0} ; [ DW_TAG_lexical_block ]
!15 = metadata !{i32 786478, i32 0, metadata !16, metadata !"conv", metadata !"conv", metadata !"_Z4convRA11_A11_iS1_Pi", metadata !16, i32 3, metadata !17, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !26, i32 4} ; [ DW_TAG_subprogram ]
!16 = metadata !{i32 786473, metadata !"conv.cpp", metadata !"D:\5Cvenky\5Cworkdir\5Cdesigns\5Cconvolution", null} ; [ DW_TAG_file_type ]
!17 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !18, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!18 = metadata !{null, metadata !19, metadata !19, metadata !25}
!19 = metadata !{i32 786448, null, null, null, i32 0, i64 0, i64 0, i64 0, i32 0, metadata !20} ; [ DW_TAG_reference_type ]
!20 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 3872, i64 32, i32 0, i32 0, metadata !21, metadata !23, i32 0, i32 0} ; [ DW_TAG_array_type ]
!21 = metadata !{i32 786454, null, metadata !"data_t", metadata !16, i32 1, i64 0, i64 0, i64 0, i32 0, metadata !22} ; [ DW_TAG_typedef ]
!22 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!23 = metadata !{metadata !24, metadata !24}
!24 = metadata !{i32 786465, i64 0, i64 10}       ; [ DW_TAG_subrange_type ]
!25 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !21} ; [ DW_TAG_pointer_type ]
!26 = metadata !{metadata !27}
!27 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!28 = metadata !{metadata !29}
!29 = metadata !{i32 0, i32 31, metadata !30}
!30 = metadata !{metadata !31}
!31 = metadata !{metadata !"a", metadata !32, metadata !"int", i32 0, i32 31}
!32 = metadata !{metadata !33, metadata !33}
!33 = metadata !{i32 0, i32 10, i32 1}
!34 = metadata !{metadata !35}
!35 = metadata !{i32 0, i32 31, metadata !36}
!36 = metadata !{metadata !37}
!37 = metadata !{metadata !"b", metadata !32, metadata !"int", i32 0, i32 31}
!38 = metadata !{metadata !39}
!39 = metadata !{i32 0, i32 31, metadata !40}
!40 = metadata !{metadata !41}
!41 = metadata !{metadata !"c", metadata !42, metadata !"int", i32 0, i32 31}
!42 = metadata !{metadata !43}
!43 = metadata !{i32 0, i32 0, i32 1}
!44 = metadata !{i32 786689, metadata !15, metadata !"a", metadata !16, i32 16777219, metadata !19, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!45 = metadata !{i32 3, i32 20, metadata !15, null}
!46 = metadata !{i32 786689, metadata !15, metadata !"b", metadata !16, i32 33554435, metadata !19, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!47 = metadata !{i32 3, i32 41, metadata !15, null}
!48 = metadata !{i32 786689, metadata !15, metadata !"c", metadata !16, i32 50331651, metadata !25, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!49 = metadata !{i32 3, i32 61, metadata !15, null}
!50 = metadata !{i32 7, i32 13, metadata !51, null}
!51 = metadata !{i32 786443, metadata !14, i32 7, i32 2, metadata !16, i32 1} ; [ DW_TAG_lexical_block ]
!52 = metadata !{i32 7, i32 21, metadata !51, null}
!53 = metadata !{i32 786688, metadata !51, metadata !"i", metadata !16, i32 7, metadata !22, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!54 = metadata !{i32 13, i32 4, metadata !55, null}
!55 = metadata !{i32 786443, metadata !56, i32 11, i32 3, metadata !16, i32 4} ; [ DW_TAG_lexical_block ]
!56 = metadata !{i32 786443, metadata !57, i32 10, i32 3, metadata !16, i32 3} ; [ DW_TAG_lexical_block ]
!57 = metadata !{i32 786443, metadata !51, i32 8, i32 2, metadata !16, i32 2} ; [ DW_TAG_lexical_block ]
!58 = metadata !{i32 10, i32 14, metadata !56, null}
!59 = metadata !{i32 10, i32 22, metadata !56, null}
!60 = metadata !{i32 786688, metadata !56, metadata !"j", metadata !16, i32 10, metadata !22, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!61 = metadata !{i32 23, i32 2, metadata !14, null}
!62 = metadata !{i32 24, i32 1, metadata !14, null}
