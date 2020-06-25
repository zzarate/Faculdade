/* Versão recursiva do método de ordenação por
inserção*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void preenche (int k, int v[]){
	for (int i=0; i<k; i++){
		v[i]= rand()%1000;
	}
}

void insertion (int k, int V[], int i){
	int j, x;

	if (i>= k){
		return;
	}

	else {
		x=V[i];
		for (j= i-1; j>=0 && V[j]> x; j--){
			V[j+1]= V[j];
		}
		V[j+1]= x;

		insertion(k, V, i+1);
	}
}

int main (){
	int k, V[MAX];

	printf("Digite o tamanho do vetor(Max: %d): \n",MAX );
	scanf ("%d", &k);

	preenche(k, V);
	for(int i=0; i<k; i++){
		printf("%d ", V[i]);
	}
	printf("\n");

	insertion (k, V, 0);

	for (int i=0; i<k; i++){
		printf("%d ", V[i]);
	}
	printf("\n");

	return 0;
}