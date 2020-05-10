  .global SpigotE                   # This is a global symbol
  .text                             # Start of text segment

# Variable list:
# (1) rdi = output (2) rsi = workbuffer (3) rdx = n (4) r10 = i 
# (5) r15 = i (6) r14 = q (7) r11 = temp

SpigotE:
    #movb    $2,(%rdi)               # 9  - output[0] = 2;
    movq    %rdx, %r10              # 10 - initialize: i = n
    addq    $1,%r10                 # 10 - i = i + 1;  
    cmpq    $0, %r10                # 10 - i >= 0
    jge     forLoop1                # Start forLoop1 

forLoop1:                           # for-loop at line: 10 
    #movq    $1,(%rsi, %r10,8)       # 12 - workbuffer[i] = 1;
    dec     %r10                    # 10 -  --i;
    cmpq    $0,%r10                 # 10 - i >= 0
    jge     forLoop1                # restart forLoop1 if true 
    jmp     done1

done1:
    movq    $1,%r15                 # 15 - j = 1
    movq    %rdx,%r11               # Move n into another reg before division
    jmp     fl2test

fl2test:
    cmpq    %r11,%r15               # 15 - j < n 
    jl      forLoop2                # Start forLoop2 if true
    movq    %r11,%rdx               # Move n back into original parameter register
    ret                             # Exit function w/ no return value

forLoop2:                           # for-loop at line:15 
    movq    $0,%r14                 # 17 - q = 0; 
    movq    %r11,%r10               # 18 - i = n
    addq    $1,%r10                 # 10 - i = i + 1;  
    jmp     fl3test

fl3test:
    cmpq    $0,%r10                 # 18 - i >= 0 
    jge     forLoop3                # Start forLoop3 and continue until (i < 0) is true
    jmp     done2

done2:
    #movq    %r14,(%rdi, %r15,8)     # 25 - output[j] = q;
    inc     %r15                    # 25 - j++
    jmp     fl2test

forLoop3:                           #for-loop at line:18
    #xorq    %rdx,%rdx               # Clear out dividend register --->  %rdx in our case
    #xorq    %rax,%rax               # Clear out divisor register ---> %rax in our case

    # 20
    #movq    $10,%rax                # Move 10 into a multiple register ---> %rax
    #movq    (%rsi,%r10,8),%rdx      # Move workbuffer[i] into multiple register ---> %rdx
    #mulq    %rdx                    # Product is in %rax
    #movq    %rax,%rcx               # Move product from %rax to %rcx
    #addq    %r14,%rcx               # 20 - workbuffer[i] * 10 + q ---> %rdx

    #xorq    %rdx,%rdx               # Clear out %rdx

    # 21
    #movq    %r10,%r9                # Move i into temp reg 
    #addq    $2,%r9                  # Add to 2 to temporary buffer --> i
    #movq    %rcx,%rax               # move temp into dividend register ---> %rax    
    #divq    %r9                     # Divide temp by (i + 2)
    #movq    %rax,%r14               # Move quotient into q %r14 

    #xorq    %r9,%r9                 # Clear out reg. for next iteration

    #22
    #movb    %dl,(%rsi,%r10,1)       # 22 - workbuffer[i] = temp % (i + 2);
    jmp     done3

done3:
    dec     %r10                    # 18 - i--
    jmp     fl3test 
