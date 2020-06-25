#include <stdlib.h>
#include <stdio.h>

typedef struct cel {
	int chave;
	struct cel *ant;
	struct cel *prox;
} celula;

void busca (int x, celula *lista){
	celula *p;

	p=lista->prox;

	while (p != lista && p->chave != x){
		p= p->prox;
	}

	if (p != lista){
		printf("Elemento encontrado!\n");
	}
	else
		printf("Elemento não esta na lista!\n");
}

void insere (int x, celula *lista){
	celula *nova;

	nova= (celula *) malloc (sizeof (celula));
	nova->chave= x;

	nova->ant= lista->ant;
	nova->prox= lista;
	lista->ant->prox= nova;
	lista->ant= nova;
}

void removec (int x, celula *lista){
	celula *p;

	p = lista->prox;

	while(p != lista && p->chave != x){
		p= p->prox;
	}

	p->prox->ant= p->ant;
	p->ant->prox= p->prox;
	free(p);

	if(p == lista){
		printf("Lista vazia\n");
	}

}

void menu(){
	printf("1- Busca\n");
	printf("2- Inserir elemento\n");
	printf("3- Remover elemento\n");
	printf("4- Imprimir lista\n");
	printf("0- Sair\n");
}

int main (){
	int x, opt;
	celula *lista, *p;
	
	lista= (celula *) malloc(sizeof(celula));
	lista->prox = lista;
	lista->ant = lista;

	printf("Digite os elementos da lista(digte -1 para finalizar):\n");

	scanf("%d", &x);
	while(x != -1){
		insere(x, lista);
		scanf("%d", &x);
	}

	do{
		menu();
		scanf("%d", &opt);	
		
		switch(opt){
			case 1:
			printf("Digite o elemento que deseja buscar: \n");
			scanf("%d", &x);
			busca (x, lista);
			break;

			case 2:
			printf("Digite o elemento que deseja inserir: \n");
			scanf("%d", &x);
			insere(x, lista);
			break;

			case 3:
			printf("Digite o elemento que deseja remover: \n");
			scanf("%d", &x);
			removec (x, lista);
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
	return 0;
}