    .global black_lanes
    .global black_lanes_size
    .section .rodata
black_lanes:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\black_lanes.data"
1:
black_lanes_size:
    .int 1b - black_lanes
