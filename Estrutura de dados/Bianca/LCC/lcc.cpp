#include "lcc.h"

//Construtor: cria uma lista com cabeca vazia
LCC::LCC()
{
	cabeca = new No();
}

//Inserção no começo (após cabeca)
void 
LCC::insere_cabeca(int chave)
{
	cabeca->prox = new No(chave, cabeca->prox);
	
	//cabeca->prox = novo;
}

//Remove o nó que contém a chave recebida como argumento
void 
LCC::remove_no(int chave)
{
	//Busca a chave
	No *ant, *ptr;
	
	ant = cabeca;
	ptr = cabeca->prox;
	
	while (ptr != 0 && ptr->chave != chave)
	{
		ant = ptr;
		ptr = ptr->prox;
	}
	
	if (ptr != 0)//if (ptr)
	{
		//Encontrei
		ant->prox = ptr->prox;
		
		delete ptr;
	}
	else
		printf("Chave %d não encontrada", chave);
}

void 
LCC::imprime_lcc()
{
	
	if (cabeca->prox == 0)
		printf("Lista vazia\n");
	else
	{
		for (No* ptr = cabeca->prox; ptr != 0; ptr = ptr->prox)
			printf("%d ", ptr->chave);
			
		printf("\n");
	}		
}

LCC::~LCC()
{
	for (No* ptr = cabeca; ptr != 0;)
	{
		No* aux = ptr->prox;
		delete ptr;
		
		ptr = aux;
	}
}
