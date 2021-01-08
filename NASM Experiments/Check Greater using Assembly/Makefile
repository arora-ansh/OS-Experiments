A:
	nasm -felf64 checkGreater.asm
	ld checkGreater.o
	./a.out

B:
	nasm -felf64 checkGreater.asm
	gcc -c P1.c -o P1.o
	ld -e main P1.o checkGreater.o
	./a.out

clear:
	rm *.o 
	rm a.out