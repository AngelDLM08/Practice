#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int fd[2];
	pipe(fd);
	printf("Parrent PID: %d, okda?\n",getpid());

	int i;
	int j;
	char wtp[11];
	char rfp[11];
	int stat;
	int exr;

	pid = fork();
	
	switch(pid){

	case -1:
		printf("Error\n");
		return -1;

	case 0:
//=========================
// Child process after running 1-st part of Parrent;
		printf("Child AF PID: %d\n",getpid());	
		close(fd[0]);
//---------------------------		

		exr= execl("/bin/ls","ls","-l","/tmp/",NULL);


//		scanf("%s",wtp);
//		i=write(fd[1],wtp,11);
		return 0;

//======================================
	default:
// Parrent after fork()
		printf("Parrent AF PID: %d\n", getpid());
		close(fd[1]);
		wait(&stat);
//---------------------------
// Parrent after running Child





//		j=read(fd[0],rfp,11);
//		printf("your scrap: %s\n",rfp);

//=======================================
	}

return 0;
}
