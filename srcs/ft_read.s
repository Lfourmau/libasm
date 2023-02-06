extern __errno_location

section .text
	global _ft_read
	_ft_read:
		mov	rax,0 ;0x2000003
		syscall	; call kernel
		cmp rax, 0
    	jl .error
		ret
	.error:
		neg rax    ; get absolute value of syscall return
		mov rdi, rax
		call __errno_location WRT ..plt
		mov [rax], rdi  ; set the value of errno
		mov rax, -1
		ret
