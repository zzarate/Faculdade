#include "no.h"
#include <stdio.h>

class LCC
{
	private:
		No* cabeca;
		
	public:
		//Construtor: cria uma lista com cabeca vazia
		LCC();
		
		//Inserção no começo (após cabeca)
		void insere_cabeca(int);
		
		//Remove o nó que contém a chave recebida como argumento
		void remove_no(int);
		
		void imprime_lcc();
		
		//Destrutor
		~LCC();
};
