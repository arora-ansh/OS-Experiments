#include<stdio.h>

int main(){

	int i = 50; // Integer i
	int *p; // Pointer to integer
	int **m; // Pointer to int pointer
	p = &i; // p now points to i
	printf("%p %d \n", p, *p); // Prints the address of i (in p)
	m = &p; // m now points to p
	printf("%p %p \n", m, *m); // Prints the address of p (in m)
	return 0;
}