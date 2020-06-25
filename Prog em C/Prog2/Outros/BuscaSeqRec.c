#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20000
#define MAXVET 10000

void preenche (int k, int v[]){
	for (int i=0; i<k; i++){
		v[i]= rand()%MAX;
	}
}

int buscaSeqRec (int k, int n, int v[]){
	if (v[k-1] == n)
		return 1;
	else
		if (k>0)
			return buscaSeqRec (k-1, n, v);
		else
			return 0;

};

int main (){
	int k, n, result; //K- Tam Vet, N- Num 
	int v[MAXVET];

	printf("Digite o tamanho do vetor(Max %d): \n", MAXVET);
	scanf ("%d", &k);
	printf("Digite o numero a ser procurado(Max %d): \n", MAX);
	scanf ("%d", &n);

	preenche(k, v);

	result=buscaSeqRec (k, n, v);
	if (result)
		printf("Achou\n");
	else
		printf("Não achou\n");

	return 0;
}