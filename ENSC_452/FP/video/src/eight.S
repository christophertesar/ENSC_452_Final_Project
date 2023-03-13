    .global eight
    .global eight
    .section .rodata
eight:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\eight.data"
1:
eight_size:
    .int 1b - eight
