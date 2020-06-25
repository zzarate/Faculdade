/* Ordenação por intercalação em ordem decrescente*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void preenche (int k, int v[]){
	for (int i=0; i<k; i++){
		v[i]= rand()%1000;
	}
}

void intercala (int p, int q, int r, int V[]){
	int i, j, k; //Variaveis aux. cont;
	int W[MAX];  //Vet. aux. V;

	i=p; //Primeira posicao- Comeco;
	j=q; //Meio do vet. [(p+k)/2];
	k=0; 

	while (i<q && j<r){
		if (V[i]> V[j]){
			W[k]= V[i];
			i++; 
		}
		else {
			W[k]= V[j];
			j++;
		}

		k++;
	}

	while (i< q){
		W[k]= V[i];
		i++;
		k++;
	}

	while (j<r){
		W[k]= V[j];
		j++;
		k++;
	}

	for (i=p; i<r; i++){
		V[i]= W[i-p];
	}

}

void merge (int p, int k, int V[]){

	int q; //Meio do vetor

	if (p<k-1){
		q= (p+k)/2;
		merge (p, q, V);
		merge (q, k, V);
		intercala (p, q, k, V);
	}

}

int main(){
	int k, V[MAX];

	printf("Digite o tamanho do vetor(Max: %d): \n",MAX );
	scanf ("%d", &k);
	preenche(k, V);

	for (int i=0; i<MAX; i++){
		printf("%d ", V[i]);
	}
	printf("\n");

	merge (0, MAX, V);

	for (int i=0; i<MAX; i++){
		printf("%d ", V[i]);
	}
	printf("\n");

	return 0;
} 