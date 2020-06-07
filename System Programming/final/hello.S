.global foo
.text

foo:
    movq    $1, %rax        # copy 1 to %rax
    ret                     # return to caller
