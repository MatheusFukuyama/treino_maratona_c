#include<stdio.h>

void bubble(int tam, int *vetor);

int main() {
	int i, numCompetidores, populacao=0, maior = 0;
	
	scanf("%d", &numCompetidores);
	
	if(numCompetidores < 2 || numCompetidores > 10000 )
		return 0;
	
	int votos[numCompetidores];

	for(i=0; i<numCompetidores; i++) {
		scanf("%d", &votos[i]);
		populacao += votos[i];
		
		if(votos[i] > maior)
			maior = votos[i];
	}
	
	if(populacao > 100000)
		return 0;

	int carlos = votos[0];
	if(carlos == maior)
		printf("S\n");
	else
		printf("N\n");
	
	return 0;
}

