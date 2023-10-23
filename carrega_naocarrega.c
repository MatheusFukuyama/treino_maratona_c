#include<stdio.h>
#include<math.h>



void converterBinario(unsigned long valor, unsigned long bits[]) {
	int i = 0;
	
	while(valor >= 2) {
		bits[i] = valor % 2;
		i++;
		valor = valor / 2;
	}
	
	bits[i] = valor;
}


void somaBits(unsigned long bits1[], unsigned long bits2[], unsigned long result[]) {
	int i;
	
	for( i = 0; i < 32; i++ ) {
		if(( bits1[i] + bits2[i] ) == 2 ) {
			result[i] = 0;
		} else {
			result[i] = bits1[i] + bits2[i];
		}
	}
	
}

unsigned long converteDecimal(unsigned long bits[]) {
	int i;
	unsigned long decimal = 0;
	
	for(i = 0; i < 32; i++) {
		decimal += (bits[i])*pow(2, i);
	}
	
	return decimal;
	
}

int main() {
	unsigned long valor1, valor2, bits1[32], bits2[32], i, result[32], resDecimal;
	
	while(scanf("%lu%lu", &valor1, &valor2) != EOF) {
	
		for(i=0; i < 32; i++) {
			bits1[i] = 0;
			bits2[i] = 0;
			result[i] = 0;
		}
		
		converterBinario(valor1, bits1);
		converterBinario(valor2, bits2);
		
		
		somaBits(bits1, bits2, result);
		
		resDecimal = converteDecimal(result);
		
		printf("%lu\n", resDecimal);
		
	}
	
	return 0;
}



