    .global something_right
    .global something_right_size
    .section .rodata
something_right:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\AudioSW\\src\\something_right.data"
1:
something_right_size:
    .int 1b - something_right
