//
// Created by Joao Victor Zarate on 09/05/2021.
//

#include "include/shell.h"

int main(int argc, char *argv[])
{
	std::string cmd;
    Shell sh; //Objeto Shell

    if ((signal(SIGINT, sh.cmd_handler) == SIG_ERR))
    {
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        std::cout << sh.MYPS1;
        std::getline(std::cin, cmd);

        /* Verify exit*/
		if (!cmd.compare(0, 4, "exit"))
		{
			return 0;
		}

        sh.verify_command(cmd);
    }

    return 0;
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

void Shell::verify_command(std::string cmd)
{

	if (!cmd.compare(0, 4, "kill", 4))
	{
		std::cout << "kill detect\n"; //TODO
	}

	if (!cmd.compare(0, 6, "export", 6))
	{
		std::cout << "export detect\n"; //TODO
	}

	if (!cmd.compare(0, 4, "echo", 4))
	{
		std::cout << "echo detect\n"; //TODO
	}
}

/**
 * Caso o comando não seja reconhecido exibe uma mensagem de erro
 */
void Shell::cmd_handler(int)
{
	if (feof(stdin))
	{
		std::cout << "\n";
		exit(0);
	}
	int c = getc(stdin);
	if (c == EOF)
	{
		std::cout << "\n";
		exit(0);
	}
	ungetc(c, stdin);
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