#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
	char chave;
	struct cel *prox;
}celula;

char remover (celula *pilha){
	char x;
	celula *p;

	if (pilha->prox != NULL){
		p= pilha->prox;
		x= p->chave;
		pilha->prox= p->prox;
		free (p);
	}
	return x;
}

void insere (char c, celula *pilha){
	celula *nova;

	nova= (celula *) malloc (sizeof (celula));
	nova->chave= c;
	nova->prox= pilha->prox;
	pilha->prox= nova;
}

int bem_formada (char S[], celula *pilha){
	int i = 0;

	while (S[i] != '\0')
	{
		if (S[i] == '(' || S[i] == '{')
			insere (S[i], pilha);
		else{
			if ((S[i] == ')' && remover (pilha) == '(') || (S[i] == '}' && remover (pilha) == '{'));
			else
				return 0;
		}

		i++;
	}
	return 1;
}

int main (void){
	char S[100];
	celula *pilha;

	pilha= (celula *) malloc (sizeof (celula));
	pilha->prox= NULL;

	scanf (" %s", S);

	printf ("%d\n", bem_formada (S, pilha));
	return 0;
}