	.text
main:
	li	$t0, 24
loop_begin:
loop_condition:
	bge	$t0, 42, end
loop_body:
	li	$v0, 1
	move	$a0, $t0
	syscall
loop_step:
	add	$t0, $t0, 3
	j	loop_begin

end:	
	li	$v0, 0
	jr	$ra
