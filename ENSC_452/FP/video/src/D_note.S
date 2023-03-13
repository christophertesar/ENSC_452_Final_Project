    .global D_note
    .global D_note_size
    .section .rodata
D_note:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\D_note.data"
1:
D_note_size:
    .int 1b - D_note
