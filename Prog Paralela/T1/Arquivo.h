#include <iostream>
#include <vector>

class Arquivo
{
public:
    Arquivo(char *nome_arq, char op);
    ~Arquivo();
    void Escrever(std::string texto);
    void Ler();                       

    /**
     * @brief Armazena os caracteres lido do arquivo
     */
    std::vector<char> buffer;

private:
    /**
     * @brief Arquivo aberto
     */
    FILE *arquivo;
};