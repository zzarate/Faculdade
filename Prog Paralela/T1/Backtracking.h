/**
 * @file Backtracking.h
 * @brief Operações do backtracking
 * @version 1.0
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Expansao.h"

#include <stack>

class Backtracking
{
private:
    std::stack<celula> pilha; // Caminho da origem até o destino

public:
    Backtracking(Grid &grid, Expansao &expand);
    ~Backtracking();
    
    std::string menor_caminho; //Menor caminho
    void menorCaminho(Grid grid);
};