#include<stdio.h>

int main() {
	int quantidade, i, num, out = 0;
	
	scanf("%d", &quantidade);
	
	for(i=0; i<quantidade; i++) {
		scanf("%d", &num);
		if(num < 10 || num > 20 ){
			out++;
		}
	}

	printf("%d in\n", quantidade - out);
	printf("%d out\n", out);
	
	return 0;
}
