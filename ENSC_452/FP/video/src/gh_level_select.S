    .global gh_level_select
    .global gh_level_select_size
    .section .rodata
gh_level_select:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\gh_level_select.data"
1:
gh_level_select_size:
    .int 1b - gh_level_select
