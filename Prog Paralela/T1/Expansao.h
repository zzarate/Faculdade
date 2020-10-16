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
    Expansao(/* args */);
    ~Expansao();
    void expandir(celula origem);
};