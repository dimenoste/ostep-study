#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int	q1(void)
{
	int rc, x, y;
	x = 100;
	y = 2;
	rc = fork();
	if (rc < 0)
	{
		fprintf(stderr, "error produce, fork failed\n");
	}
	else if (rc == 0) // child process
	{
		x = 50;
	}
	else
	{
		x = 150;
	}
	x += 10;
	y = 3;
	printf("x is %d from preccess (pid: %d)\n", x, (int)getpid());
	printf("y is %d from preccess (pid: %d)\n", y, (int)getpid());
}

int	q2(void)
{
}

int	main(void)
{
	q1();
}