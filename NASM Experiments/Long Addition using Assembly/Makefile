32bit:
	nasm -felf32 P4_1.asm
	gcc -m32 P4_1.o P4_32bit.c 
	./a.out

64bit:
	nasm -felf64 P4_2.asm
	gcc P4_2.o P4_64bit.c 
	./a.out

clear:
	rm a.out *.o