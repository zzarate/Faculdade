/**
 * @brief 
 * 
 */

#include "Grid.h"
#include <stack>
#include <Expansao.h>

class Backtracking
{
private:
    std::stack<celula> pilha; // Caminho da origem até o destino
    bool achou = true;
public:
    Backtracking(Grid grid);
    ~Backtracking();
    long int vizinhoI(int k, celula cel); //procurar o vizinho da celula e devover posicao i
    long int vizinhoJ(int k, celula cel); //procurar o vizinho da celula e devover posicao j
};


