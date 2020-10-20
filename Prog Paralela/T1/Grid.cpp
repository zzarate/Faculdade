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
 * @brief Retorna a quantidade de linhas do grid
 * 
 * @return unsigned int Quantidade de linhas do grid
 */
unsigned int Grid::getLinhas()
{
    return linhas;
}

/**
 * @brief Retorna a quantidade de colunas do grid
 * 
 * @return unsigned int Quantidade de colunas do grid
 */
unsigned int Grid::getColunas()
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
