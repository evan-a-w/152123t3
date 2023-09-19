SQUARE_MAX = 46340

	.text
main:
	# x is t0, y is t1

	la	$a0, str
	li	$v0, 4
	syscall # printf("Enter a number: ");

	li	$v0, 5
	syscall
	move	$t0, $v0 # scanf("%d", &x);

	bgt	$t0, SQUARE_MAX, too_big # if (x > SQUARE_MAX)
print_square:	
	mul	$t1, $t0, $t0	# y = x * x

	li	$v0, 1
	move	$a0, $t1
	syscall 	# printf("%d\n", y);

	li	$v0, 11
	li	$a0, '\n'
	syscall		# printf("%c", '\n');

	j	end

too_big:
	li	$v0, 4
	la	$a0, too_big_str
	syscall

end:	
	li	$v0, 0
	jr	$ra

	.data
str: # str is a char *
	.asciiz "Enter a number: "
too_big_str:
	.asciiz "square too big for 32 bits\n"
