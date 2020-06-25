/* Versão recursiva do método de ordenação por
trocas sucessivas*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void preenche (int k, int v[]){
	for (int i=0; i<k; i++){
		v[i]= rand()%1000;
	}
}

void troca (int *a, int *b){
	int aux;

	aux= *a;
	*a= *b;
	*b= aux;
}

void trocaSuc( int n, int V[]){
	if (n==1)
		return;

	for (int i=0; i<n-1; i++){
		if (V[i]> V[i+1]){
			troca(&V[i], &V[i+1]);
		}
	}
	trocaSuc(n-1, V);
}

int main (){
	int n, V[MAX];

	printf("Digite o tamanho do vetor(Max: %d): \n",MAX );
	scanf ("%d", &n);

	preenche(n, V);
	for(int i=0; i<n; i++){
		printf("%d ", V[i]);
	}
	printf("\n");

	trocaSuc(n, V);

	for (int i=0; i<n; i++){
		printf("%d ", V[i] );
	}
	printf("\n");

	return 0;
}