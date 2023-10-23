#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
	char texto[20];
	
	fgets(texto, 20, stdin);
	
	int i;
	for(i=0; i<strlen(texto); i++) {
		if(islower(texto[i]))
			return 0;
	}
	
	if(strcmp(texto, "FRIO\n") == 0)
		printf("%d\n", 24);
	else if(strcmp(texto, "QUENTE\n") == 0)
		printf("%d\n", 28);
	else if(strcmp(texto, "MUITO FRIO\n") == 0)
		printf("%d\n", 20);
	else if(strcmp(texto, "EXTREMAMENTE FRIO\n") == 0)
		printf("%d\n", 18);
	else
		printf("COMANDO INVALIDO\n");
	
	return 0;
}
