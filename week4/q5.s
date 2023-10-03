	.text
main:
	# int result in $v0
main__prologue:	 # a prologue pushes on the stack
	push	$ra

main__body:
	li	$a0, 11
	li	$a1, 13
	li	$a2, 17
	li	$a3, 19
	jal	sum4 # int result = sum4(11, 13, 17, 19);

	move	$a0, $v0
	li	$v0, 1
	syscall  # prints the result of sum4

	li	$a0, '\n'
	li	$v0, 11
	syscall

main__epilogue:	 # an epilogue pops off the stack and returns
	pop	$ra

	li	$v0, 0
	jr	$ra # return 0

# int sum4(int a, int b, int c, int d)
sum4:
	# int a in $a0
	# int b in $a1
	# int c in $s0
	# int d in $s1
	# res1 in $s2
sum4__prologue:	
	push	$s0
	push	$s1
	push	$s2
	push	$ra

	move	$s0, $a2
	move	$s1, $a3
sum4__body:	
	# int res = sum2(a, b);
	move	$a0, $a0
	move	$a1, $a1
	jal	sum2 # this invalidates all non $s registers
	move	$s2, $v0 # $t0 = sum2(a, b)

	# int res2 = sum2(c, d);
	move	$a0, $s0
	move	$a1, $s1
	jal	sum2

	move	$a0, $s2
	move	$a1, $v0
	jal	sum2
	# $v0 = sum2(res1, res2)

sum4__epilogue:	
	pop	$ra
	pop	$s2
	pop	$s1
	pop	$s0

	jr	$ra

sum2:
	li	$a3, 0 # this is valid (tho pointless)
	add	$v0, $a0, $a1
	jr	$ra
