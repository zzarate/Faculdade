
#include <iostream>

typedef std::pair<unsigned int, unsigned int> celula; //Celula [i] [j];

class Grid
{
private:
    unsigned int colunas;
    unsigned int linhas;
    unsigned int qnt_obstaculos;

    celula origem;
    celula destino;

public:
    Grid(/* args */);
    ~Grid();
};