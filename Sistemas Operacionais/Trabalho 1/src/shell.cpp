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
//	Shell::dir = getcwd(); //Salva diretorio atual
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
        Shell::echo(cmd);
    }
    else if (!cmd.compare(0, 2, "cd", 2))
	{
		Shell::change_dir(cmd);
	}
    else
		Shell::exec_app(cmd);
}

/**
 * Salva a string passada como argumento na lista de comandos exectados
 * @param cmd std::string do comando digitado
 */
void Shell::set_command(std::string cmd)
{
    command_list.push_front(cmd);
}

/**
 *  Obtem a lista de comandos executados
 * @return std::list<std::string> com todos os comandos executados
 */
std::list<std::string> Shell::get_command()
{
    return command_list;
}

/**
 * Required
 */
void Shell::cmd_handler(int sig)
{
	//Do nothing
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
 * Imprime os 50 ultimos comandos digitados na shell
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

int Shell::change_dir(std::string dir)
{
	return 0;
}

/**
 * Executa um novo processo
 * @param cmd nome do processo a ser executado
 * @return retorna 1 em caso de erro e 0 caso contrario
 */
int Shell::exec_app(std::string cmd)
{
	std::string args_str;
	std::string proc;
	size_t pos;
	char *args_ptr;

	pos  = cmd.find_first_of(" ");
    proc = cmd.substr(0, pos - 1);

    if (pos != std::string::npos)
    {
		args_str = cmd.substr(pos + 1, std::string::npos);
		std::strcpy(args_ptr, args_str.c_str());
	}


    pid_t pid = fork();

    if (pid == -1)
    {
        return 1;
    }
    else if (pid == 0)
    {
        if (execvp(proc.c_str(), &args_ptr) < 0)
        {
            std::cout << proc << " não encontrado" << std::endl;
        }
        exit(0);
    }
    else
    {
        wait(NULL);
        return 0;
    }
}

/**
 * Imprime cadeia de caracteres
 * @param s cadeia de carateres a ser imprimida
 */
void Shell::echo(std::string s)
{
	std::string echo = s.substr(4, std::string::npos);

	if(echo.length() > 4)
		echo.assign(echo,1,echo.length());

	if (!echo.compare(0, 1, "$", 1))
		Shell::print_env(echo.substr(1, std::string::npos));
	else
		std::cout << echo + "\n";
}

/**
 * Imprime variavel de ambiente passada como argumento
 * @param var nome da variavel de ambiente
 */
void Shell::print_env(std::string var)
{
}