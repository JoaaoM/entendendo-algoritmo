#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	int valor;
	struct Lista *prox;
} Lista;

void novoNo (Lista **primeiroNo, int valor){
	Lista *aux = *primeiroNo;
	Lista *novoNo = malloc(sizeof(Lista));
	novoNo->valor = valor;
	novoNo->prox = NULL;
	
	if(aux == NULL){
		*primeiroNo = novoNo;
	} else {
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novoNo;
	}
}
void imprimirLista(Lista *primeiroNo) {
    printf("+------------------------+\n");
    printf("| Lista	|\n");
    printf("+------------------------+");
    
    while (primeiroNo != NULL) {
        printf("\n| (%p) | %6d | -->", (void*)primeiroNo, primeiroNo->valor);
        primeiroNo = primeiroNo->prox;
    }
    
    printf(" NULL \n");
    printf("+------------------------+\n");
}

void liberarMemoria(Lista *lista){
	while(lista != NULL){
		Lista *temp = lista;
		lista = lista->prox;
		free(temp);
	}
}

int main (){
	Lista *compras_inicio = NULL;

	novoNo(&compras_inicio, 100);
	novoNo(&compras_inicio, 200);
	novoNo(&compras_inicio, 300);
	novoNo(&compras_inicio, 400);
	novoNo(&compras_inicio, 500);
	novoNo(&compras_inicio, 600);
	novoNo(&compras_inicio, 700);
	novoNo(&compras_inicio, 1700);
	novoNo(&compras_inicio, 2700);

	imprimirLista(compras_inicio);
	liberarMemoria(compras_inicio);
	
	system("pause");
	return 0;
}