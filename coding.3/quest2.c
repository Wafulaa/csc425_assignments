#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int fd = open("q2.c", O_RDONLY);
    if(fd == -1 ){
        printf("Unable to open the file\n exiting....\n");// open thr file
        return 0;
    }
    
    int rc = fork();
    if (rc < 0)// fork fails when r equals zero
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)// child process when r equal 0
    {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
        char myChar;// the character
        read(fd, &myChar,1);
        printf("character from the child file\n%c\n", myChar);// prints the character
    }
    else//the parent process
    {
        wait(NULL);// parent process waits for the child process
        printf("hello, I am parent of %d (pid:%d)\n",
               r, (int)getpid());
        char myChar;
        read(fd, &myChar,1);
        printf("character from the parent file\n%c\n", myChar);
    }
    return 0;
}
/*********************************************
Your name:Anthony W Wafula
Question 1: yes the can both write
Question 2: the output will apper randomly
*********************************************/

