#include "Node.h"

Node::Node(int f, int c, Node *l, Node *r)
{
    this->f = f;
    this->c = c;
    this->l = l;
    this->r = r;
}

Node::Node(int f, Node *l, Node *r)
{
    this->f = f;
    this->l = l;
    this->r = r;
}

int Node::freq(void)
{
    return f;
}

char Node::code(void)
{
    return c;
}

Node *Node::left(void)
{
    return l;
}

Node *Node::right(void)
{
    return r;
}

bool Node::leaf(void)
{
}