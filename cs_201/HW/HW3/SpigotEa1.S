  .global SpigotE                   # This is a global symbol
  .text                             # Start of text segment

SpigotE:
    movb    $2,(%rdi)               # 9  - output[0] = 2;
    movq    %rdx, %r10              # 10 - initialize: i = n
    addq    $1,%r10                 # 10 - i = i + 1;  
    call    for-loop1               # *Compiled and ran to this point*
    movq    $1,%r15                 # 15 - j = 1
    call    for-loop2               # Start for-loop and continue until (j >= n) is true
    ret 

for-loop1:                          # for-for-loop at line: 10 
    movq    $1,(%rsi, %r10,8)       # 12 - workbuffer[i] = 1;
    dec     %r10                    # 10 -  --i;
    cmpq    $0,%r10                 # 10 - i >= 0
    jns     for-loop1               # restart for-loop1 if false 
    ret                             # otherwise, exit for-loop1 

for-loop2:                          # for-for-loop at line:15 
    movq    $0,%r14                 # 17 - q = 0; 
    movq    %rdx,%r10               # 18 - i = n
    addq    $1,%r10                 # 10 - i = i + 1;  
    call    for-loop3               # Start for-loop3 and continue until (i < 0) is true
                                    # 25 - output[j] = q;
    ret

for-loop3:
    movq    (%rsi, %r10, 8), %r11   # 20 - temp = workbuffer[i];
    movq    $10,%r9                 # Save 10 into a temporary buffer
    imul    (%r11, %r10),%r9        # Save product of 10 * workbuffer[i] into temporary buffer  
    movq    %r9, (%r11, %r10, 8)    # Move product stored in temporary buffer into temp var
    addq    %r14,%r11               # 20 - temp = temp + q; 
    movq    %r11, 
