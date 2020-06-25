#include "lcc.h"

int main()
{
	LCC* lista;
	
	lista = new LCC();
	
	lista->cabeca->prox = new No(10);
	
	//Inserções
	lista->insere_cabeca(60);
	
	lista->imprime_lcc();
	
	lista->insere_cabeca(50);
	
	lista->imprime_lcc();
	
	lista->insere_cabeca(40);
	
	lista->imprime_lcc();
	
	lista->remove_no(50);
	
	lista->imprime_lcc();
	
	delete lista;
	
	return 0;
}
