#include<stdio.h>
#include<math.h>

int main() {
	int n;
	
	scanf("%d", &n);
	
	float x[n], y[n], raio[n];
	
	int i = 0;
	for(i=0; i<n; i++) {
		scanf("%f%f%f", &x[i], &y[i], &raio[i]);
	}
	
	float distancia;
	float difx, dify;
	int inter = 0, indMaior, indMenor;
	float maiorRaio;
	int j;
	for(i=0; i<n; i++) {
		for(j=i+1; j < n; j++) {
			difx = x[i] - x[j];
			dify = y[i] - y[j];
			
			distancia = sqrt((difx)*(difx) + (dify)*(dify));
			
			if(raio[i] > raio[j]){
				maiorRaio = raio[i];
				indMaior = i;
				indMenor = j;
			} else{
				maiorRaio = raio[j];
				indMaior = j;
				indMenor = i;
			}
			
			if(distancia < maiorRaio) {
				if(raio[indMenor] + distancia == raio[indMaior])
					inter++;
				else if(raio[indMenor] + distancia > raio[indMaior])
					inter+=2;
			} else if(distancia > maiorRaio) {
				if(distancia - raio[indMenor]  == raio[indMaior])
					inter++;
				else if(distancia - raio[indMenor] < raio[indMaior])
					inter+=2;
			} else if(distancia == maiorRaio){
				inter+=2;
			}
		}
			
	}
	
	if(inter <= 2*n)
		printf("%d\n", inter);
	else
		printf("greater\n");
	
	return 0;
}
