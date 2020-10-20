/**
 * @file main.cpp
 * @author João Víctor Zárate, Julio Huang
 * @brief Trabalho 1 - Progrmação Paralela
 * @version 0.1
 * @date 2020-10-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>

#include "Backtracking.h"
#include "Expansao.h"
#include "Arquivo.h"
#include "Grid.h"

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

    Grid grid(arq_entrada.buffer); //Cria grid e passa arquivo de entrada
    Expansao expand(grid);         //Cria expansão e passa o grid como argumento
}
