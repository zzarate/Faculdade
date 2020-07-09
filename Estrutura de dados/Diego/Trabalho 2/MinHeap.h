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
  MinHeap();            // Construtor padrão
  ~MinHeap();           // Destrutor padrão
  int size(void);       // Tamanho da heap
  void insert(Node *n); // Inserir elemento
  Node *extract(void);  // Remover (menor) elemento
};
