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

    /*
    for (auto &&i : info)
    {
        c = info[i]; //Armazena o caractere i de info no c

        //Enquanto não tiver nova linha ou espaço, salva o caractere
        if (c != ' ' || c != '\n')
        {
            buffer->push_back(c);
        }
        else
        {
            if (linha_arq < 3) //Caso seja a parte de linhas, colunas, origem e destino
            {
                if (c == ' ')
                {
                    switch (linha_arq)
                    {
                    case 0:
                        linhas = stoi(*buffer); //Salva a quantidade de linhas do grid
                        buffer->clear();        //Limpa o buffer
                        break;

                    case 1:
                        origem.first = stoi(*buffer); //Salva a celula de origem i
                        buffer->clear();              //Limpa o buffer
                        break;

                    case 2:
                        destino.first = stoi(*buffer); //Salva a celula de destino i
                        buffer->clear();               //Limpa o buffer
                        break;

                    default:
                        break;
                    }
                }
                else if (c == '\n')
                {
                    switch (linha_arq)
                    {
                    case 0:
                        colunas = stoi(*buffer); //Salva a quantidade de colunas do grid
                        buffer->clear();         //Limpa o buffer
                        linha_arq++;
                        break;

                    case 1:
                        origem.second = stoi(*buffer); //Salva a celula de origem j
                        buffer->clear();               //Limpa o buffer
                        linha_arq++;
                        break;

                    case 2:
                        destino.second = stoi(*buffer); //Salva a celula de destino j
                        buffer->clear();                //Limpa o buffer
                        linha_arq++;
                        break;

                    default:
                        break;
                    }
                }
            }
            else //Caso seja a parte de obstaculos
            {
                if (linha_arq == 3)
                {
                    int quant_obstaculos = stoi(*buffer); //Salva a quantide de obstaculos
                    buffer->clear();                      //Limpa o buffer
                    linhas++;
                } else
                {
                    if (c == ' '){
                        
                    }
                }
                
            }
        }
    }
*/
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
