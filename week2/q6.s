	.text
main:
	# x in $t0
	# (x > 100 && x < 1000)
	bgt	$t0, 100, greater_100
	j	small_big

greater_100:
	blt	$t0, 1000, small_big

medium:
	# printf("medium\n")	;

small_big:	
	# printf("small/big\n")	;


	# (x > 100 || x < 1000)
	bgt	$t0, 100, true
	blt	$t0, 1000, true

false:


true:	

	li	$v0, 0
	jr	$ra
	
