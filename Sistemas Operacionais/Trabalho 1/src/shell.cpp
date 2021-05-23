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

    // signal(SIGINT, sh.cmd_handler);

    while (1)
    {
        std::cout << sh.MYPS1;

        if (sh.checkExit())
        {
            std::cout << std::endl;
            return 0;
        }

        std::getline(std::cin, cmd);
        sh.set_command(cmd);

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
    if (!cmd.compare(0, 7, "history"))
    {
        print_command_history();
    }
    else if (!cmd.compare(0, 4, "kill", 4))
    {
        std::cout << "kill detect\n"; //TODO
    }
    else if (!cmd.compare(0, 6, "export", 6))
    {
        std::cout << "export detect\n"; //TODO
    }
    else if (!cmd.compare(0, 4, "echo", 4))
    {
        std::cout << "echo detect\n"; //TODO
    }
}

void Shell::set_command(std::string cmd)
{
    command_list.push_front(cmd);
}

std::list<std::string> Shell::get_command()
{
    return command_list;
}
/**
 * Caso o comando não seja reconhecido exibe uma mensagem de erro
 */
void Shell::cmd_handler(int sig)
{
    // signal(sig, SIG_IGN);
    // signal(SIGINT, cmd_handler);
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
 * TODO
 */
void Shell::print_command_history()
{
    std::list<std::string> command_list = get_command();
    std::list<std::string>::iterator k; // cria um iterador de string
    int tam;
    tam = command_list.size();

    if (tam > 50)
    {
        k = command_list.begin();
        for (int i = 0; i < 50; i++, k++)
        {
            std::cout << *k << std::endl;
        }
    }
    else
    {
        for (k = command_list.begin(); k != command_list.end(); k++)
        {
            std::cout << *k << std::endl;
        }
    }
}

/**
 * TODO
 * @param n
 */
void Shell::print_command_history(int n)
{
}