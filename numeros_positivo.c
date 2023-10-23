#include<stdio.h>

int main() {
	int i, cont=0;
	float num[6];
	
	for(i=0; i<6; i++) {
		scanf("%f", &num[i]);
		if(num[i] > 0)
			cont++;
	}

	printf("%d valores positivos\n", cont);
	
	return 0;
}
