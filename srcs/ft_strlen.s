section .text
	global _ft_strlen
	_ft_strlen:
		mov rax, 0              ; initialize strlen counter
		cmp byte [rdi], 0x00    ; if value at [rdi] is 0x00 return
		jne .loop               ; loop if not at end of string
		ret
    .loop:
		add rdi, 1              ; increment char * to next character
		add rax, 1              ; increment strlen counter
		cmp byte [rdi], 0x00    ; if value at [rdi] is 0x00 return
		jne .loop               ; loop if not at end of string
		ret

	                       ; jump back to input