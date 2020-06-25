#include "BTreeNode.h"

BTreeNode::BTreeNode(int t)
{
	n = 0;
	leaf = true;
	key = new int[2 * t - 1];
	c = new BTreeNode*[2 * t];
	
	for (int i = 0; i < 2 * t; i++)
		c[i] = 0;
	
	parent = 0;
}
