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
        if (cel.first == celDest.first && cel.second == celDest.second) // cel é o destino
            achou = true;
        else
        {
            for (int k = 0; k < 4; k++)
            { // No máximo 4 vizinhos
                int i, j; //i e j do vizinho;
                i = vizinhoI(k, cel);
                j = vizinhoJ(k, cel);
                if(i < grid.linhas && j < grid.colunas) 
                {
                    if (grid[i][j] == INT_MIN) 
                    {
                        grid[i][j] = grid[cel.first][cel.second] + 1; //ver se a celula vizinho eh igual a celula atual
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
            return cel.first;
        break;
        case 1:
            return cel.first;
        break;
        case 2:
            return cel.first + 1;
        break;
        case 3:
            return cel.first - 1;
        break;
    }

}
long int Expansao::vizinhoJ(int k, celula cel)
{
    switch (k)
    {
        case 0:
            return cel.second - 1;
        break;
        case 1:
            return cel.second + 1;
        break;
        case 2:
            return cel.second;
        break;
        case 3:
            return cel.second;
        break;
    }
}
