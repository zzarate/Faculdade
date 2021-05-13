//
// Created by Joao Victor Zarate on 09/05/2021.
//

#include "include/sh.h"

static void end_handler(int)
{
    printf("Comando não encontrado.\n");
}

int main(int argc, char *argv[])
{
    char cmd[100];
    sh *shell = new sh();

    if ((signal(SIGINT, end_handler) == SIG_ERR))
    {
        printf("Error while setting a signal handler\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("\nMyShell$ ");
        fgets(cmd, 100, stdin);

        if (strncmp(cmd, "exit", 4) == 0 || shell.checkExit())
        { //FIXME
            exit(0);
        }
    }

    return EXIT_SUCCESS;
}

/**
 * Verificar se eh EOF (Ctrl + D)
 * @return 1 se for EOF, 0 se não for EOF
 * */
int sh::checkExit() 
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
 * Print
 */
void sh::print_command_history()
{
}

void sh::print_command_history(int n)
{
}