    .global gh_highscores
    .global gh_highscores_size
    .section .rodata
gh_highscores:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\gh_highscores.data"
1:
gh_highscores_size:
    .int 1b - gh_highscores
