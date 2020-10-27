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
    std::string menor_caminho; //Menor caminho

    void menorCaminho();

public:
    Backtracking(Grid &grid, Expansao &expand);
    ~Backtracking();
};