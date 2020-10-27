/**
 * @brief Classe 
 * 
 */

#include <queue>
#include "Grid.h"

class Expansao
{
private:
    std::queue<celula> fila; //Fila a ser armazenado as celulas a serem expandidas

public:
    Expansao(Grid &grid);
    ~Expansao();

    bool achou = false; //Variavel para saber se o destino foi encontrado
};