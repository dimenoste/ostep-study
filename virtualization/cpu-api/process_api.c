#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 #include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("hello (pid:%d)\n", (int)getpid());
    printf("hello from parent (pid:%d)\n", (int)getppid());
    fflush(stdout);
    
    int rc = fork();
    if (rc < 0)
    {
        fprintf(stderr, "fork failed at %d\n", 1);
        exit(1);
    }
    else if (rc == 0)
    {
        printf("child (pid:%d)\n", (int) getpid());
        char *myargs[3];
        myargs[0] = "wc";
        myargs[1] = "p3";
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this should not print out");
    }
    else
    {
        int rc_wait = wait(NULL);
        printf("parent of %d (rc_wait:%d) (pid:%d)\n",
        rc, rc_wait, (int) getpid());
    }
    return 0;
}