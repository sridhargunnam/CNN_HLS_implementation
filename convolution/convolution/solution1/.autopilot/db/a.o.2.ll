; ModuleID = 'D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

@conv.str = internal unnamed_addr constant [5 x i8] c"conv\00" ; [#uses=1 type=[5 x i8]*]

; [#uses=5]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

; [#uses=0]
define void @conv([11 x [11 x i32]]* nocapture %a, [11 x [11 x i32]]* nocapture %b, i32 %c) nounwind readonly {
  call void (...)* @_ssdm_op_SpecBitsMap([11 x [11 x i32]]* %a) nounwind, !map !24
  call void (...)* @_ssdm_op_SpecBitsMap([11 x [11 x i32]]* %b) nounwind, !map !30
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %c) nounwind, !map !34
  call void (...)* @_ssdm_op_SpecTopModule([5 x i8]* @conv.str) nounwind
  %temp = alloca [11 x i32], align 4              ; [#uses=1 type=[11 x i32]*]
  call void @llvm.dbg.value(metadata !{[11 x [11 x i32]]* %a}, i64 0, metadata !40), !dbg !43 ; [debug line = 2:18] [debug variable = a]
  call void @llvm.dbg.value(metadata !{[11 x [11 x i32]]* %b}, i64 0, metadata !44), !dbg !45 ; [debug line = 2:36] [debug variable = b]
  call void @llvm.dbg.value(metadata !{i32 %c}, i64 0, metadata !46), !dbg !47 ; [debug line = 2:54] [debug variable = c]
  call void @llvm.dbg.declare(metadata !{[11 x i32]* %temp}, metadata !48), !dbg !50 ; [debug line = 6:9] [debug variable = temp]
  br label %1, !dbg !51                           ; [debug line = 7:6]

; <label>:1                                       ; preds = %7, %0
  %i = phi i4 [ 0, %0 ], [ %i.1, %7 ]             ; [#uses=3 type=i4]
  %i.cast2 = zext i4 %i to i32, !dbg !51          ; [#uses=3 type=i32] [debug line = 7:6]
  %exitcond2 = icmp eq i4 %i, -5, !dbg !51        ; [#uses=1 type=i1] [debug line = 7:6]
  %2 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind ; [#uses=0 type=i32]
  br i1 %exitcond2, label %.preheader.preheader_ifconv, label %3, !dbg !51 ; [debug line = 7:6]

.preheader.preheader_ifconv:                      ; preds = %1
  ret void, !dbg !53                              ; [debug line = 21:1]

; <label>:3                                       ; preds = %1
  %temp.addr = getelementptr inbounds [11 x i32]* %temp, i32 0, i32 %i.cast2, !dbg !54 ; [#uses=3 type=i32*] [debug line = 9:3]
  store i32 0, i32* %temp.addr, align 4, !dbg !54 ; [debug line = 9:3]
  br label %4, !dbg !56                           ; [debug line = 10:7]

; <label>:4                                       ; preds = %6, %3
  %j = phi i4 [ 0, %3 ], [ %j.1, %6 ]             ; [#uses=3 type=i4]
  %j.cast1 = zext i4 %j to i32, !dbg !56          ; [#uses=2 type=i32] [debug line = 10:7]
  %exitcond1 = icmp eq i4 %j, -5, !dbg !56        ; [#uses=1 type=i1] [debug line = 10:7]
  %5 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind ; [#uses=0 type=i32]
  br i1 %exitcond1, label %7, label %6, !dbg !56  ; [debug line = 10:7]

; <label>:6                                       ; preds = %4
  %temp.load = load i32* %temp.addr, align 4, !dbg !58 ; [#uses=1 type=i32] [debug line = 12:4]
  %a.addr = getelementptr [11 x [11 x i32]]* %a, i32 0, i32 %i.cast2, i32 %j.cast1, !dbg !58 ; [#uses=1 type=i32*] [debug line = 12:4]
  %a.load = load i32* %a.addr, align 4, !dbg !58  ; [#uses=1 type=i32] [debug line = 12:4]
  %b.addr = getelementptr [11 x [11 x i32]]* %b, i32 0, i32 %i.cast2, i32 %j.cast1, !dbg !58 ; [#uses=1 type=i32*] [debug line = 12:4]
  %b.load = load i32* %b.addr, align 4, !dbg !58  ; [#uses=1 type=i32] [debug line = 12:4]
  %tmp = mul nsw i32 %a.load, %b.load, !dbg !58   ; [#uses=1 type=i32] [debug line = 12:4]
  %tmp.1 = add nsw i32 %tmp, %temp.load, !dbg !58 ; [#uses=1 type=i32] [debug line = 12:4]
  store i32 %tmp.1, i32* %temp.addr, align 4, !dbg !58 ; [debug line = 12:4]
  %j.1 = add i4 %j, 1, !dbg !60                   ; [#uses=1 type=i4] [debug line = 10:18]
  call void @llvm.dbg.value(metadata !{i4 %j.1}, i64 0, metadata !61), !dbg !60 ; [debug line = 10:18] [debug variable = j]
  br label %4, !dbg !60                           ; [debug line = 10:18]

; <label>:7                                       ; preds = %4
  %i.1 = add i4 %i, 1, !dbg !62                   ; [#uses=1 type=i4] [debug line = 7:17]
  call void @llvm.dbg.value(metadata !{i4 %i.1}, i64 0, metadata !63), !dbg !62 ; [debug line = 7:17] [debug variable = i]
  br label %1, !dbg !62                           ; [debug line = 7:17]
}

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=2]
declare i32 @_ssdm_op_SpecLoopTripCount(...)

; [#uses=3]
declare void @_ssdm_op_SpecBitsMap(...)

!llvm.dbg.cu = !{!0}
!opencl.kernels = !{!17}
!hls.encrypted.func = !{}
!llvm.map.gv = !{}

!0 = metadata !{i32 786449, i32 0, i32 4, metadata !"D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/conv.pragma.2.cpp", metadata !"D:\5Cvenky\5Cworkdir\5Cdesigns\5Cconvolution", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !1} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"conv", metadata !"conv", metadata !"_Z4convPA11_iS0_i", metadata !6, i32 2, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !15, i32 3} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"conv.cpp", metadata !"D:\5Cvenky\5Cworkdir\5Cdesigns\5Cconvolution", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{null, metadata !9, metadata !9, metadata !11}
!9 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 32, i64 32, i64 0, i32 0, metadata !10} ; [ DW_TAG_pointer_type ]
!10 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 352, i64 32, i32 0, i32 0, metadata !11, metadata !13, i32 0, i32 0} ; [ DW_TAG_array_type ]
!11 = metadata !{i32 786454, null, metadata !"data_t", metadata !6, i32 4, i64 0, i64 0, i64 0, i32 0, metadata !12} ; [ DW_TAG_typedef ]
!12 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!13 = metadata !{metadata !14}
!14 = metadata !{i32 786465, i64 0, i64 10}       ; [ DW_TAG_subrange_type ]
!15 = metadata !{metadata !16}
!16 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!17 = metadata !{null, metadata !18, metadata !19, metadata !20, metadata !21, metadata !22, metadata !23}
!18 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1, i32 0}
!19 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none"}
!20 = metadata !{metadata !"kernel_arg_type", metadata !"data_t [11]*", metadata !"data_t [11]*", metadata !"data_t"}
!21 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !""}
!22 = metadata !{metadata !"kernel_arg_name", metadata !"a", metadata !"b", metadata !"c"}
!23 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!24 = metadata !{metadata !25}
!25 = metadata !{i32 0, i32 31, metadata !26}
!26 = metadata !{metadata !27}
!27 = metadata !{metadata !"a", metadata !28, metadata !"int", i32 0, i32 31}
!28 = metadata !{metadata !29, metadata !29}
!29 = metadata !{i32 0, i32 10, i32 1}
!30 = metadata !{metadata !31}
!31 = metadata !{i32 0, i32 31, metadata !32}
!32 = metadata !{metadata !33}
!33 = metadata !{metadata !"b", metadata !28, metadata !"int", i32 0, i32 31}
!34 = metadata !{metadata !35}
!35 = metadata !{i32 0, i32 31, metadata !36}
!36 = metadata !{metadata !37}
!37 = metadata !{metadata !"c", metadata !38, metadata !"int", i32 0, i32 31}
!38 = metadata !{metadata !39}
!39 = metadata !{i32 0, i32 0, i32 0}
!40 = metadata !{i32 786689, metadata !5, metadata !"a", null, i32 2, metadata !41, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!41 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 3872, i64 32, i32 0, i32 0, metadata !11, metadata !42, i32 0, i32 0} ; [ DW_TAG_array_type ]
!42 = metadata !{metadata !14, metadata !14}
!43 = metadata !{i32 2, i32 18, metadata !5, null}
!44 = metadata !{i32 786689, metadata !5, metadata !"b", null, i32 2, metadata !41, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!45 = metadata !{i32 2, i32 36, metadata !5, null}
!46 = metadata !{i32 786689, metadata !5, metadata !"c", metadata !6, i32 50331650, metadata !11, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!47 = metadata !{i32 2, i32 54, metadata !5, null}
!48 = metadata !{i32 786688, metadata !49, metadata !"temp", metadata !6, i32 6, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!49 = metadata !{i32 786443, metadata !5, i32 3, i32 1, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!50 = metadata !{i32 6, i32 9, metadata !49, null}
!51 = metadata !{i32 7, i32 6, metadata !52, null}
!52 = metadata !{i32 786443, metadata !49, i32 7, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!53 = metadata !{i32 21, i32 1, metadata !49, null}
!54 = metadata !{i32 9, i32 3, metadata !55, null}
!55 = metadata !{i32 786443, metadata !52, i32 8, i32 2, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!56 = metadata !{i32 10, i32 7, metadata !57, null}
!57 = metadata !{i32 786443, metadata !55, i32 10, i32 3, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!58 = metadata !{i32 12, i32 4, metadata !59, null}
!59 = metadata !{i32 786443, metadata !57, i32 11, i32 3, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!60 = metadata !{i32 10, i32 18, metadata !57, null}
!61 = metadata !{i32 786688, metadata !49, metadata !"j", metadata !6, i32 5, metadata !11, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!62 = metadata !{i32 7, i32 17, metadata !52, null}
!63 = metadata !{i32 786688, metadata !49, metadata !"i", metadata !6, i32 5, metadata !11, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
