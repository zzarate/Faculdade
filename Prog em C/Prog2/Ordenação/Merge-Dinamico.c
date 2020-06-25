#include <stdlib.h>
#include <stdio.h>

void intercala (int p, int q, int r, int V[MAXVET]){
	int i, j, k;
	int W[MAXVET]; // Vetor aux;

	i=p; // Comeco
	j=q; // Meio
	k=0; // Final

	while (i<q && j<r){
		if (V[i]<= V[j]){
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

int main (){
	int *V;
	int n, i;

	printf("Digite o tamanho do vetor:\n");
	scanf ("%d", &n);

	V= (int *) malloc (n * sizeof (int));

	printf("Digte os elementos do vetor: \n");
	for (i=; i<n; i++){
		scanf ("%d", &V[i]);
	}

	merge (0, n, V);

	for (i=0; i<n; i++){		// Imprime o vetor ordenado
		printf("%d ", V[i] );
	}

	return 0;
}