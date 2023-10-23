#include<stdio.h>
#include<math.h>

int main() {
	int testes;
	
	scanf("%d", &testes);
	
	int posicaoInicial;
	int qntVertice, qntAresta;
	
	int i, j, k, cont = 0;
	for(i=0; i< testes; i++) {
		cont = 0;
		scanf("%d%d%d", &posicaoInicial, &qntVertice, &qntAresta);
		
		int grafo[qntVertice][qntVertice];		
				
		for(j=0; j < qntVertice; j++) {
			for(k=0; k<qntVertice; k++) {
				grafo[j][k] = 0;
			}
		} 
		
		int areA, areB;
		for(j=0; j < qntAresta; j++){
			scanf("%d%d", &areA, &areB);
			
			grafo[areA][areB] = 1;
		}
		
		for(j=0; j < qntAresta; j++){
			for(k=0; k<qntVertice; k++) {
				if(grafo[j][k] == 1)
					if(grafo[k][j] == 1){
						grafo[k][j] = 0;
						cont++;
					}
			}
		}
		
		printf("%d\n", (qntVertice-cont)*2);
	}
	return 0;
	
}
