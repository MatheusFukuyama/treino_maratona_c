#include<stdio.h>

int main() {
	int a1, a2, a3;
	
	scanf("%d%d%d", &a1, &a2, &a3);
	
	int primeiro = a2*2 + a3*4;
	int segundo = a1*2 + a3*2;
	int terceiro = a1*4 + a2*2;
	
	if(primeiro > segundo)
		if(segundo > terceiro)
			printf("%d\n", terceiro);
		else
			printf("%d\n", segundo);
			
	else if(primeiro < segundo)
		if(primeiro > terceiro)
			printf("%d\n", terceiro);
		else
			printf("%d\n", primeiro);
	else
		if(segundo > terceiro)
			printf("%d\n", terceiro);
		else
			printf("%d\n", segundo);
		
	return 0;
		
}

