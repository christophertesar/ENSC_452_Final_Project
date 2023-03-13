    .global arrow
    .global arrow_size
    .section .rodata
arrow:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\arrow.data"
1:
arrow_size:
    .int 1b - arrow
