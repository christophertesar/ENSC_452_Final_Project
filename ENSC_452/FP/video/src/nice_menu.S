    .global nice_menu
    .global nice_menu_size
    .section .rodata
nice_menu:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\menu.data"
1:
nice_menu_size:
    .int 1b - nice_menu
