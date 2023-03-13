    .global nine
    .global nine_size
    .section .rodata
nine:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\nine.data"
1:
nine_size:
    .int 1b - nine
