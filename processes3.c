#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_CMD_LEN 256
#define MAX_ARGS 64

int main()
{
	char cmd[MAX_CMD_LEN] = { 0 };
	char *args[MAX_ARGS];
	int args_counter = 0;
	pid_t child_pid;
	int status;
	
	while (1){
	printf("command: ");
	fgets(cmd, sizeof(cmd), stdin);
	cmd[strcspn(cmd, "\n")] = 0;				//removing last symbol in entering string
	char *token = strtok(cmd, " \n");			//separate arguments
	
	while (token != NULL){					//every argument have a position in array
		args[args_counter++] = token;
		token = strtok(NULL, " \n");
	}
	
	args[args_counter] = NULL;				//last element in array must be NULL
	
	if (strcmp(args[0], "exit") == 0){			//if user enter "exit" then program is end
		break;
	}
	
	child_pid = fork();					//child process is called
	if (child_pid == 0){					//child process call execvp 
		execvp(args[0], args);
		exit(1);
	} else if (child_pid > 0){				
		wait(&status);
	} else {
		fprintf (stderr, "fork failed\n");
		exit(1);
	}
	}
	
	return 0;
}

