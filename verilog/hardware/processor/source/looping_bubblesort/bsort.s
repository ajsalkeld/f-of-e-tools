	.file	"bsort.c"
	.option nopic
	.text
	.align	2
	.globl	main
	.type	main, @function
main:
	lui	a0,%hi(.LANCHOR0)
	addi	a0,a0,%lo(.LANCHOR0)
	addi	a2,a0,58
	li	a1,58
	j	.L2
.L3:
	addi	a5,a5,1
	beq	a5,a2,.L6
.L4:
	lbu	a3,0(a5)
	lbu	a4,1(a5)
	bleu	a3,a4,.L3
	sb	a3,1(a5)
	sb	a4,0(a5)
	j	.L3
.L6:
	addi	a1,a1,-1
	addi	a2,a2,-1
	beqz	a1,.L5
.L2:
	mv	a5,a0
	bgtz	a1,.L4
	j	.L6
.L5:
	li	a0,0
	ret
	.size	main, .-main
	.globl	bsort_input_len
	.globl	bsort_input
	.data
	.align	2
	.set	.LANCHOR0,. + 0
	.type	bsort_input, @object
	.size	bsort_input, 59
bsort_input:
	.byte	83
	.byte	105
	.byte	110
	.byte	103
	.byte	32
	.byte	116
	.byte	111
	.byte	32
	.byte	109
	.byte	101
	.byte	32
	.byte	111
	.byte	102
	.byte	32
	.byte	116
	.byte	104
	.byte	101
	.byte	32
	.byte	109
	.byte	97
	.byte	110
	.byte	44
	.byte	32
	.byte	77
	.byte	117
	.byte	115
	.byte	101
	.byte	44
	.byte	32
	.byte	116
	.byte	104
	.byte	101
	.byte	32
	.byte	109
	.byte	97
	.byte	110
	.byte	32
	.byte	111
	.byte	102
	.byte	32
	.byte	116
	.byte	119
	.byte	105
	.byte	115
	.byte	116
	.byte	115
	.byte	32
	.byte	97
	.byte	110
	.byte	100
	.byte	32
	.byte	116
	.byte	117
	.byte	114
	.byte	110
	.byte	115
	.byte	46
	.byte	46
	.byte	46
	.section	.srodata,"a"
	.align	2
	.type	bsort_input_len, @object
	.size	bsort_input_len, 4
bsort_input_len:
	.word	59
	.ident	"GCC: (GNU) 8.2.0"
