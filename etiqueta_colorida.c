#include<stdio.h>
#include<string.h>
#include<math.h>

int converteParaDecimal(char etiqueta[]) {
	int i, posicao = 1, dec = 0;
	
	for(i=strlen(etiqueta)-1; i >=0 ; i--) {
		if(etiqueta[i] == 'a')
			dec += posicao * 10;		
		else if(etiqueta[i] == 'b')
			dec += posicao * 11;
		else if(etiqueta[i] == 'c')
			dec += posicao * 12;
		else if(etiqueta[i] == 'd')
			dec += posicao * 13;
		else if(etiqueta[i] == 'e')
			dec += posicao * 14;
		else if(etiqueta[i] == 'f')
			dec += posicao * 15;
		else	
			dec += (posicao * (etiqueta[i] - '0'));
		posicao *= 16;
	}
	
	return dec;
}


void converteParaHexa(unsigned long long total) {
	int i;
	
	char hexaTotal[14];

	i = 0;
	while(total >= 16) {
		
		if(total % 16 == 10)
			hexaTotal[i] = 'a';		
		else if(total % 16 == 11)
			hexaTotal[i] = 'b';
		else if(total % 16 == 12)
			hexaTotal[i] = 'c';
		else if(total % 16 == 13)
			hexaTotal[i] = 'd';
		else if(total % 16 == 14)
			hexaTotal[i] = 'e';
		else if(total % 16 == 15)
			hexaTotal[i] = 'f';
		else	
			hexaTotal[i] = (total % 16) + '0';
		total /= 16;
		i++;
	}
	hexaTotal[i] = total + '0';
	i++;
	hexaTotal[i] = '\0';
	
	for(i= strlen(hexaTotal)-1; i>=0; i--)
		printf("%c", hexaTotal[i]);
	
	printf("\n");
}


int main() {
	char red[7], green[7], blue[7];
	int decR, decG, decB;
	
	scanf("%s%s%s", red, green, blue);
	
	decR = converteParaDecimal(red);
	decG = converteParaDecimal(green);
	decB = converteParaDecimal(blue);
	
	if(decG > decR){
		printf("1\n");
		return 0;
	}
	
	unsigned long long quantidadeLadoG = decR / decG;
	unsigned long long quantidadeG = quantidadeLadoG * quantidadeLadoG;
	
	unsigned long long quantidadeB = (quantidadeLadoG * decG) / decB;
	quantidadeB *= quantidadeB; 
	
	unsigned long long total = quantidadeB + quantidadeG + 1;
	
	converteParaHexa(total);
	
	return 0;
}
