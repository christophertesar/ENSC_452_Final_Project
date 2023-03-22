    .global americanfootball_left
    .global americanfootball_left_size
    .section .rodata
americanfootball_left:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\Test_1\\src\\americanfootball_left.data"
1:
americanfootball_left_size:
    .int 1b - americanfootball_left
