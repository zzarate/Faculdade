/*****************************************************/
/*Verificacao da estabilidade do algoritmo mergesort*/
/*Nesse caso ele não é estavel                      */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

static void intercala (int p, int q, int r, int V[], float F[]){
	int i, j, k; //Variaveis aux. cont;
	int W[MAX];  //Vet. aux. V;
	float X[MAX]; //Vet. aux. F;

	i=p; //Primeira posicao- Comeco;
	j=q; //Meio do vet. [(p+k)/2];
	k=0; 

	while (i<q && j<r){
		if (V[i]< V[j]){
			W[k]= V[i];
			X[k]= F[i]; //Troca elementos de F;

			i++; 
		}
		else {
			W[k]= V[j];
			X[k]= F[j];

			j++;
		}

		k++;
	}

	while (i< q){
		W[k]= V[i];
		X[k]= F[i];

		i++;
		k++;
	}

	while (j<r){
		W[k]= V[j];
		X[k]= F[j];

		j++;
		k++;
	}

	for (i=p; i<r; i++){
		V[i]= W[i-p];
		F[i]= X[i-p];
	}

}

void merge (int p, int k, int V[], float F[]){

	int q; //Meio do vetor

	if (p<k-1){
		q= (p+k)/2;
		merge (p, q, V, F);
		merge (q, k, V, F);
		intercala (p, q, k, V, F);
	}

}

int main(){
	int V[MAX]= {8008, 1701, 578, 222, 613, 430, 7, 429, 222, 188};		//Vetor dos elementos a serem ordenados
	float F[MAX]= {8008, 1701, 578, 222.1, 613, 430, 7, 429, 222.2, 188};// Vetor da permutacao de posicao correspondente ao elementos do vetor V.

	printf("Sequencia com elementos de valor aleatorio, execeto o numero 222:\n");

	for (int i=0; i<MAX; i++){
		printf("%d ", V[i]);
	}
	printf("\n");
	printf("\n");
	printf("Sequencia com flag nos elementos que desejo verificar se houve alteracao de posicao: \n");

	for (int i=0; i<MAX; i++){
		printf("%.1f ", F[i] );
	}
	printf("\n");
	printf("\n");

	merge (0, MAX, V, F);

	printf("Sequencia dos elementos ordenados: \n");

	for (int i=0; i<MAX; i++){
		printf("%d ", V[i]);
	}
	printf("\n");
	printf("\n");

	printf("Sequencia da permuta de posicao dos elementos correspondente: \n");

	for (int i=0; i<MAX ; ++i){
		printf("%.1f ", F[i]);
	}
	printf("\n");

	printf("\n");

	return 0;
}