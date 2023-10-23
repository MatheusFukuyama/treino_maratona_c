#include<stdio.h>

void bubble(int tam, int *vetor);

int main() {
	int i, numCompetidores, minClassificado,classificados = 0;
	
	scanf("%d%d", &numCompetidores, &minClassificado);
	
	int competidores[numCompetidores];
	
	for(i=0; i<numCompetidores; i++) {
		scanf("%d", &competidores[i]);
	}

	bubble(numCompetidores, competidores);
	
	for(classificados = minClassificado-1; competidores[classificados] == competidores[classificados+1]; classificados++){
	}
	classificados += 1;
	
	printf("%d\n", classificados);
	
	return 0;
}

void bubble(int tam, int *v)
{
	int a,b,c;
	
	for(a=1;a<tam;a++)
	{
		for(b=tam-1; b>=a; b--)
		{
			if(v[b] > v[b-1])
			{
				c = v[b];
				v[b] = v[b-1];
				v[b-1] = c;
			}
		}
	}
}
