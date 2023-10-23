#include<stdio.h>

int main() {
	int idade, anos, meses, dias;
	
	scanf("%d", &idade);
	
	anos = idade/365;
	
	idade %= 365;
	
	meses = idade/30;
	
	idade %= 30;
	
	dias = idade;
	
	printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
	return 0;
}
