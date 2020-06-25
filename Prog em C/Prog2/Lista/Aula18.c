#include <stdlib.h>
#include <stdio.h>

struct cel {
	int chave;
	struct cel *prox;
}

typedef struct cel celula;

void imprine_lista (celula *lst){
	celula *p;

	for (p= lst; p != NULL; p=p->prox)
		printf("%d\n", p->chave);
}

celula *busca_C (int x, celula *lst){
	celula *p;

	p= lst->prox;

	while (p!= NULL && p-> chave !=x)
		p= p->prox;
	return p;
}



int main (){


	imprine_lista (lista->porx); // com cabeça
	imprine_lista (lista); // sem cabeça
}