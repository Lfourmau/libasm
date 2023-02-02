section .text
	global _ft_write
	_ft_write:
		;check the fd and jump to ret if < 0 ?
		mov	rax,0x2000004
		syscall
		ret
	.ret:
		mov rax, -1
		ret
		;return the value for a bad fd

