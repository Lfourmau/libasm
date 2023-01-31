section .text
	global _ft_strcmp
	_ft_strcmp:
		cmp byte [rdi], 0x00
		jz .return
		jmp .loop
		ret
	.loop:
		cmp byte [rdi], 0x00
		jz .return
		mov byte al, [rdi]
		mov byte cl, [rsi]
		movsx rax, al
		movsx rcx, cl
		inc rdi
		inc rsi
		sub rax, rcx
		jz .loop
	.return:
		ret