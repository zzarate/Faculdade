#include <stdlib.h>
#include <stdio.h>

typedef struct cel {
	int chave;
	struct cel *ant;
	struct cel *prox;
} celula;

void buscaC (int x, celula *lista){
	celula *p;

	p= lista->prox;

	while (p != NULL && p->chave != x){
		p= p->prox;
	}

	if (p != NULL)
		printf("Elemento encontrado!\n");
	else
		printf("Elemento não esta na lista!\n");
}

void buscaS (int x, celula *lista){
	celula *p;

	p=lista;

	while (p != NULL && p->chave != x){
		p= p->prox;
	}

	if (p != lista){
		printf("Elemento encontrado!\n");
	}
	else
		printf("Elemento não esta na lista!\n");
}

void insereC (int x, celula *lista){
	celula *p, *q, *nova;

	nova= (celula *) malloc(sizeof(celula));
	nova->chave= x;

	p= lista;
	q= lista->prox;

	while(q != NULL && q->chave < x){
		p= q;
		q= q->prox;
	}

	nova->prox= q;
	p->prox= nova;
}

void insereS (int x, celula **lista){
	celula *p, *q, *nova;

	p = NULL;
	q = *lista;

	nova= (celula *) malloc (sizeof (celula));
	nova->chave= x;

	while (q != NULL && q->chave < x){
		p= q;
		q= q->prox;
	}
	nova->prox = q;

	if (p != NULL)
		p->prox= nova;
	else
		*lista = nova;
}

void removeC (int x, celula *lista){
	celula *p, *q;

	p= lista;
	q= lista->prox;

	while (q != NULL && q->chave != x){
		p= q;
		q= q->prox;
	}
	if (q != NULL){
		p->prox= q->prox;
		free(q);
	}
}

void removeS(int x, celula **lista){
	celula *p, *q;

	p= NULL;
	q= *lista;

	while (q != NULL && q->chave != x){
		p= q;
		q= q->prox;
	}
	if (q != NULL){
		if (p != NULL){
			p->prox= q->prox;
			free(q);
		}
		else {
			*lista= q->prox;
			free(q);
		}
	}
}

void menu(){
	printf("1- Busca\n");
	printf("2- Inserir elemento\n");
	printf("3- Remover elemento\n");
	printf("4- Imprimir lista\n");
	printf("0- Sair\n");
}

void menu2 (){
	printf("1- Lista com cabeça\n");
	printf("2- Lista sem cabeça\n");
	printf("0- Sair\n");
}



int main (){
	int x, opt1, opt2;
	celula *lista, *p;

	lista= (celula *) malloc(sizeof(celula));

	menu2 ();
	scanf ("%d", &opt1);

	switch (opt1){
		case 1: //Lista com cabeça
		lista->prox= lista;
		lista->ant= lista;

		printf("Digite os elementos da lista(digte -1 para finalizar):\n");
		scanf("%d", &x);
		while(x != -1){
			insereC (x, lista);
			scanf("%d", &x);
		}

		do{
			menu();
			scanf("%d", &opt2);	
			
			switch(opt2){
				case 1:
				printf("Digite o elemento que deseja buscar: \n");
				scanf("%d", &x);
				buscaC (x, lista);
				break;

				case 2:
				printf("Digite o elemento que deseja inserir: \n");
				scanf("%d", &x);
				insereC(x, lista);
				break;

				case 3:
				printf("Digite o elemento que deseja remover: \n");
				scanf("%d", &x);
				removeC(x, lista);
				break;

				case 4:
				for(p = lista->prox; p != lista; p = p->prox)
					printf("%d ",p->chave);
				printf("\n");
				break;

				case 0:
				return 0;
				break;
			}
		}while (1);
		break;
		//Fim caso 1

		case 2: //Lista sem cabeça
		lista = (celula *) malloc(sizeof(celula));
		lista->prox = NULL;

		printf("Digite os elementos da lista(digte -1 para finalizar):\n");
		scanf("%d", &x);

		while(x != -1){
			insereS (x, &lista);
			scanf("%d", &x);
		}

		do{
			menu();
			scanf("%d", &opt2);	
			
			switch(opt2){
				case 1:
				printf("Digite o elemento que deseja buscar: \n");
				scanf("%d", &x);
				buscaS (x, lista);
				break;

				case 2:
				printf("Digite o elemento que deseja inserir: \n");
				scanf("%d", &x);
				insereS (x, &lista);
				break;

				case 3:
				printf("Digite o elemento que deseja remover: \n");
				scanf("%d", &x);
				removeS (x, &lista);
				break;

				case 4:
				for(p= lista->prox; p != lista; p= p->prox)
					printf("%d ",p->chave);
				printf("\n");
				break;

				case 0:
				return 0;
				break;
			}
		}while (1);
		break;
		//Fim caso 2

		case 0:
		return 0;
		break;
	}
	return 0;
}