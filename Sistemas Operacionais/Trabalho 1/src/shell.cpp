//
// Created by Joao Victor Zarate on 09/05/2021.
//

#include "include/shell.h"

int main(int argc, char *argv[])
{
//    char *cmd_str; //String do comando digitado
	char cmd_str[100];
    Shell sh; //Objeto Shell

    if ((signal(SIGINT, sh.cmd_handler) == SIG_ERR))
    {
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        std::cout << sh.MYPS1;
        fgets(cmd_str, 100, stdin);


		/**
		 * Verify commands
		 */

        if (!strncmp(cmd_str, "exit", 4) || sh.checkExit())
        { //FIXME
            exit(0);
        }

        if (!strncmp(cmd_str, "kill", 4))
		{
			std::cout << "kill detect\n"; //TODO
		}

        if (!strncmp(cmd_str, "export", 6))
		{
			std::cout << "export detect\n"; //TODO
		}

        if (!strncmp(cmd_str, "echo", 4))
		{
			std::cout << "echo detect\n"; //TODO
		}
    }

    return EXIT_SUCCESS;
}

/**
 * Construtor da Shell
 */
Shell::Shell()
{
	MYPS1 = "tecii$: "; //Inicializa o prompt
}

/**
 * Destrutor da Shell
 */
Shell::~Shell()
{

}


/**
 * Verificar se eh EOF (Ctrl + D)
 * @return 1 se for EOF, 0 caso contrario
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
void Shell::cmd_handler(int)
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