//orphan process
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    if (pid > 0) {
        printf("\nParent's ID P : %d\n", getpid());
    }
    else if (pid == 0) {
        printf("\nBEFORE\n");
        printf("Child's ID: %d\n", getpid());
        printf("Parent -ID: %d\n\n", getppid());
        sleep(10);
        printf("\nAFTER\n");
        printf("\nChild ID: %d\n", getpid());
        printf("Parent -ID: %d\n", getppid());
    }
    else {
        printf("Failed to create child process");
    }
    return 0;
}
