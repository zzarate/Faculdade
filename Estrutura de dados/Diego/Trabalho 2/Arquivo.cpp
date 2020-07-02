#include <iostream>
#include <Arquivo.h>

/*Recebe nome do arquivo, e operação que irá realizar *
 * (ler ou escrever) e abre o arquivo*/
Arquivo::Arquivo(char *nome_arq, char op)
{
    switch (op)
    {
    /*Apenas abre o arquivo para leitura*/
    case 'r':
        if ((arquivo = fopen(nome_arq, "r")) == NULL)
        {
            perror("Erro ao abrir arquivo!");
            exit(1);
        }
        break;
    /*Abre o arquivo para escrita*/
    case 'w':
        if ((arquivo = fopen(nome_arq, "w")) == NULL)
        {
            perror("Erro ao abrir arquivo!");
            exit(1);
        }
        break;

    default:
        std::cout << "Erro ao abrir arquivo!";
        break;
    }
}

Arquivo::~Arquivo()
{
}

void Arquivo::Abrir()
{
}

void Arquivo::Escreve()
{
}
