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
    long int vizinhoI(int k, celula cel); //procurar o vizinho da celula e devover posicao i
    long int vizinhoJ(int k, celula cel); //procurar o vizinho da celula e devover posicao j
};