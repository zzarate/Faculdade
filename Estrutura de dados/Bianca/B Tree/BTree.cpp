#include "BTree.h"

BTree::BTree(int t)
{
	root = new BTreeNode(t);
	
	DISK_WRITE(root);
}
