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