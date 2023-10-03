FLAG_ROWS = 6
FLAG_COLS = 12
	
	.data
flag:
	# ugly .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

	.text
main:

	li	$t0, 0	# row in t0
row_loop:	
row_loop_cond:
	bge	$t0, FLAG_ROWS, row_loop_end
row_loop_body:	

	li	$t1, 0	# col in t1
col_loop:	
col_loop_cond:	
	bge	$t1, FLAG_COLS, col_loop_end
col_loop_body:
	# offset in $t2
	# offset from rows
	mul	$t2, $t0, FLAG_COLS # offset from the row == row * FLAG_COLS
	add	$t2, $t2, $t1 # offset += offset from col

	
	lb	$a0, flag($t2) # $a0 = flag[row][col]
	li	$v0, 11
	syscall			# printf("%c", flag[row][col]);



	add	$t1, $t1, 1
	j	col_loop
col_loop_end:	

	li	$a0, '\n'
	li	$v0, 11
	syscall

	add	$t0, $t0, 1
	j	row_loop
row_loop_end:	

	li	$v0, 0
	jr	$ra    # return 0
