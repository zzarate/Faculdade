#include <iostream>
#include <vector>

class Arquivo
{
public:
    Arquivo(char *nome_arq, char *op);
    ~Arquivo();
    void Escrever(std::string texto);
    void Ler();

    std::vector<char> buffer; //Armazena os caracteres lido do arquivo

private:
    FILE *arquivo; //Arquivo aberto
};