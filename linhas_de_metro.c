#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct arestas{
	int tempo;
	struct arestas *arestasProx;
	int numAresta;
}arestas;

typedef struct vertices{
	int numVertice;
	arestas *primAresta;
	struct vertices *verticeProx;
	int passou;
}vertices;

typedef struct grafo{
	vertices *primVertice;
	int vertice, aresta;
}grafo;

typedef struct no{
	int numVertice;
	struct no *prox, *ant;
}no;

typedef struct lista{
	no *prim, *ult;
}lista;

void criarLista(lista *i){
	i->prim = NULL;
}

void criar(grafo *g){
	g->primVertice = NULL;
}

void inserirVertices(grafo *g, int numVertice2){
	vertices *novo;
	novo = malloc(sizeof(vertices));
	
	novo->verticeProx = NULL;
	novo->numVertice = numVertice2;
	novo->primAresta = NULL;
	novo->passou = 0;

	if(g->primVertice == NULL){
		g->primVertice = novo;
	}
	else{
		novo->verticeProx = g->primVertice;
		g->primVertice = novo;
	}

}

vertices *busca(grafo *g, int target){
	vertices *aux;
	
	aux = g->primVertice;
	while(aux != NULL){
		if(aux->numVertice == target)
			return aux;
		aux = aux->verticeProx;
	}
}

void inserirLista(lista *i, int numVertice1){
	no *novo;
	
	novo = malloc(sizeof(no));
	novo->numVertice = numVertice1;
	novo->prox = NULL;
	novo->ant = NULL;
	
	if(i->prim == NULL){
		i->prim = novo;
		i->ult = novo;
	}
	else{
		novo->prox = i->prim;
		i->prim->ant = novo;
		i->prim = novo;
	}
}

void removerLista(lista *i){
	no* aux;
	
	aux = i->prim;
	i->prim = i->prim->prox;
	free(aux);
}

void limparLista(lista *i) {
	no* aux;
	
	while(i->prim != i->ult){
		removerLista(i);
	}
	
	i->prim = NULL;

}

void inserirArestas(grafo *g, lista *i, int numVertice1, int numVertice2){
	arestas *novo, *novo2;
	vertices *ligacao;
	
	novo = malloc(sizeof(arestas));
	novo->arestasProx = NULL;
	novo->numAresta = numVertice2;
	
	novo2 = malloc(sizeof(arestas));
	novo2->arestasProx = NULL;
	novo2->numAresta = numVertice1;

	ligacao = busca(g, numVertice1);
	
	if(ligacao->primAresta == NULL)
		ligacao->primAresta = novo;
	else{
		novo->arestasProx = ligacao->primAresta;
		ligacao->primAresta = novo;
	}
	
	ligacao = busca(g, numVertice2);
	
	if(ligacao->primAresta == NULL)
		ligacao->primAresta = novo2;
	else{
		novo2->arestasProx = ligacao->primAresta;
		ligacao->primAresta = novo2;
	}
}


void imprimirCaminho(lista *i){
	no *aux;

	aux = i->ult;
	while(aux != NULL){
		printf("-> %s", aux->numVertice);
		aux = aux->ant;
	}
}

 
void copiarLista(lista *i, lista *l) {
	no *aux;

	aux = i->prim;
	while(aux != NULL) {
		inserirLista(l, aux->numVertice);
		aux = aux->prox;
	}
}

int iteracao = 1;

void mostrarCaminho(grafo *g, lista *i, int inicio, int fim, lista *l1, lista *l2){
	vertices *inicioVer,*fimVer, *comparaPassou;
	arestas *ligacoes;

	inicioVer = busca(g, inicio);
	ligacoes = inicioVer->primAresta;
	inserirLista(i, inicioVer->numVertice);
	
	inicioVer->passou = 1;
	while(ligacoes != NULL){
		if(ligacoes->numAresta == fim){
			inserirLista(i, ligacoes->numAresta);
			
			if(iteracao == 1)
				copiarLista(i, l1);
			else{
				printf("\n");
				copiarLista(i, l2);
			}
		}
		else{
			comparaPassou = busca(g, ligacoes->numAresta);
			if(comparaPassou->passou != 1){
				mostrarCaminho(g, i, ligacoes->numAresta, fim, l1, l2);
			}
		}
		ligacoes = ligacoes->arestasProx;
	}
	removerLista(i);
	inicioVer->passou = 0;
}


void zerarGrafo(grafo *g1) {
	vertices *v = g1->primVertice;
	
	while(v != NULL) {
		v->passou = 0;
		v = v->verticeProx;
	}
}


int count = 0;
int i, qntConsulta;
	
int main(){
	grafo g1;
	lista i1, l1, l2;
	no *aux, *aux2;

	
	criarLista(&i1);
	criarLista(&l1);
	criarLista(&l2);
	
	int n, ligacao1, ligacao2, inicio1, fim1, inicio2, fim2;
	
	scanf("%d%d", &n, &qntConsulta);
	
	for(i=0; i<n; i++)
		inserirVertices(&g1, i+1);
	
	for(i=0; i<n-1; i++){
		scanf("%d%d", &ligacao1, &ligacao2);
		inserirArestas(&g1, &i1, ligacao1, ligacao2);
	}

	for(i=0; i<qntConsulta; i++) {
		scanf("%d%d%d%d", &inicio1, &fim1, &inicio2, &fim2);
		mostrarCaminho(&g1, &i1, inicio1, fim1, &l1, &l2);
		iteracao++;
		zerarGrafo(&g1);
		mostrarCaminho(&g1, &i1, inicio2, fim2, &l1, &l2);
		iteracao=1;
		
		removerLista(&l2);
		
		aux = l1.prim;
		aux2 = l2.prim;
		
		while(aux != NULL) {
			while(aux2 != NULL) {
				if(aux->numVertice == aux2->numVertice)
					count++;
				aux2 = aux2->prox;
			}
			aux = aux->prox;
			aux2 = l2.prim;
		}
			
		printf("%d\n", count);
		count = 0;
		zerarGrafo(&g1);
		
		limparLista(&l1);
		limparLista(&l2);
	}
}
