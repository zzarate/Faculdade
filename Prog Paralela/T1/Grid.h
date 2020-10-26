#include <iostream>
#include <vector>
#include <string>

typedef std::pair<long int, long int> celula; //Celula [i] [j];

class Grid
{
private:
    long int linhas;  //Quantidade de linhas do grid
    long int colunas; //Quantidade de colunas do grid

    celula origem;  //Celula de origem
    celula destino; //Celula de destino

    int salvaInfo(std::vector<char> info, int &i);
    void obstaculo(std::vector<char> info, int &i);

public:
    Grid(std::vector<char> info);
    ~Grid();

    std::vector<std::vector<long int>> grid; //Grid

    long int vizinhoI(int k, celula cel);
    long int vizinhoJ(int k, celula cel); 

    long int getLinhas();
    long int getColunas();
    long int getvalorCelula(celula cell);
    celula getOrigem();
    celula getDestino();
};
