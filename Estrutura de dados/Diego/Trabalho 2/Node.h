#include <iostream>

/* Nó de uma árvore de Huffman */
class Node {
private:
  int f;     // Frequência
  char c;    // Código ASCII
  Node *l;   // Filho esquerdo
  Node *r;   // Filho direito
  
public:
  Node(int f, int c, Node *l = NULL, Node *r = NULL); // Construtor
  Node(int f = 0, Node *l = NULL, Node *r = NULL);    // Construtor
  int freq(void);    // Devolve a frequência do caractere
  char code(void);   // Devolve o código do caractere
  Node *left(void);  // Devolve o filho esquerdo
  Node *right(void); // Devolve o filho direito
  bool leaf(void);   // Devolve true se é folha e false caso contrário
};