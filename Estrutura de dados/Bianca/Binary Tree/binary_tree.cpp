#include "binary_tree.h"

void
BinaryTree::preOrder(Node* node)
{
	visitNode(node);
	
	if (node->left != 0)
		preOrder(node->left);
		
	if (node->right != 0)
		preOrder(node->right);
}

void
BinaryTree::inOrder(Node* node)
{
	if (node->left != 0)
		inOrder(node->left);
		
	visitNode(node);
		
	if (node->right != 0)
		inOrder(node->right);
}

void
BinaryTree::posOrder(Node* node)
{	
	if (node->left != 0)
		posOrder(node->left);
		
	if (node->right != 0)
		posOrder(node->right);

	visitNode(node);

}

void
BinaryTree::visitNode(Node* node)
{
	printf("%d ", node->info);//Imprime o campo info
}

Node*
BinaryTree::findNode(int value, Node*& parent)
{
	Node* cur = root;
	
	while (cur != 0)
	{
		if (cur->info == value)
			return cur;
			
		parent = cur;
		
		if (cur->info > value)
			cur = cur->left;
		else
			cur = cur->right;
	}
	
	return cur;
}

bool
BinaryTree::addNode(int value)
{
	Node* parent = 0;
	Node* cur = findNode(value, parent);
	
	//Não encontrei, posso inserir
	if (cur == 0)
	{
		doAddNode(value, parent);
		
		return true;
	}
	
	return false;
}

void
BinaryTree::doAddNode(int value, Node* parent)
{
	if (parent != 0)
	{
		Node* novo = new Node(value);
		
		if (parent->info > value)
			parent->left = novo;
		else 
			parent->right = novo;
	}
	else
		root = new Node(value);
}

bool
BinaryTree::removeNode(int value)
{
	Node* parent = 0;
	Node* node = findNode(value, parent);
	
	//Encontrei, vou remover
	if (node != 0)
	{
		doRemoveNode(node, parent);
		
		return true;
	}
	
	return false;
}

void
BinaryTree::doRemoveNode(Node* node, Node* parent)
{
	Node *y, *x, *py;	
	
	if (node->left == 0 || node->right == 0) 
	{
		//Tem no máximo um filho
		y = node;
		py = parent;
	}
	else
	{
		//Tem dois filhos, precisa buscar o sucessor
		py = node;
		y = node->right;
		
		//Busca do sucessor (menor elemento da subárvore direita
		//ou seja, o elemento mais à esquerda)
		while (y->left != 0)
		{
			py = y;
			y = y->left;
		}
	}
	
	//Neste ponto, sabemos que y tem no máximo um filho,
	//podemos remover
	if (y->left != 0)//Tem o filho da esquerda
		x = y->left;
	else//Tem o filho da direita ou nenhum
		x = y->right;
		
	//x é o filho do nó a ser removido (ou 0)
	//Faço o pai de y ser o novo pai do filho de y
	if (py == 0)//Estou removendo a raiz
		root = x;
	else
	{
		if (y == py->left)
			py->left = x;
		else
			py->right = x;
			
		node->info = y->info;
	}
	
	delete y;
}

BinaryTree::~BinaryTree()
{
	clear(root);
}

void
BinaryTree::clear(Node* node)
{
	//Deleta os nós usando pós-ordem
	if (node)
	{
		clear(node->left);
		clear(node->right);
		
		delete node;		
	}
}
















