    .global five
    .global five_size
    .section .rodata
five:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\five.data"
1:
five_size:
    .int 1b - five
