/* Problema de Josephus */
/*Lista circular*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	int chave;
	struct cel *prox;
} celula;

void insere (int y, celula *c){
	celula *nova;

	nova= (celula *) malloc (sizeof (celula));
	nova->chave= y;
	nova->prox= c->prox;
	c->prox= nova;
}

void remove_p (int x, celula *c){
	celula *p, *q;

	p= c;
	p->chave= x;
	q= p->prox;

	while (q->chave != x){
		p= q;
		q= q->prox;
	}
	if (q != c){
		p->prox= q->prox;
		free (q);
	}
}

celula *seleciona (int n, int m, celula *c){
	celula *p;
	
	p=c->prox;
	if (n>1){
		for (int i=0; i<=m; i++){
			p= p->prox;
		}
		remove_p (p->chave, c);
		return (c);
	}

	else
		return p;

}

int main (){
	int n, m;
	celula *lista, *J;

	lista= (celula *) malloc (sizeof (celula));
	lista->prox= lista;

	printf("Digite o valor de n: \n");
	scanf ("%d", &n);
	printf("Digite o valor de m: \n");
	scanf ("%d", &m);

	for (int i=n; i > 0; i--){
		insere (i, lista);
	}

	J=seleciona (n, m, lista);

	printf("%d é o sobrevivente \n", J->chave );

	return 0;
}