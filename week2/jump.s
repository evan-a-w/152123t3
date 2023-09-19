	.text
main:
	li	$a0, 2

	j	print
	# bne - branch not equal

	li	$a0, 1

print:	
	li	$v0, 1
	syscall # printf("%d", $v0);


	li	$v0, 0 # return 0
	jr	$ra
