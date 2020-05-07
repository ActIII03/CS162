  .global SpigotE                   # This is a global symbol
  .text                             # Start of text segment

# Variable list:
# (1) rdi = output (2) rsi = workbuffer (3) rdx = n (4) r10 = i 
# (5) r15 = i (6) r14 = q (7) r11 = temp

SpigotE:
    movb    $2,(%rdi)               # 9  - output[0] = 2;
    movq    %rdx, %r10              # 10 - initialize: i = n
    addq    $1,%r10                 # 10 - i = i + 1;  
    call    forLoop1                # *Compiled and ran to this point*
    movq    $1,%r15                 # 15 - j = 1
    call    forLoop2                # Start forLoop and continue until (j >= n) is true
    ret 

forLoop1:                           # for-Loop at line: 10 
    movq    $1,(%rsi, %r10,8)       # 12 - workbuffer[i] = 1;
    dec     %r10                    # 10 -  --i;
    cmpq    $0,%r10                 # 10 - i >= 0
    jns     forLoop1                # restart forLoop1 if false 
    ret                             # otherwise, exit forLoop1 

forLoop2:                           # for-Loop at line:15 
    movq    $0,%r14                 # 17 - q = 0; 
    movq    %rdx,%r10               # 18 - i = n
    addq    $1,%r10                 # 10 - i = i + 1;  
    call    forLoop3                # Start forLoop3 and continue until (i < 0) is true
    movq    %r14,(%rdi, %r15,8)     # 25 - output[j] = q;
    ret

forLoop3:
    movq    (%rsi, %r10, 8), %r11   # 20 - temp = workbuffer[i];
    movq    $10,%r9                 # Save 10 into a temporary buffer
    imulq   %r11,%r9                # Save product of 10 * workbuffer[i] into temporary buffer  
    movq    %r9,(%rsi, %r10, 8)     # Move product stored in temporary buffer into temp var
    addq    %r14,%r11               # 20 - temp = temp + q; 
    movq    %r11,%r14               # 21 - q = temp
    movq    %r10,%r9                # Move i into a temporary buffer
    addq    $2,%r10                 # Add to 2 to temporary buffer
    movq    %r11,%rax               # Get ready for division moving temp into the dividend reg RAX
    movq    %rdx,%r13               # Save n into temporary buffer before division
    movq    %r10,%rdx               # Move i into the quotient register
    idiv     %rdx                   # Divide temp by (i + 2)
