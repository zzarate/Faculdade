#include "Expansao.h"

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
        if (cel.first == celDest.first && cel.second == celDest.second) // cel é o destino
            achou = true;
        else
        {
            for (int k = 0; k < 4; k++)
            {                  // No máximo 4 vizinhos
                long int i, j; //i e j do vizinho;
                i = grid.vizinhoI(k, cel);
                j = grid.vizinhoJ(k, cel);
                if (i < grid.getLinhas() && j < grid.getColunas())
                {
                    if (grid.grid[i][j] == INT32_MIN)
                    {
                        grid.grid[i][j] = grid.grid[cel.first][cel.second] + 1; //ver se a celula vizinho eh igual a celula atual
                        celula viz(i, j);                                       //crio uma celula viziho
                        fila.push(viz);                                         // Insere célula viz no fim da fila
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
