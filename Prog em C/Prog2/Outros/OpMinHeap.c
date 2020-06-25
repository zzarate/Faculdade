/*Operações diversas com Min-heap */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

void preenche (int n, int V[]){
	int i;

	for (i=0; i<n; i++){
		V[i]=rand()%1000;
	}
}

int pai(int i){
	if (i==0){
		return 0;
	}
	else
		return (i-1)/2;
}

int esquerdo(int i){
	return (i*2)+1;
}

int direito(int i){
	return i*2+2;
}

void troca(int *a, int *b){
	int aux;

	aux=*a;
	*a=*b;
	*b=aux;
}

void sobe(int i, int V[]){
	while (V[pai(i)]> V[i]){
		troca(&V[i], &V[pai(i)]);
		i=pai(i);
	}
}

void desce(int k, int V[], int i){
	int e, d, min;

	e= esquerdo(i);
	d= direito(i);

	if(e<k && V[e]<V[i]){
		min= e;
	}
	else
		min= i;

	if (d<k && V[d]< V[min]){
		min=d;
	}
	if (min!= i){
		troca (&V[i], &V[min]);
		desce(k, V, min);
	}

}

void constroi(int k, int V[]){
	for (int i= k/2-1; i>=0; i--){
		desce (k, V, i);
	}
}

int consulta(int V[]){
	return V[0];
}

int extrai(int V[], int *k){
	int min;

	if (*k> 0){
		min = V[0];
		V[0]= V[*k-1];
		*k= *k-1;
		desce (*k, V, 0);
		return min;
	}
	else
		return INT_MIN;
}

void prioridade (int k, int V[], int i, int p){
	if (p>V[i]){
		printf("Erro: nova prioridade e maior que a da celula\n");
	}
	else{
		V[i]= p;
		sobe (i, V);
	}
}

void insere(int *k, int V[], int p){
	V[*k]= p;
	*k=*k+1;
	sobe(*k-1, V);
}

int main(){
	int k, p;
	int V[MAX];

	printf("Digite o tamanho (Max: %d):\n",MAX );
	scanf ("%d", &k);

	preenche(k, V);
	printf("Elementos do vetor: \n");
	for (int i=0; i<k; i++){
		printf("%d ", V[i]);
	}
	printf("\n");
	printf("\n");

	constroi (k, V);
	printf("Min-heap: \n");
	for (int i=0 ; i<k; i++){
		printf("%d ", V[i]);
	}
	printf("\n");
	printf("\n");

	printf("Menor prioridade: \n");
	printf("%d \n", consulta(V));
	printf("\n");

	printf("Extracao do menor numero:\n");
	printf("%d \n",extrai(V, &k) );
	for (int i=0; i<k; i++){
		printf("%d ", V[i]);
	}
	printf("\n");
	printf("\n");

	printf("Digite um numero a ser a menor prioridade: \n");
	scanf ("%d", &p);
	prioridade(k, V, k-1, p);
	for (int i=0; i<k; i++){
		printf("%d ", V[i]);
	}
	printf("\n");
	printf("\n");

	printf("Digite um numero a ser inserido no heap: \n");
	scanf ("%d", &p);
	insere(&k, V, p);
	for (int i=0; i<k; i++){
		printf("%d ",V[i] );
	}
	printf("\n");

	return 0;
}