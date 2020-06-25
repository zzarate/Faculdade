#include "node.h"
#include <stdio.h>

class BinaryTree
{
	public:
		Node* root;
		
		//Construtor: constrói uma árvore vazia
		BinaryTree()
		{
			root = 0;
		}
		
		//Percursos
		void preOrder(Node*);
		void inOrder(Node*);
		void posOrder(Node*);
		
		//Visita
		void visitNode(Node*);
		
		//Busca
		Node* findNode(int, Node*&);
		
		//Inserção
		bool addNode(int);
		void doAddNode(int, Node*);
		
		//Remoção
		bool removeNode(int);
		void doRemoveNode(Node*, Node*);
		
		//Destrutor
		~BinaryTree();
		
		void clear(Node*);
};
