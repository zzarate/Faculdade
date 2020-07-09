/**************************************************
*                                                 *
* João Víctor Zárate Pereira Araújo               *
* Trabalho 2                                      *
* Professor(a): Diego Padilha Rubert              *
*                                                 *
***************************************************/

#include <iostream>
#include "Arquivo.h"
#include "Huffman.h"
#include "Node.h"

int main(int argc, char *argv[])
{
    //Verifica se todos os parametros foram passados
    if (argc < 4)
    {
        std::cout << "Erro! Deve-se passar 3 argumentos:\n";
        std::cout << "Operação a ser realizada (c ou d), ";
        std::cout << "arquivo de entrada e arquivo de saida.\n";
        exit(1);
    }

    //Verifica qual operação para ser executada foi passada (c= compactar, d= descompactar)
    if (*argv[1] == 'c')
    {
        Arquivo arq_entrada(argv[2], 'r'); //Cria um objeto e abre o arquivo passado como parametro
        arq_entrada.Ler();                 //Le os caracteres do arquivo de entrada

        //Conta a frequencia do elementos e armazena em uma tabela hash
        Huffman huff; //Objeto da classe Huffman
        huff.frequencia(arq_entrada.buffer);
        MinHeap heap; //Objeto da classe Min Heap
        //Envia a frequencia dos caracteres para min heap
        for (auto &it : huff.freq)
        {
            Node *no = new Node(it.second, it.first);
            heap.insert(no);
        }
        huff.freq.clear();                        //Limpa a hash usada para contar a frequencia
        Node *huff_tree = huff.HuffmanTree(heap); //Cria a arvore Huffman
        //Faz em ondem
        huff.codeTable(huff_tree,"");

        /* code */
    }
    else if (*argv[1] == 'd')
    {
        Arquivo arq_entrada(argv[2], 'r'); //Cria um objeto e abre o arquivo passado como parametro
        arq_entrada.Ler();                 //Le os caracteres do arquivo de entrada

        /* code */
    }
    else
    {
        std::cout << "Operação a ser realizada incorreta!";
        exit(1);
    }
}