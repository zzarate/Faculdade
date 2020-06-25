#ifndef _RBTREE_H_
#define _RBTREE_H_

#define RED   0
#define BLACK 1

class Node 
{
    public:
        Node* left;
        Node* right;
        Node* parent;
        int value;
        int color;

        Node();
        Node(int);
};

class RBTree 
{
    private:
        
        Node* nil;
        int numberOfNodes;

        void leftRotation(Node*);
        void rightRotation(Node*);
        Node* successor(Node*);
        void print(Node*);
        void insertFixUp(Node*&);
        void removeFixUp(Node*&);
        void deleteTree(Node*);

    public:
		Node* root;
        RBTree();
        ~RBTree();

        bool insert(int);
        bool remove(int);
        bool contains(int);

        void print();
        int size() const;
        bool isEmpty() const;
        
        int blackHeight(Node*);
};

#endif
