#include <iostream>
#include <vector>


class Arquivo
{
public:
    Arquivo(char *nome_arq, char op);  //Construtor
    ~Arquivo(); //Destrutor padrão
    void Escrever(); //Escreve em um arquivo
    void Ler(); //Realiza a leitura do arquivo
    std::vector <char> buffer;//Armazena os caracteres lido do arquivo

private:
    FILE *arquivo;
};