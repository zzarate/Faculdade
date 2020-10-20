#include "Expansao.h"
#include <limits.h>

/**
 * @brief Construct a new Expansao:: Expansao object
 * 
 * @param grid Grid a ser utilizado
 */
Expansao::Expansao(Grid grid)
{
    fila.push(grid.getOrigem()); //coloca origem na fila
    while (fila.empty() != 0 && !achou)
    {   
        celula cel, celDest;
        cel = fila.front(); //acessa primeiro da fila
        fila.pop();         // Remove célula do início da fila
        celDest = grid.getDestino();
        if (std::get<0>(cel) == std::get<0>(celDest) && std::get<1>(cel) == std::get<1>(celDest)) // cel é o destino
            achou = true;
        else
        {
            for (int k = 0; k < 4; k++)
            { // No máximo 4 vizinhos
                long int i, j; //i e j do vizinho;
                i = vizinhoI(k, cel);
                j = vizinhoJ(k, cel);
                if(i < grid.linha && j < grid.coluna) 
                {
                    if (grid[i][j] == INT_MIN) 
                    {
                        grid[i][j] = grid[std::get<0>(cel)][std::get<1>(cel)] + 1; //ver se a celula vizinho eh igual a celula atual
                        celula viz (i, j); //crio uma celula viziho
                        fila.push(viz); // Insere célula viz no fim da fila
                    }
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

long int Expansao::vizinhoI(int k, celula cel)
{
    switch (k)
    {
        case 0:
            return std::get<0>(cel);
        break;
        case 1:
            return std::get<0>(cel);
        break;
        case 2:
            return std::get<0>(cel) + 1;
        break;
        case 3:
            return std::get<0>(cel) - 1;
        break;
    }

}
long int Expansao::vizinhoJ(int k, celula cel)
{
    switch (k)
    {
        case 0:
            return std::get<1>(cel) - 1;
        break;
        case 1:
            return std::get<1>(cel) + 1;
        break;
        case 2:
            return std::get<1>(cel);
        break;
        case 3:
            return std::get<1>(cel);
        break;
    }
}
