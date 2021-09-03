#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> 
 

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    pid_t rc = fork();// fork
    int status;
    if (rc < 0)// fork fails whge under zero
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)// child process
    {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        sleep(1);
    }
    else
    {
         pid_t wc = waitpid(rc, &status, WUNTRACED);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
               rc, wc, (int)getpid());
    }
    return 0;
}
/*********************************************
Your name:anthony W wafula
Question 1: control on what process to wait for
Question 2: no questiin  2
*********************************************/

