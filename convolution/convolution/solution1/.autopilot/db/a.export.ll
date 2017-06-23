; ModuleID = 'D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

@conv_str = internal unnamed_addr constant [5 x i8] c"conv\00"

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

define void @conv([121 x i32]* nocapture %a, [121 x i32]* nocapture %b, i32 %c) nounwind readonly {
  call void (...)* @_ssdm_op_SpecBitsMap([121 x i32]* %a) nounwind, !map !7
  call void (...)* @_ssdm_op_SpecBitsMap([121 x i32]* %b) nounwind, !map !13
  call void (...)* @_ssdm_op_SpecBitsMap(i32 %c) nounwind, !map !17
  call void (...)* @_ssdm_op_SpecTopModule([5 x i8]* @conv_str) nounwind
  br label %.loopexit

.loopexit.loopexit:                               ; preds = %.preheader
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %0
  %i = phi i4 [ 0, %0 ], [ %i_1, %.loopexit.loopexit ]
  %exitcond2 = icmp eq i4 %i, -5
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind
  %i_1 = add i4 %i, 1
  br i1 %exitcond2, label %.preheader.preheader_ifconv, label %.preheader.preheader

.preheader.preheader:                             ; preds = %.loopexit
  br label %.preheader

.preheader.preheader_ifconv:                      ; preds = %.loopexit
  ret void

.preheader:                                       ; preds = %.preheader.preheader, %.preheader
  %j = phi i4 [ %j_1, %.preheader ], [ 0, %.preheader.preheader ]
  %exitcond1 = icmp eq i4 %j, -5
  %empty_2 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind
  %j_1 = add i4 %j, 1
  br i1 %exitcond1, label %.loopexit.loopexit, label %.preheader
}

define weak void @_ssdm_op_SpecTopModule(...) {
entry:
  ret void
}

define weak i32 @_ssdm_op_SpecLoopTripCount(...) {
entry:
  ret i32 0
}

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
