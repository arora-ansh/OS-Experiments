global	long_add
section .text

long_add:
		push 	ebp
		mov 	ebp, esp
		sub		esp, 4
		push 	edi
		push	esi
		push	edx

		mov 	eax, [ebp+8]
		mov		esi, [ebp+12]
		mov		edi, [ebp+16]
		mov		edx, [ebp+20]

		mov		[ebp-4], edi
		add		[ebp-4], esi
		add 	[ebp-4], edx
		add 	eax, [ebp-4]

		pop 	esi
		pop 	edi
		pop 	edx
		mov 	esp, ebp
		pop 	ebp
		ret