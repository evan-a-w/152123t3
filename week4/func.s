	.text
main:	
	#move	$t0, $ra
	# ra is where we need to return to
	push	$ra
	jal func
	# OVERWRITE the value of $ra that we need

	# saves the address of the following instruction
	# into $ra and jumps to func

return_address:	


	li	$a0, 2
	li	$a1, 3
	jal	add
	# overwrites $ra to second_return_address
	# the result is in $v0
	# $v0 = add(2, 3)

second_return_address:	
	move	$a0, $v0
	li	$v0, 1
	syscall

	#move	$ra, $t0
	pop	$ra
	li	$v0, 0
	jr	$ra


func:
	jr	$ra

add: #adds two numbers
	# expect a number in $a0
	# and a number in $a1
	# int add(int a, int b) { return a + b; }
	# a in $a0
	# b in $a1
	add	$t0, $a0, $a1
	move	$v0, $t0
	jr	$ra


	
