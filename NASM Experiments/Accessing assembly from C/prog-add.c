#include <stdio.h>
#include <inttypes.h>

int64_t add(int64_t,int64_t);

int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	int sum = add(x,y);
	printf("%d\n", sum);
	return 0;
}