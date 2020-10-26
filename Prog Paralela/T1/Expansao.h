/**
 * @brief Classe 
 * 
 */

#include <queue>
#include "Grid.h"

class Expansao
{
private:
    std::queue<celula> fila;

public:
    Expansao(Grid grid);
    ~Expansao();

    bool achou = false;
};