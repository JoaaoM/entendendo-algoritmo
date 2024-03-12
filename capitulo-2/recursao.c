#include <stdlib.h>
#include <stdio.h>

// Quero encontrar o maior quadrado que eu possa dividir um terreno de 1680x640 (Largura * Altura)
// Utilizando da tecnica DC (dividir para conquistar)

int encontrarMenorQuadrado(int largura, int altura){
	if (largura % altura == 0 || altura % largura == 0) {
		if(largura > altura){
			return altura;
		} else {
			return largura;
		}
	}
	int resto;
	if (largura > altura){
		resto = largura % altura;
		encontrarMenorQuadrado(largura, resto);
	} else {
		resto = altura % largura;
		encontrarMenorQuadrado(resto, altura);
	}
}


int main (){
	int lado = encontrarMenorQuadrado(1700, 660);
	printf("maior quadrado %d x %d", lado, lado), 
	system("pause");
	return 0;
}