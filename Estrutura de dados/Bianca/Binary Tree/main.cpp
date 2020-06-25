#include "binary_tree.h"

int main()
{
	BinaryTree* arvore;
	
	arvore = new BinaryTree();
	
	//Inserções
	arvore->addNode(5);
	arvore->addNode(2);
	arvore->addNode(6);
	arvore->addNode(1);
	arvore->addNode(4);
	arvore->addNode(8);
	arvore->addNode(3);
	arvore->addNode(7);
	
	printf("In ordem\n");
	arvore->inOrder(arvore->root);
	
	int num;
	
	scanf("%d", &num);
	
	arvore->removeNode(num);
	printf("In ordem\n");
	arvore->inOrder(arvore->root);


	/*printf("\nPre Ordem\n");
	arvore->preOrder(arvore->root);
	printf("\nPos Ordem\n");
	arvore->posOrder(arvore->root);
	
	
	Node* parent = 0;
	bool achou = arvore->findNode(-2, parent);
	
	if (achou)
		printf("Achei e o pai é %d\n", parent->info);
	else
		printf("Nao achei e parei em %d\n", parent->info);
	*/
	
		
	delete arvore;
	
	return 0;
}
