    .global gh_gameplay
    .global gh_gameplay_size
    .section .rodata
gh_gameplay:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\VideoSW\\src\\gameplay.data"
1:
gh_gameplay_size:
    .int 1b - gh_gameplay
