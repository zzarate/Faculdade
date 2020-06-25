#include <stdio.h>
#include "RBTree.h"

//Implementações da classe Node
Node::Node()
{
    left = right = parent = 0;
    color = BLACK;
}

Node::Node(int value)
{
    this->value = value;
}

//Implementações da classe RBTree
RBTree::RBTree()
{
	nil = new Node();
	root = nil;
	numberOfNodes = 0;
}

RBTree::~RBTree()
{
	numberOfNodes = 0;
	deleteTree(root);
	delete nil;
}

void RBTree::print()
{
    print(root);
}

int RBTree::size() const
{
    return numberOfNodes;
}

bool RBTree::isEmpty() const
{
    return numberOfNodes == 0;
}

//Implementação da inserção de acordo com Cormen
bool RBTree::insert(int value)
{
	Node* y = nil;
	Node* x = root;

	while(x != nil)
    {
		y = x;

		if(x->value == value)
			return false;

		//x = value < x->value ? x->left : x->right;
       if (value < x->value)
           x = x->left;
       else
           x = x->right;
	}

	Node* node = new Node(value);
	node->parent = y;

	if(y == nil)
		root = node;
	else
    {
		if(value < y->value)
			y->left = node;
		else
			y->right = node;
	}

	node->left = nil;
	node->right = nil;
	node->color = RED;
	insertFixUp(node);

	numberOfNodes++;

	return true;
}

void RBTree::insertFixUp(Node*& node)
{
	Node* y;

	while(node->parent->color == RED)
    {
		if(node->parent == node->parent->parent->left)
        {
			y = node->parent->parent->right;

			if(y->color == RED) //Caso 1
            {
				node->parent->color = BLACK;
				y->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else 
            {
				if(node == node->parent->right)//Caso2
				{
					node = node->parent;
					leftRotation(node);
				}

				node->parent->color = BLACK;//Caso 3
				node->parent->parent->color = RED;
				rightRotation(node->parent->parent);
			}
		}
		else
        {
			y = node->parent->parent->left;

			if(y->color == RED)//Caso 1
            {
				node->parent->color = BLACK;
				y->color = BLACK;
				node->parent->parent->color = RED;
				node = node->parent->parent;
			}
			else
            {
				if(node == node->parent->left)//Caso 2
                {
					node = node->parent;
					rightRotation(node);
				}

				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				leftRotation(node->parent->parent);
			}
		}
	}//Fim do while

    //Colore a raiz de preto
	root->color = BLACK;
}

bool RBTree::remove(int value)
{
    Node* z = root;
    Node* x;
    Node* y;

    //Busca pelo elemento
    while(z != nil && z->value != value)
    {
       if (value < z->value)
           z = z->left;
       else
           z = z->right;
    }

	//Se chegou no nil, é porque não encontrou e não precisa remover
    if (z == nil)
        return false;

	//Tem 0 ou 1 filho
    if (z->left == nil || z->right == nil)
		y = z;
	else
		y = successor(z);

	if (y->left != nil)
		x = y->left;
	else
		x = y->right;

	x->parent = y->parent;

	if (y->parent == nil)
		root = x;
	else
	{
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	}

	if (y != z)
		z->value = y->value;

	if (y->color == BLACK)
		removeFixUp(x);

	delete y;

	return true;
}

void RBTree::removeFixUp(Node*& x)
{
    Node* w;

    while (x != root && x->color == BLACK)
    {
        //Se x for filho esquerdo
        if (x == x->parent->left)
        {
            w = x->parent->right;

            if (w->color == RED) //Caso 1
            {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotation(x->parent);
                w = x->parent->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK) //Caso 2
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->right->color == BLACK) //Caso 3
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotation(w);
                    w = x->parent->right;
                }

                //Caso 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotation(x->parent);

                x = root;
            }
        }
        else //x é filho direito
        {
            w = x->parent->left;

            if (w->color == RED) //Caso 1
            {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotation(x->parent);
                w = x->parent->left;
            }

            if (w->right->color == BLACK && w->left->color == BLACK) //Caso 2
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK) //Caso 3
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotation(w);
                    w = x->parent->left;
                }

                //Caso 4
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotation(x->parent);

                x = root;
            }
        }
    }
    x->color = BLACK;
}

Node* RBTree::successor(Node* node)
{
    Node* suc = node->right;

    while (suc->left != nil)
        suc = suc->left;

    return suc;
}

bool RBTree::contains(int value)
{
	Node* x = root;

	while(x != nil)
    {
		if(x->value == value)
			return true;

		//x = value < x->value ? x->left : x->right;
       if (value < x->value)
           x = x->left;
       else
           x = x->right;
	}

	return false;
}

void RBTree::leftRotation(Node* node)
{
	Node* y = node->right;
	node->right = y->left;

	if(y->left != nil)
		y->left->parent = node;

	y->parent = node->parent;
	if(node->parent == nil)
		root = y;
	else
    {
		if(node == node->parent->left)
			node->parent->left = y;
		else
			node->parent->right = y;
	}

	y->left = node;
	node->parent = y;
}

void RBTree::rightRotation(Node* node)
{
	Node* y = node->left;
	node->left = y->right;

	if(y->right != nil)
		y->right->parent = node;

	y->parent = node->parent;
	if(node->parent == nil)
		root = y;
	else
    {
		if(node == node->parent->right)
			node->parent->right = y;
		else
			node->parent->left = y;
	}

	y->right = node;
	node->parent = y;
}

void RBTree::deleteTree(Node* node)
{
	if(node != nil)
    {
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

void RBTree::print(Node* node)
{
	static int offset = 0;

	for (int i = 0; i < offset; ++i)
		printf(" ");

	if (node == nil)
    {
		printf("-[B]\n");
		return;
	}

	if(node->color == BLACK)
		printf("%d[B]\n", node->value);
	else
		printf("%d[R]\n", node->value);

	offset += 3;
	print(node->left);
	print(node->right);
	offset -= 3;
}

int RBTree::blackHeight(Node* node)
{
	if (node == nil)
		return 0;
		
	if (node->left->color == BLACK)
		return blackHeight(node->left) + 1;
	
	return blackHeight(node->left);
}
