//exec
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("PID of exec1.c=%d\n", getpid());
    sleep(10);
    
    execl("./exec2","",NULL);
    printf("BAck to exec1.c\n");
    while (1){}
    return 0;
}