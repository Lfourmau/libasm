section .text
	global _ft_strcmp
	_ft_strcmp:
		mov byte al, [rdi]
		mov byte cl, [rsi]
		movsx rax, al
		movsx rcx, cl
		sub rax, rcx
		jne .return
		cmp byte [rdi], 0x00
		je .return
		cmp byte [rsi], 0x00
		je .return
		inc rdi
		inc rsi
		jmp _ft_strcmp
	.return:
		ret