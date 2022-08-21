[bits 16]



start:
    mov byte cl, [0x7c00]
    mov byte [0x7c00], dl
