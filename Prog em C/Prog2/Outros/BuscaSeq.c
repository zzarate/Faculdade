/* Busca sequencial 
Procura um elemento dado pelo usuario, no vetor */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 20000

void gera(int n, int v[]){
	int i;
	for(i=0; i<n; i++)
		v[i]= rand()%20000;
}
void buscaseq(int num, int n, int v[]){
	int i;
	int aux=0;
	for(i=0; i<n; i++){
		if(num == v[i])
			aux++;
	}
	if(aux>0)
		printf("Achou\n");
	else
		printf("Nao achou\n");

}

int main(void){
	int v[max]; // Vetor com elementos aleatorios
	int n;		// Tamanho do Vetor
	int num;	// Numero a ser procurado
	float t1, t2;

	scanf("%d", &n);
	gera(n, v);
	scanf("%d", &num);
	double t;
	t1= clock();
	t1=time(NULL);
	buscaseq(num, n, v);
	t2= clock();
	t2=time(NULL);
	t= (t2-t1)*10000.0/CLOCKS_PER_SEC;
	printf("%f", t);
	return 0;
}