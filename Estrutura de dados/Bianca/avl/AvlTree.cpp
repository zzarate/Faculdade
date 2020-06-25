#include <stdio.h>
#include "AvlTree.h"
#include <math.h>


Node::Node(int value)
{
    info = value;
    left = right = 0;
    balance = 0;
}

AvlTree::AvlTree()
{
    root = 0;
    numberOfNodes = 0;
}

AvlTree::~AvlTree()
{
    numberOfNodes = 0;
    deleteTree(root);
}

int 
AvlTree::size()
{
    return numberOfNodes;
}

bool 
AvlTree::isEmpty()
{
    return numberOfNodes == 0;
}

void 
AvlTree::printPre()
{
    printPre(root);
}

void 
AvlTree::printOrder()
{
    printOrder(root);
}

void 
AvlTree::printPos()
{
    printPos(root);
}

Node* 
AvlTree::getRoot ()
{
    return root;
}

void AvlTree::printAscii(Node* node)
{
	static int offset = 0;

	for (int i = 0; i < offset; ++i)
		printf(" ");

	if (node == 0) {
		printf("-\n");
		return;
	}

	printf("%d %d\n", node->info, node->balance);

	offset += 3;
	printAscii(node->left);
	printAscii(node->right);
	offset -= 3;
}

bool AvlTree::insert(int info)
{
	bool h = false;

	return doInsert(info, root, h);
}

bool AvlTree::doInsert(int info, Node*& ptr, bool& h)
{
	if(ptr == 0)
    {
		ptr = new Node(info);
		numberOfNodes++;
		h = true;

		return true;
	}

	bool ret = false;

	if (ptr->info == info)
        return false;

    if (info < ptr->info)
	{
		ret = doInsert(info, ptr->left, h);

        if(h)
        {
            switch(ptr->balance)
            {
                case 1:
                    ptr->balance = 0;
                    h = false;
                    break;
                case 0:
                    ptr->balance = -1;
                    break;
                case -1:
                    rightRotation(ptr);
                    h = false;
            }
        }
	}
	else
    {
        ret = doInsert(info, ptr->right, h);

        if(h)
        {
            switch(ptr->balance)
            {
                case -1:
                    ptr->balance = 0;
                    h = false;
                    break;
                case 0:
                    ptr->balance = 1;
                    break;
                case 1:
                    leftRotation(ptr);
                    h = false;
            }
        }
	}
	return ret;
}

void AvlTree::rightRotation(Node*& pt)
{
    Node* ptu = pt->left;

    if (ptu->balance == -1)
    {
		//Rotação à direita
        pt->left = ptu->right;
        ptu->right = pt;
        pt->balance = 0;
        pt = ptu;
    }
    else
    {
		//Rotação dupla à direita
        //Primeira parte
        Node* ptv = ptu->right;
        
        ptu->right = ptv->left;
        ptv->left = ptu;
        //Segunda parte
        pt->left = ptv->right;
        ptv->right = pt;

        if (ptv->balance == -1)
            pt->balance = 1;
        else
            pt->balance = 0;

        if (ptv->balance == 1)
            ptu->balance = -1;
        else
            ptu->balance = 0;

        pt = ptv;
    }

    pt->balance = 0;
}

void AvlTree::leftRotation(Node*& pt)
{
    Node* ptu = pt->right;

    if (ptu->balance == 1)
    {
		//Rotação à esquerda
        pt->right = ptu->left;
        ptu->left = pt;
        pt->balance = 0;
        pt = ptu;
    }
    else
    {
		//Rotação dupla à esquerda
		//Primeira parte
        Node* ptv = ptu->left;
        ptu->left = ptv->right;
        ptv->right = ptu;
        //Segunda parte
        pt->right = ptv->left;
        ptv->left = pt;

        if (ptv->balance == 1)
            pt->balance = -1;
        else
            pt->balance = 0;

        if (ptv->balance == -1)
            ptu->balance = 1;
        else
            ptu->balance = 0;

        pt = ptv;
    }

    pt->balance = 0;
}

bool AvlTree::remove(int info)
{
	bool h = false;
	return doRemove(info, root, h);
}

