#include<stdio.h>

int main() {
	int credito1, credito2, credito3;
	
	scanf("%d%d%d", &credito1, &credito2, &credito3);
	
	int credito12 = credito1 + credito2;
	int credito13 = credito1 + credito3;
	int credito23 = credito2 + credito3;
	
	if(credito1 == credito2 || credito1 == credito3 || credito2 == credito3)
		printf("S\n");
	else if(credito12 == credito3 || credito13 == credito2 || credito23 == credito1)
		printf("S\n");
	else
		printf("N\n");
	
	return 0;
		
}

