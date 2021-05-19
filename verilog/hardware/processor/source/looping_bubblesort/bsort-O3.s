	.file	"bsort.c"
	.option nopic
	.text
	.section	.text.startup,"ax",@progbits
	.align	2
	.globl	main
	.type	main, @function
main:
.L3:
	li	a5,58
.L2:
	addi	a5,a5,-1
	bnez	a5,.L2
	j	.L3
	.size	main, .-main
	.globl	bsort_input_len
	.section	.srodata,"a"
	.align	2
	.type	bsort_input_len, @object
	.size	bsort_input_len, 4
bsort_input_len:
	.word	59
	.ident	"GCC: (GNU) 8.2.0"
