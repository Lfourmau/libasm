section .text
	global _ft_strcpy
	_ft_strcpy:
		push rdi
	.loop:
		cmp byte [rsi], 0x00
		jz .return
		movsb
		jmp .loop
	.return:
		mov byte [rdi], 0
		pop rax
		ret

