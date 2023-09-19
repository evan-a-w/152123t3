	.text
main:
	# x in $t0, y in $t1

	la	$a0, str
	li	$v0, 4
	syscall # printf("Enter a number: ");

	li	$v0, 5
	syscall
	move	$t0, $v0 # scanf("%d", &x);

	mul	$t1, $t0, $t0	# y = x * x

	li	$v0, 1
	move	$a0, $t1
	syscall 	# printf("%d\n", y);

	li	$v0, 11
	li	$a0, '\n'
	syscall		# printf("%c", '\n');

	li	$v0, 0
	jr	$ra

	.data
str: # str is a char *
	.asciiz "Enter a number: "
