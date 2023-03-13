    .global gh_menu
    .global gh_menu_size
    .section .rodata
gh_menu:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\gh_menu.data"
1:
gh_menu_size:
    .int 1b - gh_menu
