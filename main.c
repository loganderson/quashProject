#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>



int main()
{
    char cmdline[1000];
    char *listOfArgs[100];
    char newString[10][10];
    int i,j,ctr;


    //main loop
    while(1)
    {
        //print quash prompt
        printf("[QUASH]$ ");

        //get user input                 
        fgets(cmdline, 1000, stdin); 
        
        // if (strlen(cmdline) == 0)
        // {
        //     printf("\nempty line\n");
        //     continue;
        // }

        //parse user input and put into array called listOfArgs
        j=0; ctr=0;
        for(i = 0; i<=(strlen(cmdline));i++)
        {
            if (cmdline[i] == ' '|| cmdline[i] == '\0')
            {
                newString[ctr][j] = '\0';
                ctr++;
                j=0;
            }
            else if (cmdline[i] == '\n')
            {
                //do nothing
            }
            else
            {
                newString[ctr][j] = cmdline[i];
                j++;
            }
        }
        for (i = 0; i<ctr; i++)
        {
            listOfArgs[i] = newString[i];
        }

        //execute if built in instruction
        if (strcmp(listOfArgs[0], "echo") == 0)
        {
            i = 1;
            while (listOfArgs[i] != NULL)
            {
                
            }
        }
        else if (strcmp(listOfArgs[0], "export") == 0)
        {

        }
        else if (strcmp(listOfArgs[0], "cd") == 0)
        {
            printf (listOfArgs[1]);
            chdir(listOfArgs[1]);
        }
        else if (strcmp(listOfArgs[0], "pwd") == 0)
        {
            char cwd[1000];
            if (getcwd(cwd, sizeof(cwd)) != NULL)
            {
                printf(cwd);
            }
            printf("\n");
        }
        else if (strcmp(listOfArgs[0], "quit") == 0)
        {
            exit(0);
        }
        else if (strcmp(listOfArgs[0], "exit") == 0)
        {
            exit(0);
        }
        else if (strcmp(listOfArgs[0], "jobs") == 0)
        {

        }
        else if (strcmp(listOfArgs[0], "kill") == 0)
        {

        }
        else //other commands/processes
        {

        }
    }
    return 0;
}