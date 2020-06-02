.global fibonacci
.text

fibonacci:
    pushq   %rax            #Save value in RAX
    cmp     $0,%rdi         #n == 0
    jz      ret1            
    cmp     $1,%rdi         #n == 1
    je      ret2
    jmp     ret3
                            #Pop something here
    ret

ret1:
    ret                     #return 0

ret2:
    movq    $1,%rax         
    ret                     #return 1 

ret3:
                            #Call something here
