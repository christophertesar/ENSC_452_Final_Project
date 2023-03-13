    .global four
    .global four_size
    .section .rodata
four:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\four.data"
1:
four_size:
    .int 1b - four