bool AvlTree::doRemove(int info, Node*& ptr, bool& h)
{
	if(ptr == 0)
		return false;

	//int cmp = ptr->info - info;

	//Encontrou o nó
	if(ptr->info == info)
    {
		Node* aux = ptr;

		if(ptr->left == 0 || ptr->right == 0)//Zero ou um filho
        {
			ptr = aux->right != 0 ? aux->right : aux->left;
			h = true;
			numberOfNodes--;
			delete aux;
		}
		else
		{
			//Dois filhos, substitui pelo antecessor
			aux = ptr->left;

			while(aux->right != 0)
				aux = aux->right;

			ptr->info = aux->info;

			doRemove(ptr->info, ptr->left, h);

			if(h)
            {
				switch(ptr->balance)
				{
					case -1:
						ptr->balance = 0;
						break;
					case 0:
						ptr->balance = 1;
						h = false;
						break;
					case 1:
						removeLeftRotation(ptr, h);
				}
			}
		}

		return true;
	}

	bool ret;

	if(ptr->info < info)
    {
		ret = doRemove(info, ptr->right, h);

		if(h)
        {
			switch(ptr->balance)
			{
				case 1:
					ptr->balance = 0;
					break;
				case 0:
					ptr->balance = -1;
					h = false;
					break;
				case -1:
					removeRightRotation(ptr, h);
			}
		}
	}
	else
    {
		ret = doRemove(info, ptr->left, h);

		if(h)
        {
			switch(ptr->balance)
			{
				case -1:
					ptr->balance = 0;
					break;
				case 0:
					ptr->balance = 1;
					h = false;
					break;
				case 1:
					removeLeftRotation(ptr, h);
			}
		}
	}

	return ret;
}

void AvlTree::removeLeftRotation(Node*& ptr, bool& h)
{
	Node* ptrz = ptr->right;

	if(ptrz->balance >= 0)
    {
		//Rotação esquerda
		ptr->right = ptrz->left;
		ptrz->left = ptr;

		if(ptrz->balance == 0)
        {
			ptr->balance = 1;
			ptrz->balance = -1;
			h = false;
		}
		else//ptrz->balance == 1
		{
			ptr->balance = 0;
			ptrz->balance = 0;
		}

		ptr = ptrz;
	}
	else//ptrz->balance == -1
    {
		//Rotação dupla esquerda
		Node* ptry = ptrz->left;

		ptrz->left = ptry->right;
		ptry->right = ptrz;
		ptr->right = ptry->left;
		ptry->left = ptr;

		if(ptry->balance == 1)
			ptr->balance = -1;
		else
			ptr->balance = 0;

		if(ptry->balance == -1)
			ptrz->balance = 1;
		else
			ptrz->balance = 0;

		ptr = ptry;
		ptr->balance = 0;
	}
}

void AvlTree::removeRightRotation(Node*& ptr, bool& h)
{
    Node* ptrz = ptr->left;

    if(ptrz->balance <= 0)
    {
        ptr->left = ptrz->right;
        ptrz->right = ptr;

        if(ptrz->balance == 0)
        {
            ptr->balance = -1;
            ptrz->balance = 1;
            h = false;
        }
        else
        {
            ptr->balance = 0;
            ptrz->balance = 0;
        }

        ptr = ptrz;
    }
    else
    {
        Node* ptry = ptrz->right;

        ptrz->right = ptry->left;
        ptry->left = ptrz;
        ptr->left = ptry->right;
        ptry->right = ptr;

        if(ptry->balance == -1)
            ptr->balance = 1;
        else
            ptr->balance = 0;

        if(ptry->balance == 1)
            ptrz->balance = -1;
        else
            ptrz->balance = 0;

        ptr = ptry;
        ptr->balance = 0;
    }
}

bool AvlTree::contains(int info)
{
	Node* cur = root;
	int cmp;

	while(cur != 0)
    {
		cmp = cur->info - info;

		if(cmp == 0)
			return true;

		//cur = cmp < 0 ? cur->right : cur->left;

		if (cmp < 0)
            cur = cur->right;
        else
            cur = cur->left;

	}

	return false;
}

void AvlTree::printPre(Node* node)
{
	/*
	if(node != 0) {
		printf("%d\n", node->info);
		printPre(node->left);
		printPre(node->right);
	}
	*/
	printAscii(node);
}

void AvlTree::printOrder(Node* node)
{
	if(node != 0)
    {
		printOrder(node->left);
		printf("%d\n", node->info);
		printOrder(node->right);
	}
}

void AvlTree::printPos(Node* node)
{
	if(node != 0)
    {
		printPos(node->left);
		printPos(node->right);
		printf("%d\n", node->info);
	}
}

void AvlTree::deleteTree(Node* node)
{
	if(node != 0)
    {
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}


int AvlTree::heightNodeTree(Node* node)
{

	if(node==0)
        return 0;

    int x = heightNodeTree(node->left);
    int y = heightNodeTree(node->right);

    if (x > y)
        return x + 1;
    else
        return y + 1;
    //return x>y ? x+1 : y+1;

}

