#include<stdio.h>

int main() {
	int numJogos, i, num, ganhou = 0;
	
	scanf("%d", &numJogos);
	
	for(i=0; i<numJogos; i++) {
		scanf("%d", &num);
		if(num != 1)
			ganhou++;
	}

	printf("%d\n", ganhou);
	
	return 0;
}
