#include "Grid.h"

/**
 * @brief Construct a new Grid:: Grid object
 * 
 * @param info Vetor com os dados para construir o Grid
 */
Grid::Grid(std::vector<char> info)
{
}

Grid::~Grid()
{
}

/**
 * @brief Le dados separados por espaço e/ou "/n"
 * 
 * @return long int Valor lido
 */
long int Grid::leValor()
{
    std::string *buffer = new std::string(); //Sring temporaria
    char c;                                  //Char lido do arquivo
    long int dado;                           //Dado lido

    do
    {
        buffer +=
    } while (c != ' ');

    delete buffer;
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
 * @brief Retorna a celula de origem
 * 
 * @return celula Celula de origem
 */
celula Grid::getOrigen()
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
