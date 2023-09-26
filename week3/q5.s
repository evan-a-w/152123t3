N_SIZE = 10

	.data
numbers:
	.word	0:N_SIZE

	.text
main:
	# i in $t0

	li	$t0, 0
loop:
loop_cond:
	bge	$t0, N_SIZE, loop_end
loop_body:	
	li	$v0, 5
	syscall

	# save $v0 into numbers[i]
	mul	$t1, $t0, 4 # $t1 = i * 4

	# numbers + $t1 = &numbers[i]
	# numbers + $t1
	sw	$v0, numbers($t1) # $v0 into numbers + i * 4 == &numbers[i]

	# la	$t3, numbers
	# mul	$t1, $t0, 4
	# add	$t3, $t3, $t1
	# sw	$v0, ($t3) # $v0 into numbers + i * 4 == &numbers[i]

	add	$t0, $t0, 1

	# j in $t1
	li	$t1, 0
loop2_cond:
	bge	$t1, $t0, loop2_end
loop2_body:
	mul	$t2, $t1, 4 # $t2 = j * 4 = offset
	lw	$a0, numbers($t2) # $a0 = *(numbers + j * 4)
	li	$v0, 1
	syscall

	li	$a0, ' '
	li	$v0, 11
	syscall

loop2_step:
	add	$t1, $t1, 1
	j loop2_cond
loop2_end:

	li	$a0, '\n'
	li	$v0, 11
	syscall

loop_step:
	j	loop

loop_end:

	li	$v0, 0
	jr	$ra
