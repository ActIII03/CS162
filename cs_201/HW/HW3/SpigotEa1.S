  .global SpigotE      # This is a global symbol
  .text             # Start of text segment

SpigotE:
    movb    $0x2,(%rdi)     # 9  - output[0] = 2;
    movq    %rdx, %r10      # 10 - initialize: i = n
    add     $0x1,%r10       # 10 - i = i + 1;  
    call   loop1           # Start loop1, then test1 at end of loop1
    ret 

loop1:
                            # 12 - workbuffer[i] = 1;
                            # 10 -  --i;
                            # 10 - i >= 0

                            # 10 - i >= 0
     
