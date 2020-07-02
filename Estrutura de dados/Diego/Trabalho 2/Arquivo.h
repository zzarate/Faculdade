#include <cstdio>

class Arquivo
{
public:
    Arquivo(char *nome_arq, char op);  //Construtor para arquivo
    ~Arquivo(); //Destrutor padrão
    void Abrir();
    void Escreve();
    
    FILE *arquivo;
};