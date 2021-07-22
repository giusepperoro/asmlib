section	.text
global	_ft_strcmp
_ft_strcmp:
			xor	rax, rax
			xor	rcx, rcx
			jmp	loop
result:
			movzx	rax, al
			movzx	rbx, bl
			sub		rax, rbx
			ret
loop:
			mov	al, BYTE[rdi + rcx]
			mov	bl, BYTE[rsi + rcx]
			cmp	al, bl
			jne	result
			cmp	al, 0
			je	result
			cmp	bl, 0
			je	result
			inc	rcx
			jmp	loop

