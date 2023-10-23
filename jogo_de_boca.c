#include<stdio.h>
#include<string.h>

int main() {
	char number[101];
	
	scanf("%s", number);
	
	int tamanhoNum = strlen(number);
	int i, sum = 0;
	for(i=0; i<tamanhoNum; i++)
		sum += number[i] - '0';
	
	printf("%d\n", sum%3);
	return 0;
}
