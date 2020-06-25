#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 100
#define MAXVET 100

void preenche (int V[],int k){
	int i;
	for (i=0; i<k; i++){
		V[i]=rand()%MAX;
	}
}

void troca(int *a, int *b){
	int aux;

	aux=*a;
	*a=*b;
	*b=aux;
}

int separa (int p, int r, int V[MAXVET]){
	int i, j, x;

	x=V[p]; i=p-1; j=r+1;

	while (1){
		do{
			j--;
		} while(V[j]>x);
		do {
			i++;
		} while (V[i]<x);
		if (i<j){
			troca (&V[i], &V[j]);
		}
		else
			return j;
	}
}

void quick (int p, int r, int V[MAXVET]){
	int q;

	if (p<r){
		q= separa (p, r, V);
		quick (p, q, V);
		quick (q+1, r, V);
	}
}

int main(){

	int n, V[MAXVET];


	printf("Digite o tamanho do vetor (%d): \n", MAXVET);
	scanf ("%d", &n);

	preenche (V, n);

	for (int i=0; i<n; i++){   //Imprime a sequencia preenchida
		printf("%d ", V[i] );
	}

	printf("\n");

	double t, t1, t2;
	t1=clock();

	quick (0, n-1, V);

	t2=clock();
	t= (t2-t1)/CLOCKS_PER_SEC;

	for (int i=0; i<n; i++){		// Imprime o vetor ordenado
		printf("%d ", V[i] );
	}

	printf("\n");

	printf("%f\n", t);

	return 0;
}