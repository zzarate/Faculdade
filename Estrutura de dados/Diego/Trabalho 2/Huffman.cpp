#include "Huffman.h"

void Huffman::frequencia(std::vector<char> arq)
{
    for (int i = 0; arq[i]; i++)
    {
        if (freq.find(arq[i]) == freq.end())
        {
            freq[arq[i]] = 1;
        }
        else
        {
            freq[arq[i]]++;
        }
    }
}

//Monta árvore huffman
Node *Huffman::HuffmanTree(MinHeap h)
{
    while (h.size() > 1)
    {
        Node *temp_l = h.extract();              //Recebe o nó esquerdo
        Node *temp_r = h.extract();              //Recebe o nó direito
        int f = temp_l->freq() + temp_r->freq(); //Soma a frequencia dos nós
        Node *new_node = new Node(f, temp_l, temp_r);
        h.insert(new_node);
    }
    return h.extract();
}

//Faz pré ordem, armazenando o codigo huffman
void Huffman::codeTable(Node *no, std::string s)
{
    if (no->leaf())
    {
        hentry entrada(no->code(), s);
        huff_table.insert(entrada);
        return;
    }
    codeTable(no->left(), s + '0');
    codeTable(no->right(), s + '1');
}

void Huffman::compacta(Node *huff_tree, std::vector<char> text)
{
    std::string *s = new std::string();        //String temporaria
    buffer += toBinary(huff_table.size(), 16); //Converte o tamanho para binario e armazena no buffer
    getAlphabet(huff_tree, s);
    buffer += *s;                   //Concatena os caracteres contidos na arvore, para o buffer
    s->clear();                     //Limpa a string para utilizar novamente
    getBits(huff_tree, s);          //bits do percurso pré-ordem
    buffer += *s;                   //Armazena os bits no buffer
    int bits_lg = s->length();      //Guarda o tamanho da string usado nos bit
    s->clear();                     //Limpa a string para utilizar novamente
    writeText(text, s);             //Armazena os codigos huffman
    buffer += *s;                   //Armazena os codigos no buffer
    int bits_text = s->length();    //Guarda o tamanho da string usado no texto
    int bits = bits_lg + bits_text; //Guarda o tamanho da string de bits + texto
    int sobraTemp = bits;           //Quantidade de bits que houve sobra
    if ((bits % 8) != 0)            //Verifica se necessita completar bits
    {
        while ((bits % 8) != 0) //Enquanto não completar 1byte, adiciona 0
        {
            buffer += '0';
            bits++;
        }
    }
    sobraTemp = bits - sobraTemp;               //Calcula a quantidade de bits de sobra
    std::string sobra = toBinary(sobraTemp, 8); //Converte a sobra para binario
    buffer += sobra;                            //Armazena a sobra no ultimo byte
    delete s;
}

//Recebe a raiz da arvore de Huffman,e devolve uma string com todas as letras contidas, em binario
void Huffman::getAlphabet(Node *no, std::string *s)
{
    if (no->leaf())
    {
        *s += toBinary(no->code(), 8);
        return;
    }
    getAlphabet(no->left(), s);
    getAlphabet(no->right(), s);
}

//Recebe a raiz da arvore de Huffman,e devolve uma string com todas as letras contidas, em binario
void Huffman::getBits(Node *no, std::string *s)
{
    if (no->leaf())
    {
        *s += '1';
        return;
    }
    else
    {
        *s += '0';
    }
    getBits(no->left(), s);
    getBits(no->right(), s);
}

//Converte para string binaria e retorna essa string, n= tamanho do bit
std::string Huffman::toBinary(unsigned char k, int n)
{
    std::string s = "";
    for (int i = 0; i < n; i++)
    {
        s += (k & 128) ? "1" : "0";
        k <<= 1;
    }
    return s;
}

void Huffman::writeText(std::vector<char> text, std::string *s)
{
    for (int i = 0; text[i]; i++)
    {
        *s += huff_table[text[i]];
    }
}