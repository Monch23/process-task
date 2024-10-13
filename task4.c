#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
	pid_t pid = fork();
	int status;

	if (pid > 0) {
		printf("\nParent process is started \n\n");
		wait(&status);
		
		if (WIFEXITED(status)) {
			printf("Parent's First child process is finished with status <%d> \n\n", WEXITSTATUS(status));
		} 
		if (WIFSIGNALED(status)) {
			printf("Parent's first child process is terminated with signal <%d> \n\n", WTERMSIG(status));
		}

		pid_t pid2 = fork();
	
		if (pid2 > 0) {
			wait(&status);
		
			if (WIFEXITED(status)) {
				printf("Parent's Second child process is finished with status <%d> \n\n", WEXITSTATUS(status));
			} 
			if (WIFSIGNALED(status)) {
				printf("Parent's second child process is terminated with signal <%d> \n\n", WTERMSIG(status));
			}	
		} else if (pid2 == 0) {
			printf("Parent's second child process is started \n");
			execl("/Users/picsartacademy/Desktop/processes/reverse", NULL);
		} else {
			printf("fork is failed \n");
			return -1;
		}
	} else if (pid == 0) {
		printf("Parent's first child process is stareted \n");
		execl("/Users/picsartacademy/Desktop/processes/power", NULL);
	} else {
		printf("Fork is failed \n");
		return -1;
	}

	return 0;
}
