/**
 * @file Expansao.h
 * @brief Operações da expansão
 * @version 1.0
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <queue>
#include "Grid.h"

using namespace std;

class Expansao
{
private:
    queue<celula> fila; //Fila a ser armazenado as celulas a serem expandidas

public:
    Expansao(Grid &grid);
    ~Expansao();

    bool achou = false; //Variavel para saber se o destino foi encontrado
};