#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

void	q1(void)
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
	printf("x is %d from process (pid: %d)\n", x, (int)getpid());
	printf("y is %d from process (pid: %d)\n", y, (int)getpid());
	printf("rc process (RC pid: %d)\n", rc);
}

void	q2(void)
{
	int		fd;
	int		rc;
	char	*mystr;

	mystr = "0123456789";
	fd = open("./error.txt", O_RDWR | O_CREAT);
	if (fd == -1)
	{
		fprintf(stderr, "opening of file failed\n");
		return ;
	}
	rc = fork();
	printf("pid of main process is %d\n", getpid());
	printf("pid of child process is %d\n", rc);
	// if (rc < 0)
	// {
	// 	fprintf(stderr, "fork failed\n");
	// 	return ;
	// }
	write(fd, mystr, 10);
	fsync(fd);
}

int	main(void)
{
	q1();
}
