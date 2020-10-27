#include "Backtracking.h"

Backtracking::Backtracking(Grid &grid, Expansao &expand)
{
    if (expand.achou)
    {
        celula cel;
        cel = grid.getDestino(); //coloca destino na cel
        pilha.push(grid.getDestino()); //coloca destino na pilha

        while (cel.first != grid.getOrigem().first && cel.second != grid.getOrigem().second) // Enquanto não chegar na origem
        {
            for (int k = 0; k < 4; k++) // No máximo 4 vizinhos
            {                  
                long int i, j; //i e j do vizinho;
                i = grid.vizinhoI(k, cel);
                j = grid.vizinhoJ(k, cel);
                if (i < grid.getLinhas() && j < grid.getColunas() && i >= 0 && j >= 0)
                {
                    if(grid.grid[i][j] == grid.grid[cel.first][cel.second] - 1)
                    {
                        celula viz(i, j); //cria uma celula vizinho 
                        cel = viz;    
                        pilha.emplace(cel); // Insere célula viz na pilha
                    }
                }
            }
        }
    }
}

Backtracking::~Backtracking()
{
}