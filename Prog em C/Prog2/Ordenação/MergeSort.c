/*Merge Sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20000
#define MAXVET 20000

void preenche (int V[],int k){
	int i;
	for (i=0; i<k; i++){
		V[i]=rand()%MAX;
	}
}

void intercala (int p, int q, int r, int V[MAXVET]){
	int i, j, k;
	int W[MAXVET]; // Vetor aux;

	i=p; // Comeco
	j=q; // Meio
	k=0; // Final

	while (i<q && j<r){
		if (V[i]< V[j]){
			W[k]= V[i];
			i++;
		}
		else {
			W[k]= V[j];
				j++;
		}
		k++;
	}
	while (i < q){
		W[k]= V[i];
		i++;
		k++;
	}
	while (j < r){
		W[k]= V[j];
		j++;
		k++;
	}
	for (i= p; i<r; i++){
		V[i]= W[i-p];
	}
}

void merge (int p,int k,int V[]){
	int q; //meio

	if (p < k-1){
		q= (p+k)/2;
		merge (p, q, V);
		merge (q, k, V);
		intercala (p, q, k, V);
	}
}

int main(){

	int k; //Tam vet - final
	int V[MAXVET]; //Vetor


	printf("Digite o tamanho do vetor (%d): \n", MAXVET);
	scanf ("%d", &k);

	preenche (V, k);

	for (int i=0; i<k; i++){   //Imprime a sequencia preenchida
		printf("%d ", V[i] );
	}

	printf("\n");

	double t, t1, t2;
	t1=clock();

	merge (0, k, V);

	t2=clock();
	t= (t2-t1)/CLOCKS_PER_SEC;

	for (int i=0; i<k; i++){		// Imprime o vetor ordenado
		printf("%d ", V[i] );
	}

	printf("\n");

	printf("%f\n", t);

	return 0;
}