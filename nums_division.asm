global main
extern printf

section .data
    A       dq 47.0      
    B       dq -134.0      
    TWO     dq 2.0
    HUNDRED dq 100.0

    fmt_text db "%s",10,0
    fmt_float db "%f",10,0
    text1    db "47 / (-134)",0

section .bss
    RESULT      resq 1
    FINAL       resq 1
    FINAL100    resq 1

section .text
main:

    push text1
    push fmt_text
    call printf
    add esp, 8

    fld qword [A]       
    fdiv qword [B]      
    fstp qword [RESULT] 

    fld qword [RESULT]
    sub esp, 8
    fstp qword [esp]
    push fmt_float
    call printf
    add esp, 12

    fld qword [RESULT]
    fadd qword [TWO]
    fstp qword [FINAL]

    fld qword [FINAL]
    sub esp, 8
    fstp qword [esp]
    push fmt_float
    call printf
    add esp, 12

    fld qword [FINAL]
    fmul qword [HUNDRED]
    fstp qword [FINAL100]

    fld qword [FINAL100]
    sub esp, 8
    fstp qword [esp]
    push fmt_float
    call printf
    add esp, 12

    ret
