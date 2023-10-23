 #include<stdio.h>
 
 int direita = 0;
 int esquerda = 0;
 int max = 0;
 int borda = 0;
 
void verificarDireita(int tamLinha, int linha[], int posicao, int altura)  {
 		direita++;
 		if(linha[posicao+1] >= altura && posicao < tamLinha-1) {
 			if(posicao == tamLinha-1)
 				borda = 1;
 				
 			verificarDireita(tamLinha, linha, posicao+1, altura-1);
 		}
}


void verificarEsquerda(int linha[], int posicao, int altura)  {
 		esquerda++;
 		if(linha[posicao-1] >= altura && posicao > 0){
 			if(posicao == 0)
	 			borda = 1;
	 		
	 		verificarEsquerda(linha, posicao-1, altura-1);
	 	}
}
 
 
 int verificarIsoceles(int tamLinha, int linha[], int posicao, int altura)  {
 		if(linha[posicao] == 0 || linha[posicao] == tamLinha-1)
 			return 0;
 			
 		if(altura <= max)
 			return 0;
 		
 		verificarDireita(tamLinha, linha, posicao, altura);
 		verificarEsquerda(linha, posicao, altura);
 		
 		if(direita > esquerda)
 			if(esquerda > max){
 				max = esquerda;
 				return 0;
 			}
		else
			if(direita > max){
 				max = direita;
 				return 0;
 			}
		 		
 		if(borda) {
 			return 0;
		}
 		
 	return 1;		
 }
 
 int main() {
 	int i, j, k;
 	int tamLinha, continuar = 1, subtrairAltura = 0;
	
	scanf("%d", &tamLinha);
	
	if(tamLinha > 50000)
		return 0;
	
	int linha[tamLinha];
	
	for(i =0; i < tamLinha; i++) {
		scanf("%d", &linha[i]);
		
		if(linha[i] > tamLinha || linha[i] < 1)
			return 0;
	}
 	
	for(i=0; i < tamLinha; i++) {
		while(continuar){
			continuar = verificarIsoceles(tamLinha, linha, i, linha[i] - subtrairAltura);
			
		    direita  = 0;
	 		esquerda = 0;
	 		borda = 1;
	 		
	 		subtrairAltura++;
 		}
 		continuar = 1;
 		subtrairAltura = 0;
	}
	
	max -= 1;
	printf("%d\n", max);
	return 0;
}
