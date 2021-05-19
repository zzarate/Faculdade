#include "Arquivo.h"

/**
 * Recebe nome do arquivo, e operação que irá realizar (ler ou escrever) e abre o arquivo
 * @param nome_arq: nome do arquivo
 * @param op: modo que será aberto o arquivo (r = read, w = write)
 */
Arquivo::Arquivo(char *nome_arq, char op)
{
    switch (op)
    {
    /* Abre o arquivo para leitura */
    case 'r':
        if ((arquivo = fopen(nome_arq, "r")) == NULL)
        {
            perror("Erro ao abrir arquivo!");
            return 1;
        }
        break;

    /* Abre o arquivo para escrita */
    case 'w':
        if ((arquivo = fopen(nome_arq, "w")) == NULL)
        {
            perror("Erro ao abrir arquivo!");
			return 1;
        }
        break;

    /* Abre o arquivo para escrita */
    case 'w':
        if ((arquivo = fopen(nome_arq, "w")) == NULL)
        {
            perror("Erro ao abrir arquivo!");
			return 1;
        }
        break;

    /* Abre o arquivo para escrita */
    case 'w':
        if ((arquivo = fopen(nome_arq, "w")) == NULL)
        {
            perror("Erro ao abrir arquivo!");
			return 1;
        }
        break;

    default:
        std::cout << "Erro ao abrir arquivo!";
        return 1;
        break;
    }

    return 0;
}

/**
 * Destrutor padrão.
 * Fecha o arquivo aberto.
 */
Arquivo::~Arquivo()
{
    fclose(arquivo);
}

/**
 *  Realiza a leitura do arquivo aberto através do construtor Arquivo::Arquivo e armazena o conteudo
 *  lido em um  buffer (std::vector<char> buffer)
 */
void Arquivo::Ler()
{
    char c; /* Caractere lido */
    do
    {
        c = fgetc(arquivo);
        buffer.push_back(c); /* Adicionado o caractere lido na última posição do array */
    } while (c != EOF);
    buffer.pop_back();
}

/**
 * Escreve a string passada como parametro no arquivo aberto através do construtor Arquivo::Arquivo
 * @param texto: String que será escrita no arquivo
 */
void Arquivo::Escrever(std::string texto)
{
    for (int i = 0; i < (int)texto.size(); i++)
    {
        std::string byte;
        for (int j = 0; j < 8; j++)
        {
            byte += texto[j + i];
        }
        int saida = std::stoi(byte, nullptr, 2);
        putc(saida, arquivo);
        i += 7;
    }
}