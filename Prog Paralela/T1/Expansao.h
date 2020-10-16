/**
 * @brief Classe 
 * 
 */

#include <queue>
#include "Grid.h"

class Expansao
{
private:
    bool achou = false;
    std::queue<celula> fila;

public:
    void expandir(celula origem);
};