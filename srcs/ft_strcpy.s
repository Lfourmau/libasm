section .text
	global _ft_strcpy
	_ft_strcpy:
		push rdi
		cmp byte [rsi], 0x00 ;check si src est nulle
		;si src est null on ret
		jne .loop
		pop rax
		ret
	.loop:
		mov rax, [rsi]
		mov [rdi], rax ;move value from rsi to rdi
		inc rdi
		inc rsi
		cmp byte [rsi], 0x00
		jne .loop
		mov rdi, 0
		pop rax
		ret
