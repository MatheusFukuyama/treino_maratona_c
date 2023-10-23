#include<stdio.h>

int main() {
	float qntCachorroQuente, qntParticipantes;
	
	scanf("%f%f", &qntCachorroQuente, &qntParticipantes);
	
	if((qntCachorroQuente < 1 || qntCachorroQuente > 1000) || (qntParticipantes < 1 || qntParticipantes > 1000))
		return 0;
	
	float media =  qntCachorroQuente / qntParticipantes;
	
	printf("%.2f\n", media);
	return 0;
}
