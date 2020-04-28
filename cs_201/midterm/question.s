	.file	"question.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"g: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	mov	edx, 52
	lea	rsi, .LC0[rip]
	mov	edi, 1
	mov	eax, 0
	call	__printf_chk@PLT
	mov	eax, 0
	add	rsp, 8
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.globl	Allocate3DArray
	.type	Allocate3DArray, @function
Allocate3DArray:
.LFB40:
	.cfi_startproc
	endbr64
	push	r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 24
	.cfi_def_cfa_offset 80
	mov	r14, rdi
	mov	DWORD PTR 12[rsp], esi
	mov	r13d, edx
	mov	r15d, ecx
	movsx	rdi, esi
	sal	rdi, 3
	call	malloc@PLT
	mov	QWORD PTR [r14], rax
	mov	DWORD PTR 8[rsp], 0
	jmp	.L4
.L6:
	mov	rax, QWORD PTR [r14]
	movsx	rbx, ebp
	sal	rbx, 3
	add	rbx, QWORD PTR [rax+r12]
	movsx	rdi, r15d
	sal	rdi, 3
	call	malloc@PLT
	mov	QWORD PTR [rbx], rax
	add	ebp, 1
.L5:
	cmp	ebp, r13d
	jl	.L6
	add	DWORD PTR 8[rsp], 1
.L4:
	mov	edx, DWORD PTR 12[rsp]
	cmp	DWORD PTR 8[rsp], edx
	jge	.L9
	movsx	r12, DWORD PTR 8[rsp]
	sal	r12, 3
	mov	rbx, r12
	add	rbx, QWORD PTR [r14]
	movsx	rdi, r13d
	sal	rdi, 3
	call	malloc@PLT
	mov	QWORD PTR [rbx], rax
	mov	ebp, 0
	jmp	.L5
.L9:
	add	rsp, 24
	.cfi_def_cfa_offset 56
	pop	rbx
	.cfi_def_cfa_offset 48
	pop	rbp
	.cfi_def_cfa_offset 40
	pop	r12
	.cfi_def_cfa_offset 32
	pop	r13
	.cfi_def_cfa_offset 24
	pop	r14
	.cfi_def_cfa_offset 16
	pop	r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE40:
	.size	Allocate3DArray, .-Allocate3DArray
	.globl	Destory3DArray
	.type	Destory3DArray, @function
Destory3DArray:
.LFB41:
	.cfi_startproc
	endbr64
	push	r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	push	r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	push	r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	push	r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	push	rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	push	rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	sub	rsp, 8
	.cfi_def_cfa_offset 64
	mov	r14, rdi
	mov	r15d, esi
	mov	r12d, edx
	mov	r13d, 0
	jmp	.L11
.L14:
	movsx	rax, ebx
	sal	rax, 3
	add	rax, QWORD PTR 0[rbp]
	mov	rdi, QWORD PTR [rax]
	call	free@PLT
	add	ebx, 1
.L12:
	cmp	ebx, r12d
	jl	.L14
.L13:
	mov	rdi, QWORD PTR 0[rbp]
	call	free@PLT
	add	r13d, 1
.L11:
	cmp	r13d, r15d
	jge	.L18
	movsx	rax, r13d
	lea	rbp, [r14+rax*8]
	cmp	QWORD PTR 0[rbp], 0
	je	.L13
	mov	ebx, 0
	jmp	.L12
.L18:
	mov	rdi, r14
	call	free@PLT
	add	rsp, 8
	.cfi_def_cfa_offset 56
	pop	rbx
	.cfi_def_cfa_offset 48
	pop	rbp
	.cfi_def_cfa_offset 40
	pop	r12
	.cfi_def_cfa_offset 32
	pop	r13
	.cfi_def_cfa_offset 24
	pop	r14
	.cfi_def_cfa_offset 16
	pop	r15
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE41:
	.size	Destory3DArray, .-Destory3DArray
	.ident	"GCC: (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
