	.file	"13cfun.c"
	.section	.rodata
.LC0:
	.string	"foo()"
	.text
.globl foo
	.type	foo, @function
foo:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$.LC0, (%esp)
	call	puts
	leave
	ret
	.size	foo, .-foo
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	foo
	movl	$1, (%esp)
	call	foo
	movl	$2, 4(%esp)
	movl	$1, (%esp)
	call	foo
	movl	$100, (%esp)
	call	showNum
	movl	$1001, (%esp)
	call	showNum
	leave
	ret
	.size	main, .-main
	.section	.rodata
.LC1:
	.string	"x=%d\n"
	.text
.globl showNum
	.type	showNum, @function
showNum:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$.LC1, %eax
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leave
	ret
	.size	showNum, .-showNum
	.ident	"GCC: (Ubuntu/Linaro 4.4.7-1ubuntu2) 4.4.7"
	.section	.note.GNU-stack,"",@progbits
