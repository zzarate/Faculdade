#include "AvlTree.h"

#include <stdio.h>

int main()
{
	AvlTree* bt = new AvlTree();
	int n;
	int x;
	
	printf("Digite a quantidade de numero que deseja inserir: \n");
	scanf ("%d", &n);

	for(int i = 0; i < n; i++){
		printf("Digite um numero para ser inserido:\n");
		scanf("%d", &x);
		bt->insert(x);
	}

	printf("Impressao: \n");
	bt->printAscii(bt->getRoot());
	
    printf("\nAdicionei o -1:\n");
	bt->insert(-1);
	bt->printAscii(bt->getRoot());

    //bt->remove(25);
    /*bt->remove(50);
	printf("\n Removi o 50\n");
	bt->printAscii(bt->getRoot());

    bt->remove(12);
	printf("\n Removi o 12\n");
	bt->printAscii(bt->getRoot());
	*/
	delete bt;

	return 0;
}
