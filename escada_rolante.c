#include<stdio.h>

int main() {
	int n;
	
	scanf("%d", &n);
	
	int momento0[n];
	int momento1[n];
	
	
	int i, momento, direcao, j = 0, k = 0;
	for(i=0; i<n; i++) {
		scanf("%d%d", &momento, &direcao);
		if(direcao == 0) {
			momento0[j] = momento;
			j++;
		} else {
			momento1[k] = momento;
			k++;
		}
	}
	
	momento0[j] = -1;
	momento1[k] = -1;
	
	
	int esquerda = 0;
	if(momento0[0] < momento1[0] && momento0[0]) {
		esquerda = 1;
	} else if(momento1[0] == -1) {
		esquerda = 1;
	} 
	
	j=0;k=0;
	int count = 0;
	while(momento0[j] != -1 || momento1[k] != -1) {
		if(esquerda) {
			
			if(count == 0) {
				count = momento0[0] + 10;
				j++;
			}
			while(momento0[j] < count && momento0[j] != -1) {
				count = momento0[j] + 10;
				j++;
			}
			if(momento1[k] < count && momento1[k] != -1) {
				esquerda = 0;
				count += 10;
				while(momento1[k] < count && momento1[k] != -1) {
					k++;
				}
			} else if(momento0[j] > count && momento1[k] > count){
				printf("qui n pode\n");
				if(momento0[j] < momento1[k]) {
						count = momento0[j] + 10;
						esquerda = 1;
						j++;
					} else {
						count = momento1[k] + 10;
						esquerda = 0;
						k++;
					}
			}
			
		} else {
			if(count == 0) {
				count = momento1[0] + 10;
				k++;
			}
			while(momento1[k] < count && momento1[k] != -1) {
				count = momento1[k] + 10;
				k++;
			}
			if(momento0[j] < count) {
				esquerda = 1;
				count += 10;
				while(momento0[j] < count && momento0[j] != -1) {
					j++;
				}
			} else if(momento0[j] > count && momento1[k] > count){
				if(momento0[j] < momento1[k]) {
						count = momento0[j] + 10;
						esquerda = 1;
						j++;
					} else {
						count = momento1[k] + 10;
						esquerda = 0;
						k++;
					}
			}
			
		}
	}
	
	printf("%d\n", count);
	return 0;
}

