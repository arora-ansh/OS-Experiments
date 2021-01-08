# Ansh Arora 2019022
# Program thatt uses NASM assembly code to add two numbers inputted by the user into the C Program, which then prints it out.

# For step by step compilation, call the following preceded by make

default:
	nasm -felf64 add.asm
	gcc prog-add.c add.o
	./a.out

# The NASM assembler assembles the asm files and produces a binary .o file for compilation
assemble_asm:
	nasm -felf64 add.asm

# In this step, the gcc compiler links the binary file produced from the assembly code with the C program code
link-compile:
	gcc prog-add.c add.o

#Runs the a executable file produced after the linking of the two files
run:
	./a.out

# To run the whole program at once, run make runprog
runprog:
	nasm -felf64 add.asm
	gcc prog-add.c add.o
	./a.out

# To clear out files and reset the compilation, run make clear
clear:
	rm a.out *.o

