#include<stdio.h>

int main() {
	float a,b,c, areaPeri;
	
	scanf("%f%f%f", &a,&b,&c);
	
	if((a+b) > c && (c+b) > a && (a+c) > b) {
		areaPeri = a + b + c;
		printf("Perimetro = %.1f\n", areaPeri);
	}
	else {
		areaPeri = ((a + b) * c)/2;
		printf("Area = %.1f\n", areaPeri);
	}
	return 0;
}
