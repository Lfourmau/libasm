section .text
	global _ft_strcmp
	_ft_strcmp:
		cmp byte [rdi], 0x00
		je .return
		cmp byte [rsi], 0x00
		je .return
		mov byte al, [rdi]
		mov byte cl, [rsi]
		movsx rax, al
		movsx rcx, cl
		sub rax, rcx
		inc rdi
		inc rsi
		jz _ft_strcmp
		ret
	.return:
		ret