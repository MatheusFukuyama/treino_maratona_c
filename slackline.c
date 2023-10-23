#include<stdio.h>
#include<math.h>

int main() {
	int linha, coluna, min, max, maiorDistancia;
	
	scanf("%d%d%d%d", &linha, &coluna, &min, &max);
	
	int variacao = 0;
	if(min == 1 )
		variacao = (linha*coluna) + ((linha-1)*(coluna-2)) + ((linha-2)*(coluna-1));
	
	if(max <= coluna-1)
		maiorDistancia = max-1;
	else
		maiorDistancia = coluna-1;
	
	variacao += (((linha-1)*(coluna-1))*maiorDistancia);
	
	if(max <= linha-1)
		maiorDistancia = max-1;
	else
		maiorDistancia = linha-1;
	
	
	variacao += (((linha-1)*(coluna-1))*maiorDistancia);
	
	printf("%d\n", variacao);
	return 0;
		
}
