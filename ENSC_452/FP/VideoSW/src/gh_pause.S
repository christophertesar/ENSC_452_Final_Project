    .global gh_pause
    .global gh_pause_size
    .section .rodata
gh_pause:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\VideoSW\\src\\pause.data"
1:
gh_pause_size:
    .int 1b - gh_pause
