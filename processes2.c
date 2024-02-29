#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid1;
	pid_t child_pid2;
	pid_t child_pid3;
	pid_t child_pid4;
	pid_t child_pid5;
	int status1;
	int status2;
	int status3;
	int status4;
	int status5;
	
	child_pid1 = fork();                                    		//parent process will create a process1   	
	if (child_pid1 == 0) {						
		printf("process1:\n");
		printf("pid = %d\n", getpid());
		printf("ppid = %d\n", getppid());
		child_pid3 = fork();						//process1 will create a process3
		if (child_pid3 == 0){
			printf("process3:\n");
			printf("pid = %d\n", getpid());
			printf("ppid = %d\n", getppid());
			exit(5);
		}
		else {
			child_pid4 = fork();					//process1 will create a process4
			if (child_pid4 == 0){
				printf("process4:\n");
				printf("pid = %d\n", getpid());
				printf("ppid = %d\n", getppid());
				exit(5);
			}
			else {
				wait(&status4);
			}
			wait(&status3);
		}
		exit(5);
	} 
	else {													
		printf("main process:\n");
		printf("pid = %d\n", getpid());
		printf("ppid = %d\n", getppid());
		child_pid2 = fork();						//parent process will create a process2
		if (child_pid2 == 0) {
			printf("process2:\n");
			printf("pid = %d\n", getpid());
			printf("ppid = %d\n", getppid());
			child_pid5 = fork();					//process2 will create a process5
			if (child_pid5 == 0) {					
				printf("process5:\n");
				printf("pid = %d\n", getpid());
				printf("ppid = %d\n", getppid());
				exit(5);
			}
			else {
				wait(&status5);
			}
			exit(5);
		}
		else {
			wait(&status2);
		}	
		wait(&status1);
	}
	
	return 0;
}	
