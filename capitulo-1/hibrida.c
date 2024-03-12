#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Lista {
	char nome[50];
	struct Lista *prox;
} Lista;

typedef struct Hibrida {
	char letra;
	struct Lista *lista;
} Hibrida;

void adicionarNome (Lista **primeiroNo, char *nome){
	Lista *aux = *primeiroNo;
	Lista *novoNo = malloc(sizeof(Lista));
	strcpy(novoNo->nome, nome);
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

void inicializandoLista(Hibrida *arrayHibrido) {
    for (int i = 0; i < 26; i++) {
        arrayHibrido[i].letra = 'a' + i;
        arrayHibrido[i].lista = NULL;
    }
}

void liberarMemoriaHibrida(Hibrida *arrayHibrido) {
    for (int i = 0; i < 26; i++) {
        Lista *listaAtual = arrayHibrido[i].lista;
        while (listaAtual != NULL) {
            Lista *temp = listaAtual;
            listaAtual = listaAtual->prox;
            free(temp);
        }
        arrayHibrido[i].lista = NULL; 
    }
}

void imprimirNomes(Hibrida *arrayHibrida, char primeiraLetra){
	printf("Todos os nomes cadastrado com a letra: %c\n", primeiraLetra);
	int indice = primeiraLetra - 'a';
	Lista *ptr = arrayHibrida[indice].lista;
    while (ptr != NULL) {
        printf("%s\n", ptr->nome);
        ptr = ptr->prox;
    }
}


int main () {
	Hibrida arrayHibrida[26];
	inicializandoLista(arrayHibrida);
	adicionarNome(&arrayHibrida[0].lista, "Ana");
	imprimirNomes(arrayHibrida, 'a');
	liberarMemoriaHibrida(arrayHibrida);
	system("pause");
	
	return 0;
}
