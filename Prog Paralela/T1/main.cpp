/**
 * @file main.cpp
 * @author João Víctor Zárate, Julio Huang
 * @brief Trabalho 1 - Progrmação paralela
 * @version 0.1
 * @date 2020-10-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include "Arquivo.h"


int main(int argc, char *argv[])
{
    //Verifica se todos os parametros foram passados
    if (argc < 3)
    {
        std::cout << "Erro! Deve-se passar 3 argumentos:\n";
        exit(1);
    }

    Arquivo arq_entrada(argv[1], 'r'); //Cria um objeto e abre o arquivo passado como parametro
    arq_entrada.Ler();                 //Le os caracteres do arquivo de entrada
}