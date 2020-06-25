/* Receba um conjunto S de n
números reais e um número real x e determine se existe um par
de elementos em S cuja soma é exatamente X*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int procura (float V[MAX], float x, int n){
	for (int i=0; i<n-1; i++){
		for (int j=i+1 ; j<n; j++){
			if (V[i]+V[j]== x)
				return 1;
		}
	}
	return 0;
}

int main (){
	int n;
	float x, V[MAX];

	printf("Digite o tamanho do vetor(Max: %d) \n",MAX );
	scanf ("%d", &n);
	printf("Digite o numero que dseja verificar: \n");
	scanf ("%f", &x);
	printf("Preencha o vetor:\n");
	for (int i=0; i<n; i++){
		scanf ("%f", &V[i]);
	}

	if (procura (V,x, n ) ==1)
		printf("Existe\n");
	else
		printf("Não existe\n");

	return 0;
}