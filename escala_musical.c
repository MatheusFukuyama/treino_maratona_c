#include<stdio.h>
#include<stdlib.h>

int Intercalar(int p, int q, int r, int v[])
{
	int i, j, k;
	int *w;
	
	w =  malloc ((r-p) * sizeof(int));
	
	i = p;
	j = q;
	k = 0;
	
	while(i < q && j < r)
	{
		if(v[i] <= v[j])
		{
			w[k++] = v[i++];
		}
		else{
			w[k++] = v[j++];
		}
	}
	
	while(i < q )
		w[k++] = v[i++];
	while(j < r)
		w[k++] = v[j++];
		for(i = p; i < r; i++)
		{
			 v[i] = w[i-p];
		}
		free (w);
		
}

void Mergesort(int p, int r, int v[])
{
	int i;
	if(p < r-1)
	{
		 	int q = ( r + p)/2;
		 	Mergesort(p, q, v);
		 	Mergesort(q, r, v);
		 	Intercalar(p, q, r, v);
			
	}
}

int count=12;

void possuiTom(int toms[][7], int nota, int possui[]) {
	int i, j;
	int naoPossui = 1;
	for(i=0; i < 12; i++) {
		if(possui[i]){
			for(j=0; j<7; j++) {
				if(toms[i][j] == nota)
					naoPossui = 0;
			}
			
			if(naoPossui){
				possui[i] = 0;
				count--;
			}
			naoPossui = 1;
		}
	}
}


int main() {
	int toms[12][7], possui[12];
	
	int i, j;
	for(i=0; i < 12; i++) {
		j=0;
		toms[i][j] = i+1;
		j++;
		if(toms[i][j-1] + 2 > 12)
			toms[i][j] = (toms[i][j-1] + 2)%12;
		else
			toms[i][j] = (toms[i][j-1] + 2);
		j++;
		if(toms[i][j-1] + 2 > 12)
			toms[i][j] = (toms[i][j-1] + 2)%12;
		else
			toms[i][j] = (toms[i][j-1] + 2);
		
		j++;
		if(toms[i][j-1] + 1 > 12)
			toms[i][j] = (toms[i][j-1] + 1)%12;
		else
			toms[i][j] = (toms[i][j-1] + 1);
		
		j++;
		if(toms[i][j-1] + 2 > 12)
			toms[i][j] = (toms[i][j-1] + 2)%12;
		else
			toms[i][j] = (toms[i][j-1] + 2);
		
		j++;
		if(toms[i][j-1] + 2 > 12)
			toms[i][j] = (toms[i][j-1] + 2)%12;
		else
			toms[i][j] = (toms[i][j-1] + 2);
		j++;
		if(toms[i][j-1] + 2 > 12)
			toms[i][j] = (toms[i][j-1] + 2)%12;
		else
			toms[i][j] = (toms[i][j-1] + 2);
		
		j++;
		possui[i] = 1;
	}
	
	int qntNotas;
	
	scanf("%d", &qntNotas);
	
	int notas[qntNotas];
	
	for(i=0; i < qntNotas; i++) {
		scanf("%d", &notas[i]);
		if(notas[i] > 12)
			notas[i] %= 12;
	}
	
	Mergesort(0, qntNotas, notas);
	
	for(i=0; i < qntNotas; i++) {
		if(notas[i-1] != notas[i]  && i > 0) {
			possuiTom(toms, notas[i], possui);
			if(count==0) {
				printf("desafinado\n");
				return 0;
			}
		}
		else if(i == 0) {
			possuiTom(toms, notas[i], possui);
			if(count==0) {
				printf("desafinado\n");
				return 0;
			}
		}
	}
	
	for(i=0; i < qntNotas; i++) {
		if(possui[i] == 1) {
			switch(i+1) {
				case 1:
					printf("do\n");
					break;
				case 2:
					printf("do#\n");
					break;
				case 3:
					printf("re\n");
					break;
				case 4:
					printf("re#\n");
					break;
				case 5:
					printf("mi\n");
					break;
				case 6:
					printf("fa\n");
					break;
				case 7:
					printf("fa#\n");
					break;
				case 8:
					printf("sol\n");
					break;
				case 9:
					printf("sol#\n");
					break;
				case 10:
					printf("la\n");
					break;
				case 11:
					printf("la#\n");
					break;
				case 12:
					printf("si\n");
					break;
			}
			return 0;	
		}
	}
	
	return 0;
}
