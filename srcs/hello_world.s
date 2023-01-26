section .data
hello:
	extern _printf
	.string db "Hello World!", 10
	.len equ $ - hello.string
	push rbp
	mov rbp,rsp
	sub rsp,16
	lea rdi, [rel hello.string]
	call _printf
	leave
	ret

section .text
	global start
	global _main
	extern _printf

start:
	push rbp
	mov rbp,rsp
	sub rsp,16
	lea rdi, [rel hello.string]
	call _printf
	leave
	ret