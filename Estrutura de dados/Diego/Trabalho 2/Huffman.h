#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include "MinHeap.h"
#include <string>
#include <vector>
#include <map>

/* Sugestão para tabela de dispersão */
typedef std::pair<unsigned char, std::string> hentry;
typedef std::map<unsigned char, std::string> htable;

class Huffman
{
public:
    void frequencia(std::vector<char> arq);  //Conta a frequencia do elementos do vetor passador(arq) e armazena em uma tabela hash(freq)
    void codeTable(Node *no, std::string s); //Monta a tabela de codigos
    Node *HuffmanTree(MinHeap h);            //Monta arvore Huffman

    std::map<unsigned char, int> freq; //Armazena a frequencia de elementos em uma hash
    htable huff_table;                 //Tabela hash da tabela de vodigos
};

#endif