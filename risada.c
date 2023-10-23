#include<stdio.h>
#include<string.h>

void separarVogais(char risada[], char vogais[]) {
	int i, j=0;
	
	for(i=0; i < strlen(risada); i++) {
		if(risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u') {
			vogais[j] = risada[i];
			j++;
		}
	}
	vogais[j] = '\0';
}

int verificarPalindromo(char vogais[]) {
	int i, j=0;
	char inv[51];
	for(i = strlen(vogais) - 1; i >= 0; i--) {
			inv[j] = vogais[i];
			j++;
	}
	
	inv[j] = '\0';
	
	
	for(i = 0; i < strlen(vogais); i++) {
		if(inv[i] != vogais[i])
			return 0;
	}
	
	
	return 1;
}

int main() {
	char risada[51], vogais[51];
	
	scanf("%s", risada);
	
	separarVogais(risada, vogais);
	
	if(verificarPalindromo(vogais))
		printf("S\n");
	else
		printf("N\n");
	
	return 0;
}
