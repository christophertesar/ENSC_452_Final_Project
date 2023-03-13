    .global seven
    .global seven_size
    .section .rodata
seven:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\seven.data"
1:
seven_size:
    .int 1b - seven
