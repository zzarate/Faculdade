
#include <iostream>
#include <vector>

typedef std::pair<unsigned int, unsigned int> celula; //Celula [i] [j];

class Grid
{
private:
    unsigned int linhas;  //Quantidade de linhas do grid
    unsigned int colunas; //Quantidade de colunas do grid

    celula origem;  //Celula de origem
    celula destino; //Celula de destino

    //Obstaculo
    unsigned int qnt_obstaculos;
    std::vector<celula> obsta_cel_init;

public:
    Grid(std::vector<char> info);
    ~Grid();

    unsigned int getLinhas();
    unsigned int getColunas();
    celula getOrigen();
    celula getDestino();
};