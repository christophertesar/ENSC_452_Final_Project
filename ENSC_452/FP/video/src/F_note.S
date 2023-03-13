    .global F_note
    .global F_note_size
    .section .rodata
F_note:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\F_note.data"
1:
F_note_size:
    .int 1b - F_note
