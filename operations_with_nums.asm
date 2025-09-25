global main
extern printf

section .data
    NUM1    dd 47       
    NUM2    dd -134     
    RESULT  dd 0        
    fmt     db "%d",10,0  

section .text
main:
   
    mov eax, [NUM1]     
    neg eax             
    mov [NUM1], eax     
    push eax
    push fmt
    call printf
    add esp, 8

    mov eax, [NUM2]     
    inc eax             
    mov [NUM2], eax
    push eax
    push fmt
    call printf
    add esp, 8

    mov eax, [NUM1]     
    add eax, [NUM2]     
    mov [RESULT], eax
    push eax
    push fmt
    call printf
    add esp, 8

    ret
