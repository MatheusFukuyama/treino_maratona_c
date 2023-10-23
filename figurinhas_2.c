#include<stdio.h>
#include<stdio.h>

int main() {
	char valor[8];
	float preco, possui;
	int qntMoeda25, qntMoeda10, qntMoeda5, qntMoeda1;
	
	scanf("%s", valor);
	scanf("%d%d%d%d", &qntMoeda25, &qntMoeda10, &qntMoeda5, &qntMoeda1);
	
	
	preco = (valor[2] - '0') + (valor[4] - '0')*0.1 + (valor[5] - '0')*0.01;
	
	possui = qntMoeda25 * 0.25 + qntMoeda10 * 0.1 + qntMoeda5 * 0.05 + qntMoeda1 * 0.01;
	
	
	int qntPacotes = possui/preco;
	
	float sobra = possui - (preco * qntPacotes);
	
	int qntMoedasSobra = 0;
	float acumulador = 0;
	
	while(qntMoeda1 > 0 && acumulador < sobra) {
		acumulador += 0.01;
		qntMoeda1--;
		qntMoedasSobra++;
	}
	
	while(qntMoeda5 > 0 && acumulador < sobra) {
		acumulador += 0.05;
		qntMoeda5--;
		qntMoedasSobra++;
	}
	
	while(qntMoeda10 > 0 && acumulador < sobra) {
		acumulador += 0.1;
		qntMoeda10--;
		qntMoedasSobra++;
	}
	
	while(qntMoeda25 > 0 && acumulador < sobra) {
		acumulador += 0.25;
		qntMoeda25--;
		qntMoedasSobra++;
	}
	
	if(acumulador > sobra && qntPacotes > 0) {
		qntMoedasSobra--;
	}
	printf("%d\n", qntPacotes);
	printf("%d\n", qntMoedasSobra);
	
	return 0;
}
