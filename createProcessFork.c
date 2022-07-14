#include <stdio.h>
#include <unistd.h>

int main() {
    int p1, p2, p3;
    printf("\n Parent's pid=%d\n", getpid());
    p1 = fork();
    if (p1 == 0) {
        printf("\n Child 1's pid=%d\n", getpid());
        printf("\n Child 1's parent's pid=%d\n", getppid());
        p2 = fork();
        if (p2 == 0) {
            printf("\n Child 2's pid=%d\n", getpid());
            printf("\n Child 2's parent's pid=%d\n", getppid());
            p3 = fork();
            if (p3 == 0) {
                printf("\n Child 3's pid=%d\n", getpid());
                printf("\n Child 3's parent's pid=%d\n", getppid());
            }
        }
    }
    return 0;
}