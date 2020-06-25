/* quicksort em ordem decrescente*/

#include <stdlib.h>
#include <stdio.h>
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

int separa(int p, int r, int V[]){
	int i, j, x;

	x= V[p]; 
	i=p-1; 
	j= r+1;

	while (1){
		do{
			j--;
		}
		while (V[j]< x);
		do{
			i++;
		}
		while (V[i]> x);
		if (i< j){
			troca (&V[i], &V[j]);
		}
		else
			return j;
	}
}

void quicksort (int p, int r, int V[]){
	int q;

	if (p<r){
		q= separa (p, r, V);
		quicksort(p, q, V);
		quicksort(q+1, r, V);
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

	quicksort (0, k-1, V);

	for (int i=0; i<k; i++){
		printf("%d ", V[i]);
	}
	printf("\n");

	return 0;
}