#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)//exit when for fails
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (r == 0)//the child process
    {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        char *myargs[3];
        myargs[0] = strdup("ls");         //"ls"
        myargs[1] = strdup("-a");
        myargs[2] = NULL;                 //end of the array
        char *const envp[2] = {"", NULL}; // here you can se


        execle("/usr/bin/ls", "-a", NULL, envp);
        printf("this shouldn't print out");
    }
    else//parents process
    {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
               rc, wc, (int)getpid());
    }
    return 0;
}
/*********************************************
Your name:Anthony W Wafula
Question 1:
Question 2:
*********************************************/

