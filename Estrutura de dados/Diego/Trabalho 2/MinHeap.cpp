#include "MinHeap.h"

MinHeap::MinHeap()
{
}

MinHeap::~MinHeap()
{
    int tamanho = v.size();
    for (int i = 0; i < tamanho; i++)
    {
        delete (extract());
    }
}

int MinHeap::size(void)
{
    return v.size();
}

void MinHeap::insert(Node *n)
{
    v.push_back(n);
    int aux = size() - 1;
    up(aux);
}

Node *MinHeap::extract(void)
{
    Node *min = NULL;
    if (size() > 0)
    {
        min = v[0];
        v[0] = v.back();
        v.pop_back();
        down(0);
    }
    return min;
}

void MinHeap::up(int i)
{
    if (i && v[parent(i)] < v[i])
    {
        std::swap(v[i], v[parent(i)]);
        up(parent(i));
    }
}

void MinHeap::down(int i)
{
    int l, r, smlr;
    l = left(i);
    r = right(i);

    if (l < size() && v[l]->freq() < v[i]->freq())
        smlr = l;
    else
        smlr = i;
    if (r < size() && v[r]->freq() < v[smlr]->freq())
        smlr = r;
    if (smlr != i)
    {
        std::swap(v[i], v[smlr]);
        down(smlr);
    }
}

int MinHeap::parent(int i)
{
    return (i - 1) / 2;
}

int MinHeap::left(int i)
{
    return (2 * i) + 1;
}

int MinHeap::right(int i)
{
    return (2 * i) + 2;
}