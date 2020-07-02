/**************************************************
*                                                 *
* João Víctor Zárate Pereira Araújo               *
* Trabalho 2                                      *
* Professor(a): Diego Padilha Rubert              *
*                                                 *
***************************************************/

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Erro! Deve-se passar 3 argumentos:\n";
        std::cout << "Operação a ser realizada (c ou d), ";
        std::cout << "arquivo de entrada e arquivo de saida.\n";
        exit(1);
    }

    if (*argv[1] == 'c')
    {
        /* code */
    }
    else if (*argv[1] == 'd')
    {
        /* code */
    }
    else
    {
        std::cout << "Operação a ser realizada incorreta!";
        exit(1);
    }
}