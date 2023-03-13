    .global gh_sound_settings
    .global gh_sound_settings_size
    .section .rodata
gh_sound_settings:
    .incbin "C:\\Users\\Christopher\\Desktop\\FP\\ENSC_452\\FP\\video\\src\\gh_sound_settings.data"
1:
gh_sound_settings_size:
    .int 1b - gh_sound_settings
