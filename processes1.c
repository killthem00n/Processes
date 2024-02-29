#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid;
	int status;
	
	child_pid = fork(); 				//create new process
	if (child_pid == 0) {				//if it child process do this
		printf("Child process:\n");
		printf("pid = %d\n", getpid());
		printf("ppid = %d\n", getppid());
		exit(11);
	} 						//if it parent process do this
	else {
		printf("Parent process:\n");
		printf("pid = %d\n", getpid());
		printf("ppid = %d\n", getppid());
		wait(&status);
		
	}
	
	return 0;
}
