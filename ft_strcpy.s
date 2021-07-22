section	.text
global	_ft_strcpy
_ft_strcpy:
			xor	rcx, rcx
			jmp	loop
loop:
			mov	bl, byte[rsi + rcx]
			cmp	bl, 0
			je	result
			mov	[rdi + rcx], bl
			inc	rcx
			jmp	loop
result:
			mov	byte[rdi + rcx], 0
			mov	rax, rdi
			ret
