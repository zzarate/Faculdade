/**
 * @brief 
 * 
 */

#include "Expansao.h"

#include <stack>

class Backtracking
{
private:
    std::stack<celula> pilha; // Caminho da origem até o destino

public:
    Backtracking(Grid grid, Expansao expand);
    ~Backtracking();
};