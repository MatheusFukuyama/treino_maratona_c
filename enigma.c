	#include<stdio.h>
	#include<stdio.h>
	
	int main() {
		char cifra[10001], crib[27];
		
		scanf("%s%s", cifra, crib);
		
		
		int i, j, k, cabe = 0;
		for(k=0; k < strlen(cifra) - strlen(crib) + 1; k++){
			j=0;
			for(i = k; i < strlen(cifra); i++) {
				if(cifra[i] == crib[j]){
					break;
				}
				if(j == strlen(crib)-1){
					cabe++;
					break;
				}
				j++;
			}
		}
		
		
		printf("%d\n", cabe);
		
		return 0;
	}
