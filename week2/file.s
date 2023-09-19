	.text
main:
	li	$v0, 5
	syscall
	# int v0;
	# scanf("%d", &v0);
	

	move	$a0, $v0
	li	$v0, 1
	syscall # printf("%d", $v0);


	li	$v0, 0 # return 0
	jr	$ra
