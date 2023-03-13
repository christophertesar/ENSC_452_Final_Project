    .global S_note
    .global S_note_size
    .section .rodata
S_note:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\S_note.data"
1:
S_note_size:
    .int 1b - S_note
