/* Encontrar o menor numero em uma lista encadeada*/

#include <stdlib.h>
#include <stdio.h>

//Define uma estrutura do tipo celula
typedef struct cel {
	int chave;
	struct cel *prox;
} celula;

/***************************************************** Lista com cabeça **********************/	

//Insere novas celulas na lista com cabeça
void insereC (int y, celula *p){
	celula *nova;

	nova= (celula *) malloc (sizeof (celula));
	nova-> chave= y;
	nova->prox= p->prox;
	p->prox= nova;
}

/****************** Lista com cabeça interativa  ********/

//Busca o menor elemento nas chaves das celulas da lista
celula *busca_minC (celula *lst){
	celula *p, *q;

	p= lst->prox;
	q= lst->prox;

	while (p != NULL){
		if (p->chave < q->chave ){ // Compara o conteudo da chave
			q->chave= p->chave;
		}
		p= p->prox;
	}

	return q;
}

//Funcao principal para lista com cabeça não recursiva
void lst_cabeca_int(){
	int k, n;
	celula *lista, *r;

	lista= (celula *) malloc (sizeof (celula));
	lista->prox= NULL;

	printf("Digite a quantidade de elementos: \n");
	scanf ("%d", &k);

	if (k>0){
		printf("Digite os elementos: \n");
		for (int i=0; i<k; i++){
			scanf ("%d", &n);
			insereC (n, lista);
		}

		r= busca_minC (lista);

		printf("%d é o menor elemento.\n", r->chave);
	}
	else
		printf("Lista vazia!\n");
}


/******************** Lista com cabeça recursiva ***********/

//Busca o menor elemento nas chaves das celulas
celula *busca_min_rec_C (celula *lst){
	celula *p;
	p= lst->prox;

	if (p->prox == NULL){
		return p;
	}
	if (lst->prox->chave < p->prox->chave){
		return lst->prox;
	}

	return busca_min_rec_C (lst->prox);
}

//Função principal para lista com cabeça recursiva
void lst_cabeca_rec (){
	int k, n;
	celula *lista, *r;

	lista= (celula *) malloc (sizeof (celula));
	lista->prox= NULL;

	printf("Digite a quantidade de elementos: \n");
	scanf ("%d", &k);

	if (k>0){
		printf("Digite os elementos: \n");
		for (int i=0; i<k; i++){
			scanf ("%d", &n);
			insereC (n, lista);
		}

		r= busca_min_rec_C (lista);
		printf("%d é o menor elemento.\n", r->chave);
	}
	else
		printf("Lista vazia!\n");
}

/*********************************************** Lista sem cabeça *****************************/

//Insere novas celulas sem cabeça
void insereS(int y, celula **lst){
	celula *nova;

	nova= (celula *) malloc (sizeof (celula));
	nova->chave= y;
	nova->prox= *lst;
	*lst= nova;
}

/*************** Lista sem cabeça interativa ****************/

//Busca o menor elemento nas chaves das celulas
celula *busca_minS(celula *lst){
	celula *p, *q;

	p= lst;
	q= lst;
	while(p != NULL){
		if(q->chave > p->chave){
			q->chave = p->chave;
		}
		p= p->prox;
	}
	return q;
}

//Função principal para lista sem cabeça interativa
void lst_s_int(){
	int k, n;
	celula *lista, *r;

	lista= NULL;

	printf("Digite a quantidade de elementos: \n");
	scanf ("%d", &k);
	if (k>0){
		printf("Digite os elementos: \n");
		for (int i=0; i<k; i++){
			scanf ("%d", &n);
			insereS (n, &lista);
		}

		r= busca_minS (lista);
		printf("%d é o menor elemento.\n", r->chave);
	}
	else
		printf("Lista vazia!\n");
}

/******************** Lista sem cabeça recursiva ***********/

//Busca o menor elemento nas chaves das celulas
celula *busca_min_rec_S(celula *lst){
	celula *p;

	p= lst;
	if(p->prox == NULL){
		return p;
	}

	if(lst->chave < lst->prox->chave){
		return lst;
	}
	
	return busca_min_rec_S (lst->prox);
}

//Função principal para lista sem cabeça recursiva
void lst_s_rec(){
	int k, n;
	celula *lista, *r;

	lista= NULL;

	printf("Digite a quantidade de elementos: \n");
	scanf ("%d", &k);
	if (k>0){
		printf("Digite os elementos: \n");
		for (int i=0; i<k; i++){
			scanf ("%d", &n);
			insereS (n, &lista);
		}

		r= busca_min_rec_S (lista);
		printf("%d é o menor elemento.\n", r->chave);
	}
	else
		printf("Lista vazia!\n");
}



/****************** Menu *************************/
void menu (){
	printf(" 1- Lista com cabeça interativa\n");
	printf(" 2- Lista com cabeça recursiva\n");
	printf(" 3- Lista sem cabeça interativa\n");
	printf(" 4- Lista sem cabeça recursiva\n");
	printf("\n");
	printf(" 0- Sair\n");
	printf("\n");
	printf("Digite uma opção: \n");
}


/**************** Main *************************/
int main (){
	int opt;

	menu();

	scanf ("%d", &opt);

	switch (opt){
		case 1:
		lst_cabeca_int();
		break;

		case 2:
		lst_cabeca_rec();
		break;

		case 3:
		lst_s_int();
		break;

		case 4:
		lst_s_rec();
		break;

		case 0:
		return 0;
		break;

		default:
		printf("Opção invalida!\n");
		break;
	}
	return 0;
}