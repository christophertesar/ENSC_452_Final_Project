    .global zero
    .global zero_size
    .section .rodata
zero:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\zero.data"
1:
zero_size:
    .int 1b - zero
