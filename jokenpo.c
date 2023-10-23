#include<stdio.h>
#include<string.h>

int main() {
	char jogador1[10], jogador2[10];
	
	scanf("%s %s", jogador1, jogador2);
	printf("%s\n", jogador1);
	printf("%s\n", jogador2);
	if(strcmp(jogador1, "pedra")) {
		if(strcmp(jogador2, "pedra"))
			printf("Empate\n");
		else if(strcmp(jogador2, "tesoura"))
			printf("Jogador 1\n");
		else if(strcmp(jogador2, "papel"))
			printf("Jogador 2\n");
	} else if(strcmp(jogador1, "tesoura")) {
		if(strcmp(jogador2, "pedra"))
			printf("Jogador 2\n");
		else if(strcmp(jogador2, "tesoura"))
			printf("Empate\n");
		else if(strcmp(jogador2, "papel"))
			printf("Jogador 1\n");
	} else if(strcmp(jogador1, "papel")) {
		if(strcmp(jogador2, "pedra"))
			printf("Jogador 1\n");
		else if(strcmp(jogador2, "tesoura"))
			printf("Jogador 2\n");
		else if(strcmp(jogador2, "papel"))
			printf("Empate\n");
	}
}
