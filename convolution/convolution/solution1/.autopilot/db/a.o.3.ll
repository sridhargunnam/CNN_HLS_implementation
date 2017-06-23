; ModuleID = 'D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/a.o.3.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

@conv_str = internal unnamed_addr constant [5 x i8] c"conv\00" ; [#uses=1 type=[5 x i8]*]

; [#uses=5]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=0]
define void @conv([121 x i32]* nocapture %a, [121 x i32]* nocapture %b, i32 %c) nounwind readonly {
  call void (...)* @_ssdm_op_SpecBitsMap([121 x i32]* %a) nounwind, !map !7
  call void (...)* @_ssdm_op_SpecBitsMap([121 x i32]* %b) nounwind, !map !13
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %c) nounwind, !map !17
  call void (...)* @_ssdm_op_SpecTopModule([5 x i8]* @conv_str) nounwind
  call void @llvm.dbg.value(metadata !{[121 x i32]* %a}, i64 0, metadata !23), !dbg !38 ; [debug line = 2:18] [debug variable = a]
  call void @llvm.dbg.value(metadata !{[121 x i32]* %b}, i64 0, metadata !39), !dbg !40 ; [debug line = 2:36] [debug variable = b]
  call void @llvm.dbg.value(metadata !{i32 %c}, i64 0, metadata !41), !dbg !42 ; [debug line = 2:54] [debug variable = c]
  br label %.loopexit, !dbg !43                   ; [debug line = 7:6]

.loopexit.loopexit:                               ; preds = %.preheader
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %0
  %i = phi i4 [ 0, %0 ], [ %i_1, %.loopexit.loopexit ] ; [#uses=2 type=i4]
  %exitcond2 = icmp eq i4 %i, -5, !dbg !43        ; [#uses=1 type=i1] [debug line = 7:6]
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind ; [#uses=0 type=i32]
  %i_1 = add i4 %i, 1, !dbg !46                   ; [#uses=1 type=i4] [debug line = 7:17]
  call void @llvm.dbg.value(metadata !{i4 %i_1}, i64 0, metadata !47), !dbg !46 ; [debug line = 7:17] [debug variable = i]
  br i1 %exitcond2, label %.preheader.preheader_ifconv, label %.preheader.preheader, !dbg !43 ; [debug line = 7:6]

.preheader.preheader:                             ; preds = %.loopexit
  br label %.preheader, !dbg !48                  ; [debug line = 10:7]

.preheader.preheader_ifconv:                      ; preds = %.loopexit
  ret void, !dbg !51                              ; [debug line = 21:1]

.preheader:                                       ; preds = %.preheader, %.preheader.preheader
  %j = phi i4 [ %j_1, %.preheader ], [ 0, %.preheader.preheader ] ; [#uses=2 type=i4]
  %exitcond1 = icmp eq i4 %j, -5, !dbg !48        ; [#uses=1 type=i1] [debug line = 10:7]
  %empty_2 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind ; [#uses=0 type=i32]
  %j_1 = add i4 %j, 1, !dbg !52                   ; [#uses=1 type=i4] [debug line = 10:18]
  call void @llvm.dbg.value(metadata !{i4 %j_1}, i64 0, metadata !53), !dbg !52 ; [debug line = 10:18] [debug variable = j]
  br i1 %exitcond1, label %.loopexit.loopexit, label %.preheader, !dbg !48 ; [debug line = 10:7]
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

!opencl.kernels = !{!0}
!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{null, metadata !1, metadata !2, metadata !3, metadata !4, metadata !5, metadata !6}
!1 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1, i32 0}
!2 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none"}
!3 = metadata !{metadata !"kernel_arg_type", metadata !"data_t [11]*", metadata !"data_t [11]*", metadata !"data_t"}
!4 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !""}
!5 = metadata !{metadata !"kernel_arg_name", metadata !"a", metadata !"b", metadata !"c"}
!6 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!7 = metadata !{metadata !8}
!8 = metadata !{i32 0, i32 31, metadata !9}
!9 = metadata !{metadata !10}
!10 = metadata !{metadata !"a", metadata !11, metadata !"int", i32 0, i32 31}
!11 = metadata !{metadata !12, metadata !12}
!12 = metadata !{i32 0, i32 10, i32 1}
!13 = metadata !{metadata !14}
!14 = metadata !{i32 0, i32 31, metadata !15}
!15 = metadata !{metadata !16}
!16 = metadata !{metadata !"b", metadata !11, metadata !"int", i32 0, i32 31}
!17 = metadata !{metadata !18}
!18 = metadata !{i32 0, i32 31, metadata !19}
!19 = metadata !{metadata !20}
!20 = metadata !{metadata !"c", metadata !21, metadata !"int", i32 0, i32 31}
!21 = metadata !{metadata !22}
!22 = metadata !{i32 0, i32 0, i32 0}
!23 = metadata !{i32 786689, metadata !24, metadata !"a", null, i32 2, metadata !36, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!24 = metadata !{i32 786478, i32 0, metadata !25, metadata !"conv", metadata !"conv", metadata !"_Z4convPA11_iS0_i", metadata !25, i32 2, metadata !26, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !34, i32 3} ; [ DW_TAG_subprogram ]
!25 = metadata !{i32 786473, metadata !"conv.cpp", metadata !"D:\5Cvenky\5Cworkdir\5Cdesigns\5Cconvolution", null} ; [ DW_TAG_file_type ]
!26 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !27, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!27 = metadata !{null, metadata !28, metadata !28, metadata !30}
!28 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !29} ; [ DW_TAG_pointer_type ]
!29 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 352, i64 32, i32 0, i32 0, metadata !30, metadata !32, i32 0, i32 0} ; [ DW_TAG_array_type ]
!30 = metadata !{i32 786454, null, metadata !"data_t", metadata !25, i32 4, i64 0, i64 0, i64 0, i32 0, metadata !31} ; [ DW_TAG_typedef ]
!31 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!32 = metadata !{metadata !33}
!33 = metadata !{i32 786465, i64 0, i64 10}       ; [ DW_TAG_subrange_type ]
!34 = metadata !{metadata !35}
!35 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!36 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 3872, i64 32, i32 0, i32 0, metadata !30, metadata !37, i32 0, i32 0} ; [ DW_TAG_array_type ]
!37 = metadata !{metadata !33, metadata !33}
!38 = metadata !{i32 2, i32 18, metadata !24, null}
!39 = metadata !{i32 786689, metadata !24, metadata !"b", null, i32 2, metadata !36, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!40 = metadata !{i32 2, i32 36, metadata !24, null}
!41 = metadata !{i32 786689, metadata !24, metadata !"c", metadata !25, i32 50331650, metadata !30, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!42 = metadata !{i32 2, i32 54, metadata !24, null}
!43 = metadata !{i32 7, i32 6, metadata !44, null}
!44 = metadata !{i32 786443, metadata !45, i32 7, i32 2, metadata !25, i32 1} ; [ DW_TAG_lexical_block ]
!45 = metadata !{i32 786443, metadata !24, i32 3, i32 1, metadata !25, i32 0} ; [ DW_TAG_lexical_block ]
!46 = metadata !{i32 7, i32 17, metadata !44, null}
!47 = metadata !{i32 786688, metadata !45, metadata !"i", metadata !25, i32 5, metadata !30, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!48 = metadata !{i32 10, i32 7, metadata !49, null}
!49 = metadata !{i32 786443, metadata !50, i32 10, i32 3, metadata !25, i32 3} ; [ DW_TAG_lexical_block ]
!50 = metadata !{i32 786443, metadata !44, i32 8, i32 2, metadata !25, i32 2} ; [ DW_TAG_lexical_block ]
!51 = metadata !{i32 21, i32 1, metadata !45, null}
!52 = metadata !{i32 10, i32 18, metadata !49, null}
!53 = metadata !{i32 786688, metadata !45, metadata !"j", metadata !25, i32 5, metadata !30, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
