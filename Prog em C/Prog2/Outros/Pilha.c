#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int chave;
	struct cel *prox;
}celula;

void empilharS(int y, celula **t){
	celula *nova;
	nova = (celula *) malloc (sizeof (celula));

	nova->chave= y;
	nova->prox= *t;
	*t= nova;
}

void desempilhaS(celula **t){
	celula *p;
	
	if (*t != NULL){
		p = *t;
		*t = p->prox;
		free(p);
	}
	else{
		printf("Pilha vazia!\n");
	}
}

void menu (){
	printf("1- Empilha\n");
	printf("2- Desempilha\n");
	printf("3- Imprime\n");
	printf("0- Sair\n");
}

int main(void){
	int y, n, opt;
	celula *t;
	t= NULL;

	menu();
	scanf("%d", &opt);
	switch (opt){
		case 1:
		printf("Quantos numeros para empilhar?\n");
		scanf("%d", &n);
		for(int i= 0; i<n; i++){
			scanf ("%d", &y);
			empilharS (y, &t);
		}
		

		case 2:
		printf("Quantos numeros para desempilhar?\n");
		scanf("%d", &n);
		for(int i= 0; i<n; i++){
			desempilhaS(&t);
		}
		

		case 3:
		while(t != NULL){
		printf("%d ", t->chave);
		t= t->prox;
		}
		printf("\n");
		break;

		case 0:
		return 0;
		break;
		
	}	
	return 0;
}