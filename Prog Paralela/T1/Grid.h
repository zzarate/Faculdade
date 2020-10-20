

#include <iostream>
#include <vector>
#include <string>

typedef std::pair<long int, long int> celula; //Celula [i] [j];

class Grid
{
private:
    long int linhas;  //Quantidade de linhas do grid
    long int colunas; //Quantidade de colunas do grid

    long int leValor();

    celula origem;  //Celula de origem
    celula destino; //Celula de destino

public:
    Grid(std::vector<char> info);
    ~Grid();

    long int getLinhas();
    long int getColunas();
    celula getOrigem();
    celula getDestino();
};