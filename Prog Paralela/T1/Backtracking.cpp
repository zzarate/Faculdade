#include "Backtracking.h"

/**
 * @brief Construct a new Backtracking:: Backtracking object
 * 
 * @param grid Grid 
 * @param expand 
 */
Backtracking::Backtracking(Grid &grid, Expansao &expand)
{
    if (expand.achou)
    {
        celula cel;
        cel = grid.getDestino();       //coloca destino na cel
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
                    if (grid.grid[i][j] == grid.grid[cel.first][cel.second] - 1)
                    {
                        celula viz(i, j); //cria uma celula vizinho
                        cel = viz;
                        pilha.emplace(cel); // Insere célula viz na pilha
                    }
                }
            }
        }
        pilha.push(grid.getOrigem());
    }
}

Backtracking::~Backtracking()
{
}

/**
 * @brief Armazena o menor caminho, e o caminho no std::string menor_caminho
 * 
 * @param grid Grid do caminho feito
 */
void Backtracking::menorCaminho(Grid grid)
{
    std::string s = std::to_string(grid.grid[grid.getDestino().first][grid.getDestino().second]);
    menor_caminho+= s;
    s.clear();
    menor_caminho += "\n";
    int tam = pilha.size();
    for (int i = 0; i < tam; i++)
    {
        s.clear();
        s = std::to_string(pilha.top().first);
        menor_caminho+= s;
        s.clear();
        menor_caminho +=  " ";
        s = std::to_string(pilha.top().second);
        menor_caminho+= s;
        s.clear();
        menor_caminho += "\n";
        pilha.pop();
    }
    menor_caminho.pop_back();
}