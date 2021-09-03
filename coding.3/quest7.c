#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
 
int
main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {// fork fails and exits when less than 0
        fprintf(stderr, "fork failed\n");
        exit(1);

    } else if (rc == 0) {


    close(STDOUT_FILENO); 
    open("theoutput.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    printf("I am printing from the child\n");

    } else {//parent proces
    int wc = wait(NULL);
    assert(wc >= 0);
    }
    return 0;
}
/*********************************************
Your name:anthony W Wafula
Question 1: the output is lodt if the file is not openned 
Question 2: no question 2
*********************************************/

