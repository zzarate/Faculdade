#include "Grid.h"

/**
 * @brief Construct a new Grid:: Grid object
 * 
 * @param info Vetor com os dados para construir o Grid
 */
Grid::Grid(std::vector<char> info)
{
    int *i = 0;              //Controle de caractere lido do vetor
    int quant_obstaculo = 0; //Numero de obstaculos no grid
    linhas = salvaInfo(info, *i);
    colunas = salvaInfo(info, *i);
    origem.first = salvaInfo(info, *i);
    origem.second = salvaInfo(info, *i);
    quant_obstaculo = salvaInfo(info, *i);

}

/**
 * @brief Salva tamanho, origem e destino do grid
 * 
 * @param info Vector<char> com os dados a serem lidos
 * @param i Variavel de controle da posição do vetor a ser lido
 * @return int Dado lido do vetor
 */
int Grid::salvaInfo(std::vector<char> info, int &i)
{
    std::string *buffer = new std::string(); //String temporaria
    char c;                                  //Varialver auxiliar
    do
    {
        c = info[i];
        buffer->push_back(c);
        i++;
    } while (c != ' ' || c != '\n');
    int dado_int = stoi(*buffer); //Converte a string em int
    buffer->clear();              //Limpa o buffer
    delete buffer;                //Deleta string criada
    return dado_int;
}

/**
 * @brief Salva e preenche os obstaculos do grid
 * 
 * @param info 
 * @param i 
 */
void Grid::obstaculo(std::vector<char> info, int &i)
{
}

Grid::~Grid()
{
}

/**
 * @brief Retorna a quantidade de linhas do grid
 * 
 * @return long int Quantidade de linhas do grid
 */
long int Grid::getLinhas()
{
    return linhas;
}

/**
 * @brief Retorna a quantidade de colunas do grid
 * 
 * @return long int Quantidade de colunas do grid
 */
long int Grid::getColunas()
{
    return colunas;
}

/**
 * @brief Retorna o conteudo de uma celula
 * 
 * @param cell Celula a ser acessada
 * @return long int Conteudo da celula
 */
long int Grid::getvalorCelula(celula cell)
{
    return grid[cell.first][cell.second];
}

/**
 * @brief Retorna a celula de origem
 * 
 * @return celula Celula de origem
 */
celula Grid::getOrigem()
{
    return origem;
}

/**
 * @brief Retorna a celula de destino
 * 
 * @return celula Celula de destino
 */
celula Grid::getDestino()
{
    return destino;
}

long int Grid::vizinhoI(int k, celula cel)
{
    switch (k)
    {
        case 0:
            return cel.first;
        break;
        case 1:
            return cel.first;
        break;
        case 2:
            return cel.first + 1;
        break;
        case 3:
            return cel.first - 1;
        break;
    }

}
long int Grid::vizinhoJ(int k, celula cel)
{
    switch (k)
    {
        case 0:
            return cel.second - 1;
        break;
        case 1:
            return cel.second + 1;
        break;
        case 2:
            return cel.second;
        break;
        case 3:
            return cel.second;
        break;
    }
}