extern __errno_location

section .text
	global _ft_write
	_ft_write:
		mov	rax,1; 0x2000004
		syscall
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

