#include<stdio.h>

int naoDerrubou = 0;

void NavioDerrubado(int n, int m, char campo[][m], int passou[][m], int i, int j) {
	passou[i][j] = 1;
		
	if((campo[i][j+1] == '#' && j < m-1) || (campo[i][j-1] == '#'  && j > 0) || (campo[i+1][j] == '#' && i < n-1) || (campo[i-1][j] == '#' && i > 0 )){
		naoDerrubou = 1;
	} 
		if(campo[i][j+1] == '0'  && j < m-1 && passou[i][j+1] == 0 )
				NavioDerrubado(n, m, campo, passou, i, j+1);
		if(campo[i][j-1] == '0'  && j > 0 && passou[i][j-1] == 0 )
				NavioDerrubado(n, m, campo, passou, i, j-1);
		if(campo[i+1][j] == '0'  && i < n-1 && passou[i+1][j] == 0 )
				NavioDerrubado(n, m, campo, passou, i+1, j);
		if(campo[i-1][j] == '0'  && i > 0 && passou[i-1][j] == 0 )
				NavioDerrubado(n, m, campo, passou, i-1, j);
	
	
}


int main() {
	int m, n;
	
	scanf("%d%d", &n, &m);
	
	if((m < 1 || m > 100) || (n < 1 || n > 100))
	return 0;
	
	char campo[n][m];
	int passou[n][m];
	
	int i, j;
	for(i=0; i<n; i++)
		for(j=0; j<m; j++){
			scanf(" %c", &campo[i][j]);
			passou[i][j] = 0;
		}
	
	
	int k, l, c;
	
	scanf("%d", &k);
	
	if(k < 1 || k > m*n)
		return 0;

	for(i=0; i<k; i++){
		scanf("%d%d", &l,&c);
		if(campo[l-1][c-1] != '.')
			campo[l-1][c-1] = '0';
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%c", campo[i][j]);
		}
		printf("\n");
	}
	
	
	int ponto = 0;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(campo[i][j] == '0' && passou[i][j] == 0) {
				
				NavioDerrubado(n, m, campo, passou, i, j);
				if(!naoDerrubou)
					ponto++;
				else
					naoDerrubou = 0;	
			}
		}
	}
	
	
	printf("%d\n", ponto);
	return 0;
}
