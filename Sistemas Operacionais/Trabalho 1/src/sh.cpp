//
// Created by Joao Victor Zarate on 09/05/2021.
//

#include "include/sh.h"

static void end_handler(int signal) {
    // printf("MyShell$ ");
}

int main (int argc, char *argv[])
{
    char cmd[100];

    if ((signal(SIGINT, end_handler) == SIG_ERR)) {
        printf("Error while setting a signal handler\n");
        exit(EXIT_FAILURE);
    }   

    while (1)
    {
        printf("\nMyShell$ ");
        fgets(cmd, 100, stdin);

        if (strncmp(cmd, "exit", 4) == 0 || strncmp(cmd, "^D", 2) == 0) { //FIXME
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