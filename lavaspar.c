#include<stdio.h>
#include<string.h>

int count = 0;
int palavrasAchadas=0;

int verificaLetra (char letra, char palavra[]) {
	int i;
	for(i=0; i<strlen(palavra); i++) {
		if(palavra[i] == letra){
			return 1;
		}
	}
	return 0;
}

void verificaPalavra(int qntLinha, int qntColuna, char palavra[], char jogo[][qntColuna], int posicaoLinha, int posicaoColuna, int passou[][qntColuna]) {
	int i, j;
	count++;
	passou[posicaoLinha][posicaoColuna] = 1;
	if(count == strlen(palavra))
		palavrasAchadas++;
	
	if(verificaLetra(jogo[posicaoLinha-1][posicaoColuna], palavra) && posicaoLinha > 0) {
		verificaPalavra(jogo[posicaoLinha-1][posicaoColuna], palavra);
		count--;
	} 
	if(verificaLetra(jogo[posicaoLinha+1][posicaoColuna], palavra) && posicaoLinha < qntLinha) {
		verificaPalavra(jogo[posicaoLinha-1][posicaoColuna], palavra);
		count--;
	}
	if(verificaLetra(jogo[posicaoLinha][posicaoColuna-1], palavra) && posicaoColuna > 0) {
		verificaPalavra(jogo[posicaoLinha][posicaoColuna-1], palavra);
		count--;
	} 
	if(verificaLetra(jogo[posicaoLinha][posicaoColuna+1], palavra) && posicaoLinha < qntLinha) {
		verificaPalavra(jogo[posicaoLinha][posicaoColuna+1], palavra);
		count--;
	}
}


int main() {
	int tamLinha, tamColuna;
	
	scanf("%d%d", &tamLinha, &tamColuna);
	
	char jogo[tamLinha][tamColuna];
	int passoi[tamLinha][tamColuna];
	
	int i,j;
	for(i=0; i<tamLinha; i++) {
		for(j=0; j<tamColuna; j++) {
			scanf(" %c", &jogo[tamLinha][tamColuna]);
			passou[i][j] = 0;
		}
	}
	
	int qntPalavras, k;
	
	scanf("%d", &qntPalavras);
	
	char palavra[1001];
	for(i=0; i<qntPalavras; i++) {
		scanf("%s", palavra);
		for(k=0; k<tamLinha; k++)
			for(j=0; j<tamColuna; j++)
				if(passou != 1 && verificaLetra(jogo[k][j]))
				verificaPalavra(tamLinha, tamColuna, palavra, jogo, 0, 0, passou);
	}
}
