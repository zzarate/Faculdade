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

    //Preenche todas as posições do grid con "infinito"(maior valor de long int)
    for (int k = 0; k < linhas; k++)
    {
        for (int l = 0; l < colunas; l++)
        {
            grid[k][l] = INT32_MAX;
        }
    }

    //Preenche os obstaculos com -1
    for (int j = 0; j < quant_obstaculo; j++)
    {
        obstaculo(info, *i);
    }
}

Grid::~Grid()
{
}

/**
 * @brief Salva tamanho, origem e destino do grid
 * 
 * @param info Vector<char> com as informções lidas do arquivo
 * @param i Ponteiro com indice da posição do vetor
 * @return int Dado lido do vetor
 */
int Grid::salvaInfo(std::vector<char> info, int &i)
{
    std::string *buffer = new std::string(); //String temporaria
    char c = '0';                            //Varialver auxiliar
    do
    {
        c = info[i];
        buffer->push_back(c);
        i++;
    } while (c != ' ' || c != '\n');
    int dado_int = stoi(*buffer); //Converte a string em int
    delete buffer;                //Deleta string criada
    return dado_int;
}

/**
 * @brief Salva e preenche os obstaculos do grid
 * 
 * @param info Vector<char> com as informções lidas do arquivo
 * @param i Ponteiro com indice da posição do vetor
 */
void Grid::obstaculo(std::vector<char> info, int &i)
{
    int i_inicial, j_inicial, linhas, colunas;
    std::string *buffer = new std::string(); //String temporaria
    char c = '0';                            //Varialver auxiliar

    //Pega o indice i inicial
    do
    {
        c = info[i];
        buffer->push_back(c);
        i++;
    } while (c != ' ' || c != '\n');
    i_inicial = stoi(*buffer); //Converte a string em int
    buffer->clear();           //Limpa o buffer
    c = '0';

    //Pega o indice j inicial
    do
    {
        c = info[i];
        buffer->push_back(c);
        i++;
    } while (c != ' ' || c != '\n');
    j_inicial = stoi(*buffer); //Converte a string em int
    buffer->clear();           //Limpa o buffer
    c = '0';

    //Pega o número de linhas
    do
    {
        c = info[i];
        buffer->push_back(c);
        i++;
    } while (c != ' ' || c != '\n');
    linhas = stoi(*buffer); //Converte a string em int
    buffer->clear();        //Limpa o buffer
    c = '0';

    //Pega o número de colunas
    do
    {
        c = info[i];
        buffer->push_back(c);
        i++;
    } while (c != ' ' || c != '\n');
    colunas = stoi(*buffer); //Converte a string em int
    buffer->clear();         //Limpa o buffer
    c = '0';

    //Preenche os retangulos com -1
    for (int k = i_inicial; k < (i_inicial + linhas) - 1; k++)
    {
        for (int l = j_inicial; l < (j_inicial + colunas) - 1; l++)
        {
            grid[k][l] = -1;
        }
    }

    delete buffer; //Deleta string criada
}

/**
 * @brief 
 * 
 * @param k 
 * @param cel 
 * @return long int 
 */
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
    return -1;
}

/**
 * @brief 
 * 
 * @param k 
 * @param cel 
 * @return long int 
 */
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
    return -1;
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