#include<stdio.h>
#include<stdio.h>

int main() {
	char valor[9];
	
	scanf("%s", valor);
	
	int i;
	int soma;
	for(i=0; i<strlen(valor); i++) {
		soma =
	}
	
	int uni = valor[strlen(valor)-1] - '0';
	if(uni == 0) {
		printf("100000001");
	} else if(uni == 1) {
		printf("100000002");
	} else if(uni == 2) {
		printf("100000003");
	}else if(uni == 3) {
		printf("100000004");
	}else if(uni == 4) {
		printf("100000005");
	}else if(uni == 5) {
		printf("100000006");
	}else if(uni == 6) {
		printf("100000007");
	}else if(uni == 7) {
		printf("100000001");
	}
	
	return 0;
}
