//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[])
{
    int fd1[2]; // Used to store two ends of first pipe
    //[0] is the reading end
    //[1] is the writing end
    if (pipe(fd1) == -1)
    {
        fprintf(stderr, "Pipe Failed");
        return 1;
    } 
    int rc1 = fork();
    if (rc1 < 0)
    {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc1 == 0)//first child
    {

        dup2(fd1[1], 1); // redirects the stdout
 
        printf("Hello this is a message from first child\n");
    }
    else
    {
        int rc2 = fork();
        if (rc2 < 0)//forks fails and exits
        {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } else if (rc2 == 0)// second child
        {
            dup2(fd1[0], STDIN_FILENO); //setting the input of second child to output of first)
            sleep(1);
            char message[100];
  
          //scanf("%s",message);
            gets(message);
            printf("The message from the first child is \"%s\"\n", message);
        }
        else// parent
        {
            //sleep(1);
            wait(NULL);
        }
    }
    return 0;
}
/*********************************************
Your name:Anthony W Wafula
Question 1: no question
Question 2: no question
*********************************************/

