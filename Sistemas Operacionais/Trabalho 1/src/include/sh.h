//
// Created by Joao Victor Zarate on 09/05/2021.
//

#ifndef TRABALHO_1_SH_H
#define TRABALHO_1_SH_H

#include <list>
#define KILL SIGKILL

class sh
{
private:
	void print_command_history(int n);
	void print_command_history();
	int exit ();

	std::list<char> command_list;
	std::list<char> path_list;


};
#endif //TRABALHO_1_SH_H
