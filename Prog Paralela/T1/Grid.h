
#include <iostream>
#include <vector>

typedef std::pair<unsigned int, unsigned int> celula; //Celula [i] [j];

class Grid
{
private:
    unsigned int colunas;
    unsigned int linhas;

    celula origem;
    celula destino;

    //Obstaculo
    unsigned int qnt_obstaculos;
    std::vector<celula> obsta_cel_init;

public:
    Grid(std::vector<char> info);
    ~Grid();
};