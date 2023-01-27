section .text
	global _ft_read
	_ft_read:
		push rsi
		mov	rax,0x2000003
		syscall	; call kernel
		pop rsi
		ret