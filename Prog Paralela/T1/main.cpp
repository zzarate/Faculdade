/**
 * Versão sequencial
 * 
 * Usar make para compilar OU
 * Comando de compilação(sequencial): 
 * g++ -Wall -pedantic -std=c++11 -fopenmp -g -o rotseq *.cpp *.h
 * Comando de execução (sequencial):
 * ./rotseq entrada.txt saida.txt
 * 
 * @file main.cpp
 * @author João Víctor Zárate, Julio Huang
 * @brief Trabalho 1 - Progrmação Paralela
 * @version 1.0
 * @date 2020-10-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <omp.h> // Cabeçalho da biblioteca OpenMP

#include "Backtracking.h"
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

    double tIni, tFin, tExec; // Variaveis para armazenar o tempo de execução
    tIni = omp_get_wtime();   // Pega o tempo do inicio da execução

    Grid grid(arq_entrada.buffer);            //Cria grid e passa arquivo de entrada
    Expansao expand(grid);            //Cria expansão e passa o grid como argumento
    Backtracking backt(grid, expand); //Cria o backtraking e passa o grid como parametro
    backt.menorCaminho(grid);         //Armazena o menor caminho em uma string

    tFin = omp_get_wtime(); // Tempo da execução do final
    tExec = tFin - tIni;    //Calcula o tempo que foi necessário para executar
    std::cout << "Tempo de execução: " << tExec << "\n";

    //Imprimir menor caminho
    Arquivo arq_saida (argv[2], 'w');
    arq_saida.Escrever(backt.menor_caminho);

    exit(0);
}

#endif
