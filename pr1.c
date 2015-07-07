#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int fd[2];
	pipe(fd);
	printf("Parrent PID: %d\n",getpid());

	int i;
	int j;
	char ab[4];	

	pid = fork();
	
	switch(pid){

	case -1:
		printf("Error\n");
		return -1;

	case 0:
		printf("Child AF PID: %d\n",getpid());	
		
		close(fd[1]);

		i = read(fd[0],ab, 4);
		printf("(read) i=%d\n",i);
		printf("Res=%s\n",ab);
		return 0;

	default:
		
		printf("Parrent AF PID: %d\n", getpid());
		close(fd[0]);

	
		j = write(fd[1],"abc",4);
		printf("(write) j=%d\n",j);
		
		//printf("Parent cnt=%d\n", j);		
	}

return 0;
}
