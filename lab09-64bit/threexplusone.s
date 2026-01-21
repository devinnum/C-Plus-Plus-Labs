				;My optimizations were to remove any pushing  or popping from the stack and to limit the number of branches to just two if  statements, one to check for base case and one to check if it's equal or odd. I aslo used "and" to and the input and 1 together and if it places 0 into rsi it is equal as my check. I also used shift left to multiply by two and then added itself one more time to effectively create the x3 then incremented by one. I also used shift right to divide by 2 if it is even.
	
	global threexplusone

	section .txt

threexplusone:

	xor  rax, rax
	cmp  rdi, 1
	je   done
	mov  rsi, 1
	and  rsi, rdi
	cmp  rsi, 0
	je   equal

odd:
	mov  rcx, rdi
	shl  rdi, 1
	add  rdi, rcx
	inc  rdi
	call threexplusone
	inc  rax
	jmp  done

equal:
	shr  rdi, 1
	call threexplusone
	inc  rax

done:
	ret
