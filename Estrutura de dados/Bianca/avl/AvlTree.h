#ifndef _AVLTREE_H_
#define _AVLTREE_H_

class Node
{
    public:
        Node* left;
        Node* right;
        int balance;
        int info;      
        
        Node(int);
};

class AvlTree
{
    private:
        Node* root;
        int numberOfNodes;

        bool doInsert(int, Node*&, bool&);
        bool doRemove(int, Node*&, bool&);

        void rightRotation(Node*&);
        void leftRotation(Node*&);
        void doubleRightRotation(Node*&);
        void doubleLeftRotation(Node*&);
        void removeLeftRotation(Node*&, bool&);
        void removeRightRotation(Node*&, bool&);

    public:
        AvlTree();
        ~AvlTree();

        bool insert(int);
        bool remove(int);
        bool contains(int);
        void deleteTree(Node*);
        int heightNodeTree(Node*);


        void printAscii(Node*);
        void printPre(Node*);
        void printOrder(Node*);
        void printPos(Node*);

        int size();
        bool isEmpty();
        void printPre();
        void printOrder();
        void printPos();
        Node* getRoot();
};

#endif
