#include<stdio.h>
#include<math.h>
int main() {
	float n, a, b;
	
	
	scanf("%f%f%f", &n,&a,&b);
	
	float media = ((a+b)/2);
	float result = n / media;
	
	printf("%f\n", result);
}
