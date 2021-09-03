#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();//fork
    if (rc < 0)// fails when zero and exits
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)//child process
    {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        sleep(1);
        int wc = wait(NULL);
        printf("child wait programs value is %d\n", wc);
    }
    else// parent process
    {
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
               rc, wc, (int)getpid());
    }
    return 0;
}
/*********************************************
Your name:Anthony W Wafula
Question 1: return s childs PID when used in the parent
Question 2: returns -1 when used in th child and fork fails 
*********************************************/

