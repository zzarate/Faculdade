/**
 * @file Backtracking.cpp
 * @brief Implementação da classe Backtracking.h
 * @version 1.0
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "Backtracking.h"

/**
 * @brief Construct a new Backtracking:: Backtracking object
 * 
 * @param grid Grid a ser percorrido o caminho
 * @param expand Objeto de expansão do caminho
 */
Backtracking::Backtracking(Grid &grid, Expansao &expand)
{
    if (expand.achou)
    {
        celula cel;
        cel = grid.getDestino();       //coloca destino na cel
        pilha.push(grid.getDestino()); //coloca destino na pilha

        while (cel.first != grid.getOrigem().first || cel.second != grid.getOrigem().second) // Enquanto não chegar na origem
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
    string s = to_string(grid.grid[grid.getDestino().first][grid.getDestino().second]); //Converte para string o tamanho do caminho
    menor_caminho += s;                                                                 //Armazena o tamanho do camniho na string
    s.clear();                                                                          //Limpa a string
    menor_caminho += "\n";
    int tam = pilha.size();
    for (int i = 0; i < tam; i++) // Preenche a string de saida com as celulas do caminho
    {
        s.clear();                        //Limpa a string
        s = to_string(pilha.top().first); //Converte para string o elemento da primeira celula
        menor_caminho += s;
        s.clear(); //Limpa a string
        menor_caminho += " ";
        s = to_string(pilha.top().second); //Converte para string o elemento da segunda celula
        menor_caminho += s;
        s.clear(); //Limpa a string
        menor_caminho += "\n";
        pilha.pop(); //Remove celula lida da pilha
    }
    menor_caminho.pop_back();
}