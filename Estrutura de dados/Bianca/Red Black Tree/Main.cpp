#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RBTree.h"

int main()
{
	RBTree* tree = new RBTree();

	//srand(time(NULL));

    printf("\nInsercoes:\n");
    
    tree->insert(10);
	printf("\nInseriu o 10:\n");
	tree->print();

	tree->insert(5);
	printf("\nInseriu o 5:\n");
	tree->print();
	
	tree->insert(20);
	printf("\nInseriu o 20:\n");
	tree->print();
	
	tree->insert(25);
	printf("\nInseriu o 25:\n");
	tree->print();
	
	tree->insert(15);
	printf("\nInseriu o 15:\n");
	tree->print();
	
	tree->insert(18);
	printf("\nInseriu o 18:\n");
	tree->print();
	
	tree->insert(13);
	printf("\nInseriu o 13:\n");
	tree->print();
	
	tree->insert(19);
	printf("\nInseriu o 19:\n");
	tree->print();

    printf("\nRemocao do 10:\n");
    tree->remove(10);
    tree->print();

    printf("\nRemocao do 19:\n");
    tree->remove(19);
    tree->print();

    printf("\nRemocao do 13:\n");
    tree->remove(13);
    tree->print();

    printf("\nRemocao do 15:\n");
    tree->remove(15);
    tree->print();
    
    
    printf("\n Black height = %d\n", tree->blackHeight(tree->root));

	delete tree;
	
	return 0;
}
