//
// Created by Joao Victor Zarate on 09/05/2021.
//

#include "include/shell.h"

int main(int argc, char *argv[])
{
//    char *cmd_str; //String do comando digitado
	char cmd_str[100];
    Shell sh; //Objeto Shell


    if ((signal(SIGINT, sh.handle_error) == SIG_ERR))
    {
        printf("Error while setting a signal handler\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("\nMyShell$ ");
        fgets(cmd_str, 100, stdin);

        if (strncmp(cmd_str, "exit", 4) == 0 || sh.checkExit())
        { //FIXME
            exit(0);
        }
    }

    return EXIT_SUCCESS;
}

/**
 * Construtor da Shell
 */
Shell::Shell()
{

}

/**
 * Destrutor da Shell
 */
Shell::~Shell()
{

}


/**
 * Verificar se eh EOF (Ctrl + D)
 * @return 1 se for EOF, 0 se não for EOF
 * */
int Shell::checkExit()
{
    if (feof(stdin))
        return 1;
    int c = getc(stdin);
    if (c == EOF)
        return 1;
    ungetc(c, stdin);
    return 0;
}

/**
 * Caso o comando não seja reconhecido exibe uma mensagem de erro
 */
void Shell::handle_error(int)
{
	printf("Comando não encontrado.\n");
}

/**
 * TODO
 */
void Shell::print_command_history()
{
}

/**
 * TODO
 * @param n
 */
void Shell::print_command_history(int n)
{
}