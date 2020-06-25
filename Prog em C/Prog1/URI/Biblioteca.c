/* Objetivo: cadastrar livros em uma biblioteca, remover e consultar livros 
em seu acervo*/


#include <stdio.h>

struct livro {
	char nome[40];
	char autor[20];
	int volume;
};

void opc(){
	printf("1 - Cadastrar\n");
	printf("2 - Consultar\n");
	printf("3 - Remover\n");
	printf("4 - Pesquisar\n");
	printf("0 - Sair\n");
}

int main(){

	int opt;

	opc();
	scanf ("%d%*c", &opt);
	switch (opt){
		case 1:
		printf("Nome: \n");
		scanf ("%s[^/n")
	}
}