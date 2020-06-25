/* Versão recursiva do método de ordenação por
seleção*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void preenche (int k, int v[]){
	for (int i=0; i<k; i++){
		v[i]= rand()%1000;
	}
}

void troca (int V[], int i, int j){
	int aux;

	aux= V[i];
	V[i]= V[j];
	V[j]= aux;
}

void selection (int k, int i, int V[]){
	int min= i;

	for (int j= i+1; j<k; j++){
		if(V[j]< V[min]){
			min= j;
		}
	}
	troca(V, min, i);
	if (i+1< k){
		selection(k, i+1, V);
	}
}

int main(){
	int k, V[MAX];

	printf("Digite o tamanho do vetor(Max: %d): \n",MAX );
	scanf ("%d", &k);

	preenche (k, V);

	for (int i=0; i<k; i++){
		printf("%d ", V[i]);
	}
	printf("\n");

	selection( k, 0, V);

	for (int i=0; i<k; i++){
		printf("%d ", V[i]);
	}
	printf("\n");

	return 0;
}