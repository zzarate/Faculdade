/*Verificacao da estabilidade do algoritmo mergesort*/

/*Um algoritmo de intercalação é estável se não altera a posição
relativa dos elementos que têm um mesmo valor. Por exemplo, se
o vetor tiver dois elementos de valor 222, um algoritmo de
intercalação estável manterá o primeiro 222 antes do segundo. A
função intercala é estável? Se a comparação v[i] <= v[j]
for trocada por v[i] < v[j] a função fica estável?*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//Algotimo sem alteracao
void intercala1 (int p, int q, int r, int V[], int F[]){
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

//Algoritmo com a alteracao "V[i]<= V[j]"
void intercala2 (int p, int q, int r, int V[], int F[]){
	int i, j, k; //Variaveis aux. cont;
	int W[MAX];  //Vet. aux. V;
	float X[MAX]; //Vet. aux. F;

	i=p; //Primeira posicao- Comeco;
	j=q; //Meio do vet. [(p+k)/2];
	k=0; 

	while (i<q && j<r){
		if (V[i]<= V[j]){
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


void merge1 (int p, int k, int V[], int F[]){

	int q; //Meio do vetor

	if (p<k-1){
		q= (p+k)/2;
		merge1 (p, q, V, F);
		merge1 (q, k, V, F);
		intercala1 (p, q, k, V, F);
	}

}

void merge2 (int p, int k, int V[], int F[]){

	int q; //Meio do vetor

	if (p<k-1){
		q= (p+k)/2;
		merge2 (p, q, V, F);
		merge2 (q, k, V, F);
		intercala2 (p, q, k, V, F);
	}

}

int main(){
	int V[MAX]= {8008, 1701, 578, 222, 613, 430, 7, 429, 222, 188};		//Vetor dos elementos a serem ordenados
	int F[MAX]= {0, 0, 0, 1, 0, 0, 0, 0, 2, 0};// Vetor da permutacao de posicao correspondente ao elementos do vetor V.

	printf("Sequencia com elementos de valor aleatorio, execeto o numero 222:\n");

	for (int i=0; i<MAX; i++){
		printf("%d ", V[i]);
	}
	printf("\n");
	printf("\n");
	printf("Sequencia com flag nos elementos que desejo verificar se houve alteracao de posicao: \n");

	for (int i=0; i<MAX; i++){
		printf("%d ", F[i] );
	}
	printf("\n");
	printf("\n");

	merge1 (0, MAX, V, F);

	printf("Sequencia dos elementos ordenados: \n");

	for (int i=0; i<MAX; i++){
		printf("%d ", V[i]);
	}
	printf("\n");
	printf("\n");

	printf("Sequencia da permuta de posicao dos elementos correspondente: \n");

	for (int i=0; i<MAX ; ++i){
		printf("%d ", F[i]);
	}
	printf("\n");
	printf("\n");

	printf("Na ultima linha do vetor de permuta, podemos ver que houve a troca de posicao dos\n");
	printf("elementos, portanto o algoritmo não é estavel.\n");

	printf("---------------------------------------------------------------------------------------\n");

	int S[MAX]= {8008, 1701, 578, 222, 613, 430, 7, 429, 222, 188};
	int T[MAX]= {0, 0, 0, 1, 0, 0, 0, 0, 2, 0};

	printf("Sequencia com elementos de valor aleatorio, execeto o numero 222:\n");

	for (int i=0; i<MAX; i++){
		printf("%d ", S[i]);
	}
	printf("\n");
	printf("\n");
	printf("Sequencia com flag nos elementos que desejo verificar se houve alteracao de posicao: \n");

	for (int i=0; i<MAX; i++){
		printf("%d ", T[i] );
	}
	printf("\n");
	printf("\n");

	merge2 (0, MAX, S, T);

	printf("Sequencia dos elementos ordenados: \n");

	for (int i=0; i<MAX; i++){
		printf("%d ", S[i]);
	}
	printf("\n");
	printf("\n");

	printf("Sequencia da permuta de posicao dos elementos correspondente: \n");

	for (int i=0; i<MAX ; ++i){
		printf("%d ", T[i]);
	}
	printf("\n");

	printf("\n");

	printf("Neste caso, a ultima linha permace a ordem dos elementos, o que mostra que com a troca\n");
	printf("do sinal da comparacao, torna ao algoritmo estavel.\n");
	printf("Portanto, o algoritmo 'intercala' nao e estavel, mas com a troca do sinal, se torna estavel.\n");

	return 0;
}
