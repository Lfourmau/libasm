section .text
	global _asm_add
	_asm_add:
		inc rdi
		mov rax, rdi
		ret