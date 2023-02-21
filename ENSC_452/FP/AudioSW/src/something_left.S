    .global something_left
    .global something_left_size
    .section .rodata
something_left:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\AudioSW\\src\\something_left.data"
1:
something_left_size:
    .int 1b - something_left

