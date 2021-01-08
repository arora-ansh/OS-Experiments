#include <stdio.h>
 
int main(){
	int a = 10;
	int b = 20;
	int c = a*b;
	printf("a = %10d b = %5d c = %d \n", a, b, c);
	float d = 0.95;
	printf("%5.2f %%",d*100);
	return 0;
}
