global _start
global checkGreater

section .text

_start:	  mov 		rdi, 9					; rdi assigned the value 9(x)
		  mov 		rsi, 11					; rsi assigned the value 11(y)

checkGreater:
		  cmp		rdi,rsi				; compares r8 and r9
		  jg		optiona					; jumps to optiona if x>y to print 1
		  jmp 		optionb				; otherwise jumps to optionn b

optiona:  mov       rax, 1                  ; system call for write
          mov       rdi, 1                  ; for stdout
          mov       rsi, messagea           ; address of string for output
          mov       rdx, 2                  ; number of bytes in messagea
          syscall                           
          mov       rax, 60                 ; system call for exit
          xor       rdi, rdi                ; exit code 0
          syscall                           

          section   .data
messagea: db        "1", 10      			; Writes out a 1 using syscall

optionb:  mov       rax, 1                  ; system call for write
          mov       rdi, 1                  ; for stdout
          mov       rsi, messageb           ; address of string for output
          mov       rdx, 2                  ; number of bytes in messageb
          syscall                           
          mov       rax, 60                 ; system call for exit
          xor       rdi, rdi                ; exit code 0
          syscall                           

          section   .data
messageb: db        "0", 10      			;Writes out a 0 using syscall