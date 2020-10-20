#include "Expansao.h"
#include <limits.h>

/**
 * @brief Construct a new Expansao:: Expansao object
 * 
 * @param grid Grid a ser utilizado
 */
Expansao::Expansao(Grid grid)
{
    celula cel;

    fila.push(origem);
    while (fila.empty() != 0 && !achou)
    {
        cel = fila.front();
        fila.pop();                                   // Remove célula do início da fila
        if (cel.i == destino.i && cel.j == destino.j) // cel é o destino
            achou = true;
        else
        {
            for (int k = 0; k < 4; k++)
            { // No máximo 4 vizinhos

                if (Grid[viz.i][viz.j] == INT_MIN)
                {
                    Grid[viz.i][viz.j] = Grid[cel.i][cel.j] + 1;
                    fila.push(viz); // Insere célula viz no fim da fila
                }
            }
        }
    }
}

/**
 * @brief Destroy the Expansao:: Expansao object
 * 
 */
Expansao::~Expansao()
{
}

int Expansao::vizinhoI(int k, celula cel)
{
    int i;
    //...
    return i;
}
int Expansao::vizinhoJ(int k, celula cel)
{
    int j;
    //...
    return j;
}
