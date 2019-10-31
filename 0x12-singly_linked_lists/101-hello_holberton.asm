section .rodata
    format: db 'Hello, %s', 10, 0
    name:   db 'Holberton', 0

section .text
        global main
        extern printf
    main:
        ; printf(format, name)
        mov rdi, format
        mov rsi, name
        ; no XMM registers
        mov rax, 0
        call printf
        ; return 0
        mov rax, 0
        ret
