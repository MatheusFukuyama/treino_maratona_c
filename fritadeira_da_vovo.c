#include<stdio.h>

int main() {
	int celsius;
	float fah;
	
	scanf("%d", &celsius);
	
	fah = celsius * 1.8 + 32;
	
	printf("%d graus celsius equivale a %.0f graus fahrenheit\n", celsius, fah);
	return 0;
}
