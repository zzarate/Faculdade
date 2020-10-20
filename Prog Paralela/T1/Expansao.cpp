#include "Expansao.h"
#include <limits.h>

void Expansao::expandir(celula origem, celula destino) {
    celula cel;

    fila.push (origem);
    while (fila.empty() != 0 && !achou) {
        cel = fila.front();
        fila.pop(); // Remove célula do início da fila
        if (cel.i == destino.i && cel.j == destino.j) // cel é o destino
            achou = true;
        else {
            for (int k = 0; k < 4; k++) { // No máximo 4 vizinhos
            
                if (Grid[viz.i][viz.j] == INT_MIN) {
                    Grid[viz.i][viz.j] = Grid[cel.i][cel.j] + 1;
                    fila.push (viz); // Insere célula viz no fim da fila
                }
            }
        }
    }
}

int Expansao::vizinhoI(int k, celula cel) {
    int i;
    //...
    return i;
}
int Expansao::vizinhoJ(int k, celula cel) {
    int j;
    //...
    return j;
}

Expansao::Expansao(/* args */)
{
}

Expansao::~Expansao()
{
}
