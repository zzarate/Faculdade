#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define MAXVET 100

void preenche (int V[],int k){
	int i;
	for (i=0; i<k; i++){
		V[i]=rand()%MAX;
	}
}

void insertion (int n, int V[]){
	int i,j,x;

	for (i=1; i<n; i++){
		x=V[i];
		for (j=i-1; j>=0 && V[j]< x; j--){
			V[j+1]=V[j];
		}
		V[j+1]=x;
	}
}

int main(){
	int n, V[MAXVET];

	printf("Digite o tamanho do vetor (%d): \n", MAXVET);
	scanf ("%d", &n);

	preenche(V, n);

	for (int i=0; i<n; i++){   //Imprime a sequencia preenchida
		printf("%d ", V[i] );
	}
	printf("\n");

	insertion(n, V);

	for (int i=0; i<n; i++){   //Imprime a sequencia preenchida
		printf("%d ", V[i] );
	}
	printf("\n");

	return 0;
}