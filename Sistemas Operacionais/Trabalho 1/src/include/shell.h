//
// Created by Joao Victor Zarate on 09/05/2021.
//

#ifndef TRABALHO_1_SHELL_H
#define TRABALHO_1_SHELL_H

#include <iostream>
#include <cstdio>
#include <list>

#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

/********************
 * Local Includes	*
 ********************/
#include "Arquivo.h"

class Shell
{
private:
	void print_command_history(int n);
	int exec_app(std::string cmd);
	int change_dir();
	void echo(std::string s);

	std::list<std::string> command_list;
	std::list<char> path_list;

	std::string dir;

public:
	Shell();
	~Shell();

	static void cmd_handler(int);

	void verify_command(std::string cmd);
	void set_command(std::string cmd);
	void print_command_history();
	int checkExit();
	std::list<std::string> get_command();

	std::string cmd;

	/**
	 * Variaveis de Ambiente
	 */
	std::string MYPS1;


};
#endif //TRABALHO_1_SHELL_H
