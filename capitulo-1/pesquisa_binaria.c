#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 10
#define RANGE_RANDOM 100

void bubbleSort(int vetor[]){
	bool trocou;
	do {
		trocou = false;
		for (int i = 0; i < MAX; i++){
			if(vetor[i] > vetor[i+1]){
				int aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				trocou = true;
			}
		}
	} while (trocou);
}

void imprimirVetor(int vetor[]){
	printf("[");
	for (int i = 0; i < MAX; i++){
		 if(i == MAX - 1){
			printf("%d", vetor[i]);
		 } else {
			printf("%d, ", vetor[i]);
		 }
	}
	printf("]\n");
}

void pesquisaBinaria(int vetor[], int busca){
	int indexInicio = 0;
	int indexUltimo = MAX;
	
	printf("\n\nO valor pesquisado: %d \n", busca);
	
	do {
		int indexMeio = (indexInicio + indexUltimo)/2;
		int pivo = vetor[indexMeio];
		
		if (pivo == busca){
			printf("o seu numero: %d\n", pivo);
			break;
		}
		
		if(pivo > busca){
			indexUltimo = indexMeio - 1;
		}
		
		if (pivo < busca){
			indexInicio = indexMeio + 1;
		}
		
		if (indexInicio > indexUltimo){
			printf("nenhum registro encontrado\n");
		}
		
	} while(indexInicio <= indexUltimo);
	
	printf("\n\n");
}

int gerarNumeroRandomico(){
	return rand() % RANGE_RANDOM;
}

void popularVetor(int vetor[]){
	for (int i = 0; i < MAX; i ++) {
		vetor[i] = gerarNumeroRandomico();
	}
}

int main () {
	srand(time(NULL));
	int vetor[MAX];
	popularVetor(vetor);
	printf("vetor original: ");
	imprimirVetor(vetor);
	printf("vetor ordenador: ");
	bubbleSort(vetor);
	imprimirVetor(vetor);
	pesquisaBinaria(vetor,gerarNumeroRandomico());
	pesquisaBinaria(vetor,gerarNumeroRandomico());
	pesquisaBinaria(vetor,gerarNumeroRandomico());
	pesquisaBinaria(vetor,gerarNumeroRandomico());
	pesquisaBinaria(vetor,gerarNumeroRandomico());
	pesquisaBinaria(vetor,gerarNumeroRandomico());
	
	system("pause");
}