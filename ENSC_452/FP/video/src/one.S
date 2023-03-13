    .global one
    .global one_size
    .section .rodata
one:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\one.data"
1:
one_size:
    .int 1b - one
