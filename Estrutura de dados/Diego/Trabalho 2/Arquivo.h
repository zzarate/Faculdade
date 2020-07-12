#include <iostream>
#include <vector>

class Arquivo
{
public:
    Arquivo(char *nome_arq, char op); //Recebe *nomer_arq= nome do arquivo, op= modo que irá abrir o arquivo
    ~Arquivo();                       //Destrutor padrão, fecha arquivo aberto
    void Escrever(std::string texto); //Cria arquivo. texto= recebe string com texto compactado e cria arquivo compactado
    void Ler();                       //Realiza a leitura do arquivo do arquivo aberto

    std::vector<char> buffer;         //Armazena os caracteres lido do arquivo

private:
    FILE *arquivo; //Arquivo aberto
};