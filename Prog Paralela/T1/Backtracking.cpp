#include "Backtracking.h"

Backtracking::Backtracking(/* args */)
{
    Caminho = vazio // Caminho da origem até o destino
    if (achou)
    {
        cel = destino
        insere(caminho, destino); // Insere destino no início do caminho
        // Enquanto não chegar na origem
        while (cel.i != origem.i || cel.j != origem.j)
        {
            Investiga 4 células vizinhas de cel e seleciona viz,
            tal que Grid[viz.i][viz.j] == Grid[cel.i][cel.j] - 1
            cel = viz
            insere(Caminho, viz); // Insere célula viz no início do caminho
        }
    }
}

Backtracking::~Backtracking()
{
}