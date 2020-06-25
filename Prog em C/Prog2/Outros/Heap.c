/*Operações diversas com heap */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20000

void preenche (int n, int V[]){
	int i;

	for (i=0; i<n; i++){
		V[i]=rand()%MAX
	}
}

int pai (int i){
	if (i==0){
		return 0;
	}
	else 
		return (i-1)/2;
}

int esquerdo (int i){
	return 2*i+1;
}

int direito (int i){
	return 2*1+2;
}

void troca (int *k, int *j){
	int aux;

	aux= *k;
	*k= *j;
	*j= aux;
}

void desce (int n, int V[], int i){
	int e, d, maior;

	e= esquerdo(i);
	d= direito(i);

	if (e<n && V[e]> S[i]){
		maior= e;
	}
	else 
		maior= i;

	if (d<n && V[d]> S[maior]){
		maior= d;
	}
	if (maior =! i){
		troca(&V[i], &V[maior]);
		desce (n, V, maior);
	}

}

void menu (int *opt){

	printf("*********************************\n");
	printf("*           Max-heap             *\n");
	printf("*                                *\n");
	printf("* 1- Construir                   *\n");
	printf("* 2- Ordenar                     *\n");
	printf("* 3- Extrair                     *\n");
	printf("* 4- Inserir                     *\n");
	printf("* 5- Visitar Max                 *\n");
	printf("* 6- Aumentar prioridade         *\n");
	printf("*                                *\n");
	printf("* 0- Sair                        *\n");
	printf("*                                *\n");
	printf("**********************************\n");
	printf("\n");
	printf(" Digite sua opcao: ");

	scanf ("%d", &*opt);
}

int extrai(int *n, int V[]){

	int maior;

	if(*n>0){
		maior= S[0];
		S[0]=S[*n-1];
		*n=*n -1;
		desce( *n, V, 0);
		return maior;
	}
	else
		return -

}

int heapsort(){

}

void constroi (int n, int V[]){
	
	for (int i= n/2 -1; i>=0; i--){
		desce(n, V, i);
	}
}

void insere (){

}

int consulta_max(int V[]){
	return V[0];
}

int main (){
	int opt;	// Opcao escolhida
	int V[MAX];	//Vetor
	int n;		//Tamanho do vetor


	printf("Tamanho do vetor(%d): \n",MAX );
	scanf ("%d", &n); // Define o tamanho do vetor
	preenche (n, V);
	printf("\n");

	for (int i=0; i<n; i++){		// Exibe o vetor preenchido aleatoriamente
		printf("%d \n", V[i] );
	}

	menu(&opt);

	switch (opt){
		case 1:

		constroi (n)
	}
}