; ModuleID = 'D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/a.o.2.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

@conv_str = internal unnamed_addr constant [5 x i8] c"conv\00"

declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

define void @conv([121 x i32]* %a, [121 x i32]* %b, i32* %c) nounwind {
  %sum = alloca i32
  call void (...)* @_ssdm_op_SpecBitsMap([121 x i32]* %a) nounwind, !map !13
  call void (...)* @_ssdm_op_SpecBitsMap([121 x i32]* %b) nounwind, !map !19
  call void (...)* @_ssdm_op_SpecBitsMap(i32* %c) nounwind, !map !23
  call void (...)* @_ssdm_op_SpecTopModule([5 x i8]* @conv_str) nounwind
  store i32 0, i32* %sum
  br label %.loopexit

.loopexit.loopexit:                               ; preds = %.preheader
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %0
  %i = phi i4 [ 0, %0 ], [ %i_1, %.loopexit.loopexit ]
  %phi_mul = phi i7 [ 0, %0 ], [ %next_mul, %.loopexit.loopexit ]
  %next_mul = add i7 %phi_mul, 11
  %exitcond1 = icmp eq i4 %i, -5
  %empty = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind
  %i_1 = add i4 %i, 1
  br i1 %exitcond1, label %2, label %.preheader.preheader

.preheader.preheader:                             ; preds = %.loopexit
  br label %.preheader

.preheader:                                       ; preds = %.preheader.preheader, %1
  %j = phi i4 [ %j_1, %1 ], [ 0, %.preheader.preheader ]
  %j_cast1_cast = zext i4 %j to i7
  %tmp_2 = add i7 %phi_mul, %j_cast1_cast
  %tmp_2_cast = zext i7 %tmp_2 to i32
  %a_addr = getelementptr [121 x i32]* %a, i32 0, i32 %tmp_2_cast
  %b_addr = getelementptr [121 x i32]* %b, i32 0, i32 %tmp_2_cast
  %exitcond = icmp eq i4 %j, -5
  %empty_3 = call i32 (...)* @_ssdm_op_SpecLoopTripCount(i64 11, i64 11, i64 11) nounwind
  %j_1 = add i4 %j, 1
  br i1 %exitcond, label %.loopexit.loopexit, label %1

; <label>:1                                       ; preds = %.preheader
  %sum_load_1 = load i32* %sum
  %a_load = load i32* %a_addr, align 4
  %b_load = load i32* %b_addr, align 4
  %tmp = mul nsw i32 %b_load, %a_load
  %sum_1 = add nsw i32 %tmp, %sum_load_1
  store i32 %sum_1, i32* %sum
  br label %.preheader

; <label>:2                                       ; preds = %.loopexit
  %sum_load = load i32* %sum
  call void @_ssdm_op_Write.ap_auto.i32P(i32* %c, i32 %sum_load) nounwind
  ret void
}

define weak void @_ssdm_op_Write.ap_auto.i32P(i32*, i32) {
entry:
  store i32 %1, i32* %0
  ret void
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
!13 = metadata !{metadata !14}
!14 = metadata !{i32 0, i32 31, metadata !15}
!15 = metadata !{metadata !16}
!16 = metadata !{metadata !"a", metadata !17, metadata !"int", i32 0, i32 31}
!17 = metadata !{metadata !18, metadata !18}
!18 = metadata !{i32 0, i32 10, i32 1}
!19 = metadata !{metadata !20}
!20 = metadata !{i32 0, i32 31, metadata !21}
!21 = metadata !{metadata !22}
!22 = metadata !{metadata !"b", metadata !17, metadata !"int", i32 0, i32 31}
!23 = metadata !{metadata !24}
!24 = metadata !{i32 0, i32 31, metadata !25}
!25 = metadata !{metadata !26}
!26 = metadata !{metadata !"c", metadata !27, metadata !"int", i32 0, i32 31}
!27 = metadata !{metadata !28}
!28 = metadata !{i32 0, i32 0, i32 1}
