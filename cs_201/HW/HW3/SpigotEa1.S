  .global SpigotE                   # This is a global symbol
  .text                             # Start of text segment

# Variable list:
# (1) rdi = output (2) rsi = workbuffer (3) rdx = n (4) r10 = i 
# (5) r15 = i (6) r14 = q (7) r11 = temp

SpigotE:
    movb    $2,(%rdi)               # 9  - output[0] = 2;
    movq    %rdx, %r10              # 10 - initialize: i = n
    addq    $1,%r10                 # 10 - i = i + 1;  
    cmp     $0, %r10                # 10 - i >= 0
    jge     forLoop1                # Start forLoop1 

forLoop1:                           # for-loop at line: 10 
    movq    $1,(%rsi, %r10,8)       # 12 - workbuffer[i] = 1;
    dec     %r10                    # 10 -  --i;
    cmpq    $0,%r10                 # 10 - i >= 0
    jge     forLoop1                # restart forLoop1 if false 
    jmp     done1

done1:
    movq    $1,%r15                 # 15 - j = 1
    movq    %rdx,%r11               # Move n into another reg before division
    jmp     fl2test

fl2test:
    cmpq    %rdx,%r15               # 15 - j < n 
    jl      forLoop2                # Start forLoop2 and continue until (j >= n) is true
    ret

#Work on but CLOSE
forLoop2:                           # for-loop at line:15 
    movq    $0,%r14                 # 17 - q = 0; 
    movq    %rdx,%r10               # 18 - i = n
    addq    $1,%r10                 # 10 - i = i + 1;  
    jmp     fl3test

fl3test:
    cmpq    $0,%r10                 # 18 - i >= 0 
    jge     forLoop3                # Start forLoop3 and continue until (i < 0) is true
    jmp     done2

done2:
    movq    %r14,(%rdi, %r15,8)     # 25 - output[j] = q;
    addq    $1,%r15                 # 25 - j++
    jmp     forLoop2

forLoop3:                           #for-loop at line:18
    movq    $10,%r9                 # Save 10 into a temporary buffer  
    imulq   (%rsi,%r10,8), %r9      # 20 - 10 * workbuffer[i]
    addq    %r9, %rax               # move sum into rax to prepare for division. 
    movq    %r10,%rdx               # Move i into a temporary buffer
    addq    $2,%rdx                 # Add to 2 to temporary buffer --> i
    divq    %rax                    # Divide temp by (i + 2)
    movq    %rax,%r14               # Move quotient into q (r14) 
    movq    %rdx,(%rsi,%r10,8)      # 22 - temp % (i + 2);
