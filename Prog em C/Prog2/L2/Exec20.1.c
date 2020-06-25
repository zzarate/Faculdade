#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int chave;
	struct cel *prox;
}celula;

void enfilera(int y, celula **f, celula **i){	
	celula *nova;

	nova= (celula *) malloc (sizeof (celula));
	nova->chave= y;

	if(*f == NULL){
		nova->prox = NULL;
		*f = nova;
		*i = *f;
	}

	else{
		nova->prox = NULL;
		(*f)->prox = nova;
		*f = nova;
	}
}

void desemfilera(celula **i){
	celula *p;
	p = *i;
	if(*i != NULL){
		*i = p->prox;
		free(p);
	}
	else{
		printf("Fila vazia");
	}

}

void menu(){
	printf("1-Enfileirar\n");
	printf("2-Desemfileirar\n"); 
	printf("3-Imprimir\n");
	printf("0- Sair\n");
	printf("Digite sua opcao: \n");
}

int main (){
	int y, n, caso;
	celula *i, *f, *p;
	i = NULL; f = NULL;

	menu ();
	scanf("%d", &caso);

	switch (caso){
		case 1:
		printf("Quantidade de numeros a ser inserido: \n");
		scanf("%d", &n);
		for(int j=0; j<n; j++){
			scanf("%d", &y);
			enfilera(y, &f, &i);
		}

		case 2:
		printf("Quantidade de numeros a ser removido da fila: \n");
		scanf("%d", &n);
		for(int j=0; j<n; j++){
			desemfilera(&i);
		}

		case 3:
		p= i;
		while(p != NULL){
			printf("%d ", p->chave);
			p= p->prox;
		}
		printf("\n");
		break;

		case 0:
		return 0;
		break;

		default :
		printf("Opcao invalida\n");
		break;
	}
	return 0;
}
