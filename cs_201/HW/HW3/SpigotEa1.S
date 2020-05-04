  .global SpigotE      # This is a global symbol
  .text             # Start of text segment

SpigotE:
    movb    $0x2,(%rdi)             # 9  - output[0] = 2;
    movq    %rdx, %r10              # 10 - initialize: i = n
    add     $0x1,%r10               # 10 - i = i + 1;  
    call    loop1                   # *Compiled and ran to this point*
    movq    $0x1,%r15               # 15 - j = 1
    call    loop2                   # Start loop and continue until (j >= n) is true
    ret 

loop1:                              # for-loop at line: 10 
    movq    $0x1(%rsi, %r10)        # 12 - workbuffer[i] = 1;
    dec     %r10                    # 10 -  --i;
    cmpq    %r10,$0                 # 10 - i >= 0
    jl                              # restart loop1 if false 
    ret                             # otherwise, exit loop1 

loop2:                              # for-loop at line:15 
    movb     $0,%r15                # 17 - q = 0; 
    call     loop3                  # Start loop3 and continue until (i < 0) is true
                                    # 25 - output[j] = q;
    ret

loop3:
