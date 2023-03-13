    .global yay
    .global yay_size
    .section .rodata
yay:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\yay.data"
1:
yay_size:
    .int 1b - yay
