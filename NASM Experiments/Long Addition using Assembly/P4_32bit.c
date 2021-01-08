#include <stdio.h>
#include <inttypes.h>

int32_t long_add(int32_t,int32_t,int32_t,int32_t);

int64_t extended_add(int64_t,int64_t,int64_t,int64_t);

int main(){
	//Code for 32-bit which utilizes long_add function
	
	int x,y,z,w;
	scanf("%d%d%d%d",&x,&y,&z,&w);
	int sum = long_add(x,y,z,w);
	printf("%d\n", sum);
	
	
	//Code for 64-bit which utilizes extended_add function
	/*
	int64_t a,b,c,d;
	scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
	long long int sum = extended_add(a,b,c,d);
	printf("%lld\n", sum);
	return 0;
	*/
}