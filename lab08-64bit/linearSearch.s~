	global linearSort:

	section .txt

linearSort:
	mov rax, -1
	xor rcx, rcx

start:	
	cmp rsi, rcx
	je  done
	cmp rdx, [rdi+4*rcx]
	jne loop
	mov rax, rcx
	jmp done	
loop:
	inc rcx
	jmp start

done:
	ret
	
