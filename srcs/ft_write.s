section .text
	global _ft_write
	_ft_write:
		cmp byte [rsi], 0x00
		je .empty
		mov	rax,0x2000004
		syscall
		ret
	
	.empty:
		mov rax, 0
		ret
