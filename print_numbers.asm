global main
extern printf

section .data
    TEN     equ 10
    NEGNUM  dd -12
    HEX1    dw 0123h
    HEX2    dw 0ABCDh
    BIN1    db 01010b

    fmt_int   db "%d",10,0

section .text
main:
    mov ebp, esp; for correct debugging
    ; TEN
    push TEN
    push fmt_int
    call printf
    add esp, 8

    ; NEGNUM
    push dword [NEGNUM]
    push fmt_int
    call printf
    add esp, 8

    ; HEX1
    movzx eax, word [HEX1]   
    push eax
    push fmt_int
    call printf
    add esp, 8

    ; HEX2
    movzx eax, word [HEX2]
    push eax
    push fmt_int
    call printf
    add esp, 8

    ; BIN1
    movzx eax, byte [BIN1]
    push eax
    push fmt_int
    call printf
    add esp, 8

    ret
