; ModuleID = 'D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/a.g.1.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

@conv.str = internal unnamed_addr constant [5 x i8] c"conv\00" ; [#uses=1 type=[5 x i8]*]

; [#uses=6]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

; [#uses=1]
declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

; [#uses=0]
define void @conv([11 x i32]* %a, [11 x i32]* %b, i32 %c) nounwind {
  call void (...)* @_ssdm_op_SpecTopModule([5 x i8]* @conv.str) nounwind
  %temp = alloca [11 x i32], align 4              ; [#uses=2 type=[11 x i32]*]
  call void @llvm.dbg.value(metadata !{[11 x i32]* %a}, i64 0, metadata !24), !dbg !25 ; [debug line = 2:18] [debug variable = a]
  call void @llvm.dbg.value(metadata !{[11 x i32]* %b}, i64 0, metadata !26), !dbg !27 ; [debug line = 2:36] [debug variable = b]
  call void @llvm.dbg.value(metadata !{i32 %c}, i64 0, metadata !28), !dbg !29 ; [debug line = 2:54] [debug variable = c]
  call void (...)* @_ssdm_SpecArrayDimSize([11 x i32]* %a, i32 11) nounwind, !dbg !30 ; [debug line = 3:2]
  call void (...)* @_ssdm_SpecArrayDimSize([11 x i32]* %b, i32 11) nounwind, !dbg !32 ; [debug line = 3:31]
  call void @llvm.dbg.declare(metadata !{[11 x i32]* %temp}, metadata !33), !dbg !34 ; [debug line = 6:9] [debug variable = temp]
  br label %1, !dbg !35                           ; [debug line = 7:6]

; <label>:1                                       ; preds = %5, %0
  %i = phi i32 [ 0, %0 ], [ %i.1, %5 ]            ; [#uses=5 type=i32]
  %exitcond2 = icmp eq i32 %i, 11, !dbg !35       ; [#uses=1 type=i1] [debug line = 7:6]
  br i1 %exitcond2, label %.preheader.preheader, label %2, !dbg !35 ; [debug line = 7:6]

.preheader.preheader:                             ; preds = %1
  br label %.preheader, !dbg !37                  ; [debug line = 16:6]

; <label>:2                                       ; preds = %1
  %temp.addr = getelementptr inbounds [11 x i32]* %temp, i32 0, i32 %i, !dbg !39 ; [#uses=3 type=i32*] [debug line = 9:3]
  store i32 0, i32* %temp.addr, align 4, !dbg !39 ; [debug line = 9:3]
  br label %3, !dbg !41                           ; [debug line = 10:7]

; <label>:3                                       ; preds = %4, %2
  %j = phi i32 [ 0, %2 ], [ %j.3, %4 ]            ; [#uses=4 type=i32]
  %exitcond1 = icmp eq i32 %j, 11, !dbg !41       ; [#uses=1 type=i1] [debug line = 10:7]
  br i1 %exitcond1, label %5, label %4, !dbg !41  ; [debug line = 10:7]

; <label>:4                                       ; preds = %3
  %temp.load.1 = load i32* %temp.addr, align 4, !dbg !43 ; [#uses=2 type=i32] [debug line = 12:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(i32 %temp.load.1) nounwind
  %a.addr = getelementptr inbounds [11 x i32]* %a, i32 %i, i32 %j, !dbg !43 ; [#uses=1 type=i32*] [debug line = 12:4]
  %a.load = load i32* %a.addr, align 4, !dbg !43  ; [#uses=2 type=i32] [debug line = 12:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(i32 %a.load) nounwind
  %b.addr = getelementptr inbounds [11 x i32]* %b, i32 %i, i32 %j, !dbg !43 ; [#uses=1 type=i32*] [debug line = 12:4]
  %b.load = load i32* %b.addr, align 4, !dbg !43  ; [#uses=2 type=i32] [debug line = 12:4]
  call void (...)* @_ssdm_SpecKeepArrayLoad(i32 %b.load) nounwind
  %tmp = mul nsw i32 %b.load, %a.load, !dbg !43   ; [#uses=1 type=i32] [debug line = 12:4]
  %tmp.1 = add nsw i32 %tmp, %temp.load.1, !dbg !43 ; [#uses=1 type=i32] [debug line = 12:4]
  store i32 %tmp.1, i32* %temp.addr, align 4, !dbg !43 ; [debug line = 12:4]
  %j.3 = add nsw i32 %j, 1, !dbg !45              ; [#uses=1 type=i32] [debug line = 10:18]
  call void @llvm.dbg.value(metadata !{i32 %j.3}, i64 0, metadata !46), !dbg !45 ; [debug line = 10:18] [debug variable = j]
  br label %3, !dbg !45                           ; [debug line = 10:18]

; <label>:5                                       ; preds = %3
  %i.1 = add nsw i32 %i, 1, !dbg !47              ; [#uses=1 type=i32] [debug line = 7:17]
  call void @llvm.dbg.value(metadata !{i32 %i.1}, i64 0, metadata !48), !dbg !47 ; [debug line = 7:17] [debug variable = i]
  br label %1, !dbg !47                           ; [debug line = 7:17]

.preheader:                                       ; preds = %6, %.preheader.preheader
  %j.1 = phi i32 [ %j.2, %6 ], [ 0, %.preheader.preheader ] ; [#uses=3 type=i32]
  %exitcond = icmp eq i32 %j.1, 11, !dbg !37      ; [#uses=1 type=i1] [debug line = 16:6]
  br i1 %exitcond, label %7, label %6, !dbg !37   ; [debug line = 16:6]

; <label>:6                                       ; preds = %.preheader
  %temp.addr.1 = getelementptr inbounds [11 x i32]* %temp, i32 0, i32 %j.1, !dbg !49 ; [#uses=1 type=i32*] [debug line = 18:5]
  %temp.load = load i32* %temp.addr.1, align 4, !dbg !49 ; [#uses=1 type=i32] [debug line = 18:5]
  call void (...)* @_ssdm_SpecKeepArrayLoad(i32 %temp.load) nounwind
  %j.2 = add nsw i32 %j.1, 1, !dbg !51            ; [#uses=1 type=i32] [debug line = 16:17]
  call void @llvm.dbg.value(metadata !{i32 %j.2}, i64 0, metadata !46), !dbg !51 ; [debug line = 16:17] [debug variable = j]
  br label %.preheader, !dbg !51                  ; [debug line = 16:17]

; <label>:7                                       ; preds = %.preheader
  ret void, !dbg !52                              ; [debug line = 21:1]
}

; [#uses=1]
declare void @_ssdm_op_SpecTopModule(...)

; [#uses=4]
declare void @_ssdm_SpecKeepArrayLoad(...)

; [#uses=2]
declare void @_ssdm_SpecArrayDimSize(...) nounwind

!llvm.dbg.cu = !{!0}
!opencl.kernels = !{!17}
!hls.encrypted.func = !{}

!0 = metadata !{i32 786449, i32 0, i32 4, metadata !"D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/conv.pragma.2.cpp", metadata !"D:\5Cvenky\5Cworkdir\5Cdesigns\5Cconvolution", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !1} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"conv", metadata !"conv", metadata !"_Z4convPA11_iS0_i", metadata !6, i32 2, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void ([11 x i32]*, [11 x i32]*, i32)* @conv, null, null, metadata !15, i32 3} ; [ DW_TAG_subprogram ]
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
!17 = metadata !{void ([11 x i32]*, [11 x i32]*, i32)* @conv, metadata !18, metadata !19, metadata !20, metadata !21, metadata !22, metadata !23}
!18 = metadata !{metadata !"kernel_arg_addr_space", i32 1, i32 1, i32 0}
!19 = metadata !{metadata !"kernel_arg_access_qual", metadata !"none", metadata !"none", metadata !"none"}
!20 = metadata !{metadata !"kernel_arg_type", metadata !"data_t [11]*", metadata !"data_t [11]*", metadata !"data_t"}
!21 = metadata !{metadata !"kernel_arg_type_qual", metadata !"", metadata !"", metadata !""}
!22 = metadata !{metadata !"kernel_arg_name", metadata !"a", metadata !"b", metadata !"c"}
!23 = metadata !{metadata !"reqd_work_group_size", i32 1, i32 1, i32 1}
!24 = metadata !{i32 786689, metadata !5, metadata !"a", metadata !6, i32 16777218, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!25 = metadata !{i32 2, i32 18, metadata !5, null}
!26 = metadata !{i32 786689, metadata !5, metadata !"b", metadata !6, i32 33554434, metadata !9, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!27 = metadata !{i32 2, i32 36, metadata !5, null}
!28 = metadata !{i32 786689, metadata !5, metadata !"c", metadata !6, i32 50331650, metadata !11, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!29 = metadata !{i32 2, i32 54, metadata !5, null}
!30 = metadata !{i32 3, i32 2, metadata !31, null}
!31 = metadata !{i32 786443, metadata !5, i32 3, i32 1, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!32 = metadata !{i32 3, i32 31, metadata !31, null}
!33 = metadata !{i32 786688, metadata !31, metadata !"temp", metadata !6, i32 6, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!34 = metadata !{i32 6, i32 9, metadata !31, null}
!35 = metadata !{i32 7, i32 6, metadata !36, null}
!36 = metadata !{i32 786443, metadata !31, i32 7, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!37 = metadata !{i32 16, i32 6, metadata !38, null}
!38 = metadata !{i32 786443, metadata !31, i32 16, i32 2, metadata !6, i32 5} ; [ DW_TAG_lexical_block ]
!39 = metadata !{i32 9, i32 3, metadata !40, null}
!40 = metadata !{i32 786443, metadata !36, i32 8, i32 2, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!41 = metadata !{i32 10, i32 7, metadata !42, null}
!42 = metadata !{i32 786443, metadata !40, i32 10, i32 3, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!43 = metadata !{i32 12, i32 4, metadata !44, null}
!44 = metadata !{i32 786443, metadata !42, i32 11, i32 3, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!45 = metadata !{i32 10, i32 18, metadata !42, null}
!46 = metadata !{i32 786688, metadata !31, metadata !"j", metadata !6, i32 5, metadata !11, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!47 = metadata !{i32 7, i32 17, metadata !36, null}
!48 = metadata !{i32 786688, metadata !31, metadata !"i", metadata !6, i32 5, metadata !11, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!49 = metadata !{i32 18, i32 5, metadata !50, null}
!50 = metadata !{i32 786443, metadata !38, i32 17, i32 4, metadata !6, i32 6} ; [ DW_TAG_lexical_block ]
!51 = metadata !{i32 16, i32 17, metadata !38, null}
!52 = metadata !{i32 21, i32 1, metadata !31, null}
