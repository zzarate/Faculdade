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
    void frequencia(std::vector<char> arq); //Conta a frequencia do elementos do vetor passador(arq) e armazena em uma tabela hash(freq)
    Node *HuffmanTree(MinHeap h);           //Monta arvore Huffman
    std::map<unsigned char, int> freq;      //Armazena a frequencia de elementos em uma hash
    htable huff_table;

private:
    void inOrder(Node *no); //Realiza o percurso em ordem
};

#endif