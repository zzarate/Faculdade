#include <vector>
#include "Node.h"

/* Lista de min-prioridades (min-heap) com nós de uma árvore de
   Huffman, utilizando a frequência como chave */
class MinHeap
{
private:
  std::vector<Node *> v; // Elementos
  void up(int i);        // Sobe
  void down(int i);      // Desce
  int parent(int i);     // Pai
  int left(int i);       // Filho esquerdo
  int right(int i);      // Filho direito

public:
  int size(void);       // Tamanho da heap, devolve tamnho da heap
  void insert(Node *n); // Inserir elemento, insere no passado como parametro na heap
  Node *extract(void);  // Remover (menor) elemento e devolve ele
  void limpa(Node *x);  //Deleta arvore Huffman, recebe raiz da arvore
};
