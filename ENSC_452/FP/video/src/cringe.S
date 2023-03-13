    .global cringe
    .global cringe_size
    .section .rodata
cringe:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\cringe.data"
1:
cringe_size:
    .int 1b - cringe
