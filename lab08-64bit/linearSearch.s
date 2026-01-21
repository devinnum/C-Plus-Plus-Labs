	global linearSearch:

	section .txt

linearSearch:
	mov eax, -1
	xor ecx, ecx

start:	
	cmp esi, ecx
	je  done
	cmp edx, [edi+4*ecx]
	jne loop
	mov eax, ecx
	jmp done	
loop:
	inc ecx
	jmp start

done:
	ret
	
