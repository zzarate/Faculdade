#include "Backtracking.h"

Backtracking::Backtracking(Grid grid)
{
    if (achou)
    {
        celula cel;
        cel = grid.getDestino();
        pilha.push(grid.getDestino()); //coloca destino na pilha
        
        while (cel.first != grid.getOrigem().first || cel.second != grid.getOrigem().second) // Enquanto não chegar na origem
        {
            for (int k = 0; k < 4; k++)
            { // No máximo 4 vizinhos
                long int i, j; //i e j do vizinho;
                i = vizinhoI(k, cel);
                j = vizinhoJ(k, cel);
                grid.grid[i][j] == grid.grid[cel.first][cel.second] - 1;
                celula viz (i, j);
                cel = viz;
                pilha.emplace(cel); // Insere célula viz na pilha
            }
        }
    }
}

Backtracking::~Backtracking()
{
}