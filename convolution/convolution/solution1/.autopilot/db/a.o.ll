; ModuleID = 'D:/venky/workdir/designs/convolution/convolution/solution1/.autopilot/db/a.o.bc'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-f80:128:128-v64:64:64-v128:128:128-a0:0:64-f80:32:32-n8:16:32-S32"
target triple = "i686-pc-mingw32"

; [#uses=0]
define void @_Z4convPA11_iS0_i([11 x i32]* %a, [11 x i32]* %b, i32 %c) nounwind {
  %1 = alloca [11 x i32]*, align 4                ; [#uses=3 type=[11 x i32]**]
  %2 = alloca [11 x i32]*, align 4                ; [#uses=3 type=[11 x i32]**]
  %3 = alloca i32, align 4                        ; [#uses=2 type=i32*]
  %sum = alloca i32, align 4                      ; [#uses=5 type=i32*]
  %i = alloca i32, align 4                        ; [#uses=9 type=i32*]
  %j = alloca i32, align 4                        ; [#uses=11 type=i32*]
  %temp = alloca [11 x i32], align 4              ; [#uses=4 type=[11 x i32]*]
  store [11 x i32]* %a, [11 x i32]** %1, align 4
  call void @llvm.dbg.declare(metadata !{[11 x i32]** %1}, metadata !24), !dbg !25 ; [debug line = 2:18] [debug variable = a]
  store [11 x i32]* %b, [11 x i32]** %2, align 4
  call void @llvm.dbg.declare(metadata !{[11 x i32]** %2}, metadata !26), !dbg !27 ; [debug line = 2:36] [debug variable = b]
  store i32 %c, i32* %3, align 4
  call void @llvm.dbg.declare(metadata !{i32* %3}, metadata !28), !dbg !29 ; [debug line = 2:54] [debug variable = c]
  %4 = load [11 x i32]** %1, align 4, !dbg !30    ; [#uses=1 type=[11 x i32]*] [debug line = 3:2]
  call void (...)* @_ssdm_SpecArrayDimSize([11 x i32]* %4, i32 11) nounwind, !dbg !30 ; [debug line = 3:2]
  %5 = load [11 x i32]** %2, align 4, !dbg !32    ; [#uses=1 type=[11 x i32]*] [debug line = 3:31]
  call void (...)* @_ssdm_SpecArrayDimSize([11 x i32]* %5, i32 11) nounwind, !dbg !32 ; [debug line = 3:31]
  call void @llvm.dbg.declare(metadata !{i32* %sum}, metadata !33), !dbg !34 ; [debug line = 4:6] [debug variable = sum]
  store i32 0, i32* %sum, align 4, !dbg !35       ; [debug line = 4:11]
  call void @llvm.dbg.declare(metadata !{i32* %i}, metadata !36), !dbg !37 ; [debug line = 5:9] [debug variable = i]
  call void @llvm.dbg.declare(metadata !{i32* %j}, metadata !38), !dbg !39 ; [debug line = 5:11] [debug variable = j]
  call void @llvm.dbg.declare(metadata !{[11 x i32]* %temp}, metadata !40), !dbg !41 ; [debug line = 6:9] [debug variable = temp]
  store i32 0, i32* %i, align 4, !dbg !42         ; [debug line = 7:6]
  br label %6, !dbg !42                           ; [debug line = 7:6]

; <label>:6                                       ; preds = %39, %0
  %7 = load i32* %i, align 4, !dbg !42            ; [#uses=1 type=i32] [debug line = 7:6]
  %8 = icmp slt i32 %7, 11, !dbg !42              ; [#uses=1 type=i1] [debug line = 7:6]
  br i1 %8, label %9, label %42, !dbg !42         ; [debug line = 7:6]

; <label>:9                                       ; preds = %6
  %10 = load i32* %i, align 4, !dbg !44           ; [#uses=1 type=i32] [debug line = 9:3]
  %11 = getelementptr inbounds [11 x i32]* %temp, i32 0, i32 %10, !dbg !44 ; [#uses=1 type=i32*] [debug line = 9:3]
  store i32 0, i32* %11, align 4, !dbg !44        ; [debug line = 9:3]
  store i32 0, i32* %j, align 4, !dbg !46         ; [debug line = 10:7]
  br label %12, !dbg !46                          ; [debug line = 10:7]

; <label>:12                                      ; preds = %35, %9
  %13 = load i32* %j, align 4, !dbg !46           ; [#uses=1 type=i32] [debug line = 10:7]
  %14 = icmp slt i32 %13, 11, !dbg !46            ; [#uses=1 type=i1] [debug line = 10:7]
  br i1 %14, label %15, label %38, !dbg !46       ; [debug line = 10:7]

; <label>:15                                      ; preds = %12
  %16 = load i32* %i, align 4, !dbg !48           ; [#uses=1 type=i32] [debug line = 12:4]
  %17 = getelementptr inbounds [11 x i32]* %temp, i32 0, i32 %16, !dbg !48 ; [#uses=1 type=i32*] [debug line = 12:4]
  %18 = load i32* %17, align 4, !dbg !48          ; [#uses=1 type=i32] [debug line = 12:4]
  %19 = load i32* %j, align 4, !dbg !48           ; [#uses=1 type=i32] [debug line = 12:4]
  %20 = load i32* %i, align 4, !dbg !48           ; [#uses=1 type=i32] [debug line = 12:4]
  %21 = load [11 x i32]** %1, align 4, !dbg !48   ; [#uses=1 type=[11 x i32]*] [debug line = 12:4]
  %22 = getelementptr inbounds [11 x i32]* %21, i32 %20, !dbg !48 ; [#uses=1 type=[11 x i32]*] [debug line = 12:4]
  %23 = getelementptr inbounds [11 x i32]* %22, i32 0, i32 %19, !dbg !48 ; [#uses=1 type=i32*] [debug line = 12:4]
  %24 = load i32* %23, align 4, !dbg !48          ; [#uses=1 type=i32] [debug line = 12:4]
  %25 = load i32* %j, align 4, !dbg !48           ; [#uses=1 type=i32] [debug line = 12:4]
  %26 = load i32* %i, align 4, !dbg !48           ; [#uses=1 type=i32] [debug line = 12:4]
  %27 = load [11 x i32]** %2, align 4, !dbg !48   ; [#uses=1 type=[11 x i32]*] [debug line = 12:4]
  %28 = getelementptr inbounds [11 x i32]* %27, i32 %26, !dbg !48 ; [#uses=1 type=[11 x i32]*] [debug line = 12:4]
  %29 = getelementptr inbounds [11 x i32]* %28, i32 0, i32 %25, !dbg !48 ; [#uses=1 type=i32*] [debug line = 12:4]
  %30 = load i32* %29, align 4, !dbg !48          ; [#uses=1 type=i32] [debug line = 12:4]
  %31 = mul nsw i32 %24, %30, !dbg !48            ; [#uses=1 type=i32] [debug line = 12:4]
  %32 = add nsw i32 %18, %31, !dbg !48            ; [#uses=1 type=i32] [debug line = 12:4]
  %33 = load i32* %i, align 4, !dbg !48           ; [#uses=1 type=i32] [debug line = 12:4]
  %34 = getelementptr inbounds [11 x i32]* %temp, i32 0, i32 %33, !dbg !48 ; [#uses=1 type=i32*] [debug line = 12:4]
  store i32 %32, i32* %34, align 4, !dbg !48      ; [debug line = 12:4]
  br label %35, !dbg !50                          ; [debug line = 13:3]

; <label>:35                                      ; preds = %15
  %36 = load i32* %j, align 4, !dbg !51           ; [#uses=1 type=i32] [debug line = 10:18]
  %37 = add nsw i32 %36, 1, !dbg !51              ; [#uses=1 type=i32] [debug line = 10:18]
  store i32 %37, i32* %j, align 4, !dbg !51       ; [debug line = 10:18]
  br label %12, !dbg !51                          ; [debug line = 10:18]

; <label>:38                                      ; preds = %12
  br label %39, !dbg !52                          ; [debug line = 14:2]

; <label>:39                                      ; preds = %38
  %40 = load i32* %i, align 4, !dbg !53           ; [#uses=1 type=i32] [debug line = 7:17]
  %41 = add nsw i32 %40, 1, !dbg !53              ; [#uses=1 type=i32] [debug line = 7:17]
  store i32 %41, i32* %i, align 4, !dbg !53       ; [debug line = 7:17]
  br label %6, !dbg !53                           ; [debug line = 7:17]

; <label>:42                                      ; preds = %6
  store i32 0, i32* %sum, align 4, !dbg !54       ; [debug line = 15:2]
  store i32 0, i32* %j, align 4, !dbg !55         ; [debug line = 16:6]
  br label %43, !dbg !55                          ; [debug line = 16:6]

; <label>:43                                      ; preds = %52, %42
  %44 = load i32* %j, align 4, !dbg !55           ; [#uses=1 type=i32] [debug line = 16:6]
  %45 = icmp slt i32 %44, 11, !dbg !55            ; [#uses=1 type=i1] [debug line = 16:6]
  br i1 %45, label %46, label %55, !dbg !55       ; [debug line = 16:6]

; <label>:46                                      ; preds = %43
  %47 = load i32* %sum, align 4, !dbg !57         ; [#uses=1 type=i32] [debug line = 18:5]
  %48 = load i32* %j, align 4, !dbg !57           ; [#uses=1 type=i32] [debug line = 18:5]
  %49 = getelementptr inbounds [11 x i32]* %temp, i32 0, i32 %48, !dbg !57 ; [#uses=1 type=i32*] [debug line = 18:5]
  %50 = load i32* %49, align 4, !dbg !57          ; [#uses=1 type=i32] [debug line = 18:5]
  %51 = add nsw i32 %47, %50, !dbg !57            ; [#uses=1 type=i32] [debug line = 18:5]
  store i32 %51, i32* %sum, align 4, !dbg !57     ; [debug line = 18:5]
  br label %52, !dbg !59                          ; [debug line = 19:4]

; <label>:52                                      ; preds = %46
  %53 = load i32* %j, align 4, !dbg !60           ; [#uses=1 type=i32] [debug line = 16:17]
  %54 = add nsw i32 %53, 1, !dbg !60              ; [#uses=1 type=i32] [debug line = 16:17]
  store i32 %54, i32* %j, align 4, !dbg !60       ; [debug line = 16:17]
  br label %43, !dbg !60                          ; [debug line = 16:17]

; <label>:55                                      ; preds = %43
  %56 = load i32* %sum, align 4, !dbg !61         ; [#uses=1 type=i32] [debug line = 20:2]
  store i32 %56, i32* %3, align 4, !dbg !61       ; [debug line = 20:2]
  ret void, !dbg !62                              ; [debug line = 21:1]
}

; [#uses=7]
declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

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
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"conv", metadata !"conv", metadata !"_Z4convPA11_iS0_i", metadata !6, i32 2, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, void ([11 x i32]*, [11 x i32]*, i32)* @_Z4convPA11_iS0_i, null, null, metadata !15, i32 3} ; [ DW_TAG_subprogram ]
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
!17 = metadata !{void ([11 x i32]*, [11 x i32]*, i32)* @_Z4convPA11_iS0_i, metadata !18, metadata !19, metadata !20, metadata !21, metadata !22, metadata !23}
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
!33 = metadata !{i32 786688, metadata !31, metadata !"sum", metadata !6, i32 4, metadata !12, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!34 = metadata !{i32 4, i32 6, metadata !31, null}
!35 = metadata !{i32 4, i32 11, metadata !31, null}
!36 = metadata !{i32 786688, metadata !31, metadata !"i", metadata !6, i32 5, metadata !11, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!37 = metadata !{i32 5, i32 9, metadata !31, null}
!38 = metadata !{i32 786688, metadata !31, metadata !"j", metadata !6, i32 5, metadata !11, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!39 = metadata !{i32 5, i32 11, metadata !31, null}
!40 = metadata !{i32 786688, metadata !31, metadata !"temp", metadata !6, i32 6, metadata !10, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!41 = metadata !{i32 6, i32 9, metadata !31, null}
!42 = metadata !{i32 7, i32 6, metadata !43, null}
!43 = metadata !{i32 786443, metadata !31, i32 7, i32 2, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!44 = metadata !{i32 9, i32 3, metadata !45, null}
!45 = metadata !{i32 786443, metadata !43, i32 8, i32 2, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!46 = metadata !{i32 10, i32 7, metadata !47, null}
!47 = metadata !{i32 786443, metadata !45, i32 10, i32 3, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!48 = metadata !{i32 12, i32 4, metadata !49, null}
!49 = metadata !{i32 786443, metadata !47, i32 11, i32 3, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!50 = metadata !{i32 13, i32 3, metadata !49, null}
!51 = metadata !{i32 10, i32 18, metadata !47, null}
!52 = metadata !{i32 14, i32 2, metadata !45, null}
!53 = metadata !{i32 7, i32 17, metadata !43, null}
!54 = metadata !{i32 15, i32 2, metadata !31, null}
!55 = metadata !{i32 16, i32 6, metadata !56, null}
!56 = metadata !{i32 786443, metadata !31, i32 16, i32 2, metadata !6, i32 5} ; [ DW_TAG_lexical_block ]
!57 = metadata !{i32 18, i32 5, metadata !58, null}
!58 = metadata !{i32 786443, metadata !56, i32 17, i32 4, metadata !6, i32 6} ; [ DW_TAG_lexical_block ]
!59 = metadata !{i32 19, i32 4, metadata !58, null}
!60 = metadata !{i32 16, i32 17, metadata !56, null}
!61 = metadata !{i32 20, i32 2, metadata !31, null}
!62 = metadata !{i32 21, i32 1, metadata !31, null}
