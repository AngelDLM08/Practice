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

	pid = fork();
	
	switch(pid){

	case -1:
		printf("Error\n");
		return -1;

	case 0:
		printf("Child AF PID: %d\n",getpid());	
		close(fd[0]);
		
		printf("vvedite 10 simvolov\n");
		scanf("%s",wtp);
		i=write(fd[1],wtp,11);

//		i = read(fd[0],ab, 4);
//		printf("(read) i=%d\n",i);
//		printf("Res=%s\n",ab);
		return 0;

	default:
		
		printf("Parrent AF PID: %d\n", getpid());
		close(fd[1]);
		
		wait(&stat);

		j=read(fd[0],rfp,11);
		printf("your scrap: %s\n",rfp);

		//j = write(fd[1],"abc",4);
		//printf("(write) j=%d\n",j);
		//printf("Parent cnt=%d\n", j);		
	}

return 0;
}
