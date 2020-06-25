#include <stdio.h>
#include <stdlib.h>

typedef struct cel
{
	int chave;
	struct cel *prox;
}celula;

void vet_listaC (int V, celula *lista){
	celula *nova;
	celula *q;

	nova= (celula *) malloc (sizeof (celula));
	nova->chave= V;
	q= lista;

	while (q->prox != NULL){
		q= q->prox;
	}

	nova->prox= q->prox;
	q->prox= nova;
}

void vet_listaS (int V, celula **lista){
	celula *nova;
	celula *q;

	nova= (celula *) malloc (sizeof (celula));
	nova->chave=V;
	q = *lista;

	while (q->prox != NULL){
		q= q->prox;
	}

	nova->prox= q->prox;
	q->prox = nova;
}

void imprimi_lista (celula *lista){
	celula *p;

	for (p= lista; p != NULL; p= p->prox){
		printf("%d ", p->chave);
	}
	printf("\n");
}

void imprimi_vet (int V[], int n){

	for (int i = 0; i < n; i++){
		printf("%d ", V[i]);
	}
	printf("\n");
}

void lista_vetC (int V[], celula *lista, int n){
	int i;
	celula *p;

	for (i = 0, p = lista->prox; i < n && p != NULL;i++, p = p->prox){
		V[i]=p->chave;
	}
}

void lista_vetS (int V[], celula **lista, int n){
	int i;
	celula *p;

	for (i = 0, p = *lista; i < n && p != NULL; i++, p = p->prox){
		V[i]=p->chave;
	}
}

int main (){
	int V[100], n;
	char s;
	celula *lista;
	
	lista= (celula *) malloc (sizeof (celula));

	printf("Tamanho do vetor:\n");
	
	scanf ("%d", &n);

	for (int i = 0; i < n; i++){
		scanf ("%d", &V[i]);
	}

	printf("Copiar de um vetor para uma lista\n");
	printf("\n");
	printf("(c)- Para lista com cabeça\n");
	printf("(s)- Para lista sem cabeça\n");
	scanf (" %c", &s);

	switch (s)
	{
		case 'c':
		lista->prox= NULL; 

		for (int i = 0; i < n; i++){
			vet_listaC (V[i], lista);
		}
		imprimi_lista (lista->prox);
		break;

		case 's':
		lista->chave= V[0];
		lista->prox= NULL;
		for (int i = 1; i < n; i++){
			vet_listaS (V[i], &lista);
		}
		imprimi_lista (lista);
		break;
	}

	switch (s)
	{
		case 'c':
		lista_vetC (V, lista, n);
		imprimi_vet (V, n);

		break;

		case 's':
		lista_vetS (V, &lista, n);
		imprimi_vet (V, n);

		break;
	}
	return 0;
}