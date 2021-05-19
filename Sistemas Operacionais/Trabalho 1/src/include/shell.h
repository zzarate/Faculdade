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
	void print_command_history();
	int exit ();

	std::list<char> command_list;
	std::list<char> path_list;

public:
	Shell();
	~Shell();
	int checkExit();
	static void cmd_handler(int);

	/**
	 * Variaveis de Ambiente
	 */
	std::string MYPS1;

};
#endif //TRABALHO_1_SHELL_H
