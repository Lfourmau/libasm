section .text
	global _ft_strcmp
	_ft_strcmp:
		mov byte al, [rdi]
		mov byte cl, [rsi]
		movsx rax, al
		movsx rcx, cl
		sub rax, rcx
		jz .loop
		ret
	.loop:
		inc rdi
		inc rsi
		mov byte al, [rdi]
		mov byte cl, [rsi]
		movsx rax, al
		movsx rcx, cl
		sub rax, rcx
		jz .loop
		ret