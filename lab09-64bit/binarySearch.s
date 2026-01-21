	global binarySearch:

	section .txt

binarySearch:
	
loop:

	cmp rsi, rdx
	jg  nf
	
	mov r8, rsi
	add r8, rdx
	shr r8, 1
	cmp dword [rdi+4*r8], ecx
	jl  less
	jg  great
	jmp done

less:

	inc r8
	mov rsi, r8
	jmp loop

great:

	dec r8
	mov rdx, r8
	jmp loop

	
done:
	
	mov rax, r8
	ret

nf:
	
	mov rax, -1
	ret
