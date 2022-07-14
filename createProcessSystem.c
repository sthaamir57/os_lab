#include<stdio.h>

int main() {
    printf("\nmkdir - 'newDIR created'\n");
    system("mkdir newDIR");
    printf("\ntouch - 'newFILE.txt created'\n");
    system("touch newFILE.txt");
    printf("\nls - 'files and directories listed'\n");
    system("ls");
    return 0;
}