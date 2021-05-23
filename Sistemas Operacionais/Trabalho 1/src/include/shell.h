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

/********************
 * Local Includes	*
 ********************/
#include "Arquivo.h"

class Shell
{
private:
	void print_command_history(int n);

	std::list<std::string> command_list;
	std::list<char> path_list;

public:
	Shell();
	~Shell();
	void verify_command(std::string cmd);
	static void cmd_handler(int);

	void set_command(std::string cmd);
	std::list<std::string> get_command();

	void print_command_history();
	int checkExit();

	std::string cmd;

	/**
	 * Variaveis de Ambiente
	 */
	std::string MYPS1;


};
#endif //TRABALHO_1_SHELL_H
