#include "Expansao.h"

void expandir(celula origem) {

    fila.push (origem);
    while (fila.empty() != 0 && !achou) {
        cel = remove(Fila) // Remove célula do início da fila
        if (cel.i == destino.i AND cel.j == destino.j) // cel é o destino
        achou = true
    else {
        for (cada célula viz vizinha de cel) // No máximo 4 vizinhos
            if (Grid[viz.i][viz.j] == infinito) {
                Grid[viz.i][viz.j] = Grid[cel.i][cel.j] + 1
                insere(Fila, viz) // Insere célula viz no fim da fila
            }
        }
    }
}