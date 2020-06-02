.global fibonacci
.text

fibonacci:
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
    subq                    #n - 1
                            # push difference to stack (n - 1)
                            #call fibonacci
                            #pop from 23 to rax
                            #n - 2
                            #push difference from 
                            #Call 
