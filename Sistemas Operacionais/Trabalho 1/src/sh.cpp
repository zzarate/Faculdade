//
// Created by Joao Victor Zarate on 09/05/2021.
//

#include "include/sh.h"

int main (int argc, char *argv[])
{
    char cmd[100];

    while (1)
    {
        printf("\nMyShell$ ");
        fgets(cmd, 100, stdin);

        if (strncmp(cmd, "exit", 4) == 0 || strncmp(cmd, "$", 1) == 0) { //FIXME
            exit(0);
        }
    }
    
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