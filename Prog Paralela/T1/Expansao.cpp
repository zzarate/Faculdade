/**
 * @file Expansao.cpp
 * @brief Implementação da classe Expansao.h
 * @version 1.0
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Expansao.h"

/**
 * @brief Construct a new Expansao:: Expansao object
 * 
 * @param grid Grid a ser utilizado
 */
Expansao::Expansao(Grid &grid)
{
    fila.push(grid.getOrigem()); //coloca origem na fila
    
    while (!(fila.empty()) && !(achou))
    {
        celula cel, celDest;
        cel = fila.front(); //acessa primeiro da fila
        fila.pop();         // Remove célula do início da fila
        celDest = grid.getDestino();
        if (cel.first == celDest.first && cel.second == celDest.second) // cel é o destino
            achou = true;
        else
        {   
            celula vizs[4];
            #pragma omp parallel
            {
                #pragma omp for nowait
                for (int k = 0; k < 4; k++)
                {                  // No máximo 4 vizinhos
                    long int i, j; //i e j do vizinho;
                    i = grid.vizinhoI(k, cel);
                    j = grid.vizinhoJ(k, cel);
                    
                    if (i < grid.getLinhas() && j < grid.getColunas() && i >= 0 && j >= 0)
                    {
                        if (grid.grid[i][j] == INT32_MAX)
                        {
                            grid.grid[i][j] = grid.grid[cel.first][cel.second] + 1; 
                            celula viz (i, j);                                       //crio uma celula viziho
                            vizs[k] = viz;                                         // Insere célula viz no fim da fila
                        }
                        else
                        {
                            celula nViz (-1, -1);
                            vizs[k] = nViz;
                        }
                    }
                    else
                    {
                        celula nViz (-1, -1);
                        vizs[k] = nViz;
                    }
                }
            }
            for(int k = 0; k < 4; k++){
                if(vizs[k].first != -1 || vizs[k].second != -1)
                    fila.push(vizs[k]);
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
