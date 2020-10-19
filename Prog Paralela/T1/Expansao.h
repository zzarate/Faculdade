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
    void expandir(celula origem, celula destino);
    int vizinhoI(int k, celula cel); //procurar o vizinho da celula e devover posicao i
    int vizinhoJ(int k, celula cel); //procurar o vizinho da celula e devover posicao j
};