#include<stdio.h>

int main(){
	int n, passos;
	
	while(scanf("%d", &n) != EOF){
		passos = 0;
		
		if(n < 1 || n > 1000000)
			return 0;
		
		while(n > 1) {
			if(n%2 == 0)
				n = n/2;
			else
				n = n * 3 + 1;
			passos++;
		} 
	
		printf("%d\n", passos);
	}
	
	return 0;
}
