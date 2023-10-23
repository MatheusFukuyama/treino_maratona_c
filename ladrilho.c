#include<stdio.h>

int cont = 0;

void calcularMenorArea(int tamLinha, int tamColuna, int ladrilho[][tamColuna], int visitado[][tamColuna], int linha, int coluna) {
	cont++;
	visitado[linha][coluna] = 1;
	if(ladrilho[linha][coluna] == ladrilho[linha][coluna+1] && coluna < tamColuna - 1 && visitado[linha][coluna+1] == 0){
		calcularMenorArea(tamLinha, tamColuna, ladrilho, visitado, linha, coluna + 1);
	} 
	
	if(ladrilho[linha][coluna] == ladrilho[linha][coluna-1] && coluna > 0 && visitado[linha][coluna-1] == 0){
		calcularMenorArea(tamLinha, tamColuna, ladrilho, visitado, linha, coluna - 1);
	} 
	
	if(ladrilho[linha][coluna] == ladrilho[linha+1][coluna] && linha < tamLinha - 1 && visitado[linha+1][coluna] == 0){
		calcularMenorArea(tamLinha, tamColuna, ladrilho, visitado, linha+1, coluna);
	} 
	
	if(ladrilho[linha][coluna] == ladrilho[linha-1][coluna] && linha > 0 && visitado[linha-1][coluna] == 0){
		calcularMenorArea(tamLinha, tamColuna, ladrilho, visitado, linha-1, coluna);
	}
	
}


int main() {
	int i, j, tamLinha, tamColuna;
	int menorArea = 40000;
	
	scanf("%d%d", &tamLinha, &tamColuna);
	
	if((tamLinha < 1 || tamLinha > 200) || (tamColuna < 1 || tamColuna > 200))
		return 0;
	
	
	int ladrilho[tamLinha][tamColuna];
	int visitado[tamLinha][tamColuna];
	
	for(i = 0; i < tamLinha; i++) {
		for(j = 0; j < tamColuna; j++) {
			scanf("%d", &ladrilho[i][j]);
			visitado[i][j] = 0;
			
			if(ladrilho[i][j] < 0 || ladrilho[i][j] > 40000)
				return 0;
		}
	}
	
	for(i = 0; i < tamLinha; i++) {
		for(j = 0; j < tamColuna; j++) {
			if(visitado[i][j] == 0) {
				calcularMenorArea(tamLinha, tamColuna, ladrilho, visitado, i, j);
				if(cont < menorArea){
					menorArea = cont;
				}
				
				cont = 0;
			}
		}
	}

	printf("%d\n", menorArea);
	
	return 0;
	
}
