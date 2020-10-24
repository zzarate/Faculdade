#include "Grid.h"

/**
 * @brief Construct a new Grid:: Grid object
 * 
 * @param info Vetor com os dados para construir o Grid
 */
Grid::Grid(std::vector<char> info)
{
    std::string *buffer = new std::string();
    char c = NULL; //Caractere lido
    int linha_arq; //Controle da linha do arquivo
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
            } else //Caso seja a parte de obstaculos
            {
                /* code */
            }
            
        }

        /*
        do//Pega a quantidade de linhas do grid
        {
            c=info[i];
            buffer->push_back(c);
        } while (c!= ' ');
        linhas= stoi(*buffer);
        buffer->clear(); //Limpa o buffer
        
        do//Pega a quantidade de colunas do grid
        {
            c=info[i];
            buffer->push_back(c);
        } while (c!= ' ' || c!= '\n');
        colunas= stoi(*buffer);
        buffer->clear();//Limpa o buffer

        do//Pega a celula de origem i
        {
            c=info[i];
            buffer->push_back(c);
        } while (c!= ' ');
        origem.first= stoi(*buffer);
        buffer->clear();//Limpa o buffer

        do//Pega a celula de origem j
        {
            c=info[i];
            buffer->push_back(c);
        } while (c!= ' ' || c!= '\n');
        origem.second= stoi(*buffer);
        buffer->clear();//Limpa o buffer
    */
    }

    delete buffer;
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
