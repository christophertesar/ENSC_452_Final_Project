    .global two
    .global two_size
    .section .rodata
two:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\two.data"
1:
two_size:
    .int 1b - two
