section .text
	global _ft_strlen
	_ft_strlen:
		mov rax, 0
		cmp byte [rdi], 0x00
		jne .loop
		ret
    .loop:
		inc rdi,
		inc rax,
		cmp byte [rdi], 0x00
		jne .loop
		ret