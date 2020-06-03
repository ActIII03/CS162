.global fibonacci
.text

fibonacci:
    cmp     $0,%rdi         #n == 0
    jz      ret1            
    cmp     $1,%rdi         #n == 1
    je      ret2
    jmp     ret3

ret1:
    ret                     #return 0

ret2:
    movq    $1,%rax         
    ret                     #return 1 

ret3:
    dec     %rdi            #n - 1
    push    %rdi            # push difference to stack (n - 1)
    call    fibonacci       #Call fibonacci
    pop     %rdi            #pop from 23 to rax
    subq    $2,%rdi         #n - 2
    movq    %rdi,%rax
    call    fibonacci       #Call fibonacci
    pop     %rax            
    addq    %rdi,%rax       #add return values
    ret
