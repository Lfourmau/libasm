extern _ft_strlen
extern _malloc
extern _ft_strcpy

section .text
	global _ft_strdup
	_ft_strdup:
		cmp byte [rdi], 0x00
		jz .return
		push rdi ;stocker rdi (la chaine) avant le strlen
		call _ft_strlen ;call strlen qui va mettre le ret dans rax
		mov rdi, rax ;on veut donner le strlen en arg au malloc
		inc rdi
		call _malloc ; malloc appelé avec rdi en arg
		pop rsi ;on remet la chaine dans rsi et on a l'espace dans rax
		push rax ;on garde le debut pour le return plus tard
		mov rdi, rax
		call _ft_strcpy
		pop rax
		ret
	.return:
		ret