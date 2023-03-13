    .global three
    .global three_size
    .section .rodata
three:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\Numbers\\three.data"
1:
three_size:
    .int 1b - three
