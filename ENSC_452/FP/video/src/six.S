    .global six
    .global six_size
    .section .rodata
six:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\six.data"
1:
six_size:
    .int 1b - six
