	global product:
	global power:

	section .text

product:

	xor rax, rax
	xor r10, r10

start:
	
	cmp r10, rsi
	je  done
	add rax, rdi
	inc r10
	jmp start

done:
	ret

power:
	cmp  rsi, 1
	je   powdone	
	cmp  rax, rdi
	je   precall
	mov  rcx, rdi
precall:mov  rdx, rsi
	mov  rsi, rcx
call:	call product
	mov  rsi, rdx
	mov  rdi, rax
	dec  rsi
	call power

powdone:
	ret
