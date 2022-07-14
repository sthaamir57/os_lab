#include<stdio.h>
#include<unistd.h>

int main() {
    int pid, i;
    pid = fork();
    if (pid == 0) {
        for (;;) printf("C");
    } else {
        for (;;) printf("P");
    }
}