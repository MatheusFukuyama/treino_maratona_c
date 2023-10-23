#include<stdio.h>

int igual(int m, int lampadas[], int inicial[]) {
	int i;
	for(i=0; i<m; i++)
		if(lampadas[i] != inicial[i])
			return 0;
			
	return 1;
}

int verificaDesligado (int m, int lampadas[]) {
	int i;
	for(i=0; i<m; i++)
		if(lampadas[i] != 0)
			return 0;
	
	return 1;
}

int main(){
	int n, m, i;
	
	scanf("%d%d", &n, &m);
	int interruptores[n][m], lampadas[m];
	
	int qntAceso;
	
	scanf("%d", &qntAceso);
	
	int aceso, inicial[m];
	
	for(i = 0; i < m; i++) {
		lampadas[i] = 0;
		inicial[i] = 0;
	} 
	
	
	for(i = 0; i < qntAceso; i++) {
		scanf("%d", &aceso);
		
		lampadas[aceso-1] = 1;
		inicial[aceso-1] = 1;
	} 
	
	int j, tam[n], k = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &tam[k]);
		for(j=0; j < tam[k]; j++) {
			scanf("%d", &interruptores[i][j]);
		}
		k++;
	} 
	
	i = 0;
	int turno = 0;
	while(!igual(m, lampadas, inicial) || (i != 0) || turno==0) {
		turno++;
		for(j=0; j < tam[i]; j++)
			if(lampadas[interruptores[i][j]-1] == 0)
				lampadas[interruptores[i][j]-1] = 1;
			else
				lampadas[interruptores[i][j]-1] = 0;
		
		if(verificaDesligado(m, lampadas)){
			printf("%d\n", turno);
			return 0;
		}
			
		i++;
		
		if(i >= n)
			i=0;
			

	}
	
	printf("-1\n");
	return 0;
	
}
