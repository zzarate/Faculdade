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
    void frequencia(std::vector<char> arq);                 //Recebe um vetor com o texto e conta a frequencia do elementos do vetor passador(arq) e armazena em uma tabela hash(freq)
    void codeTable(Node *no, std::string s);                //Monta a tabela de codigos, recebe um no
    void compacta(Node *huff_tree, std::vector<char> text); //Compacta arquivo Huffman
    void limpa(Node *no);                                   //Limpa arvore huffman, recebe n*= raiz da arvore huffman
    Node *HuffmanTree(MinHeap h);                           //Monta arvore Huffman, recebe heap

    std::string buffer;                //Buffer do arquivo compactado
    std::map<unsigned char, int> freq; //Armazena a frequencia de elementos em uma hash
    htable huff_table;                 //Tabela hash da tabela de codigos

private:
    std::string toBinary(unsigned char k, int n);           //Converte um char (k) para uma string binaria e retorna essa string, n= tamanho do byte(8 bits ou 16 bits)
    void writeText(std::vector<char> text, std::string *s); //Armazena o texto com os codigos Huffman
    void getAlphabet(Node *no, std::string *s);             //Recebe a raiz da arvore de Huffman,e devolve uma string com todas as letras contidas, em binario
    void getBits(Node *no, std::string *s);                 //Recebe a raiz da arvore de Huffman,e devolve uma string com bits do percurso pré ordem
};

#endif