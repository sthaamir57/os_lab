#include <stdio.h>
#include <stdlib.h>
#define M 100
int main() {
    int req[M], i, j, n, mov = 0, cp, size, dir;
    printf("Enter no. of requests : ");
    scanf("%d", &n);
    printf("Enter requests in sequence : ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("Enter current position : ");
    scanf("%d", &cp);
    printf("Enter total disk size : ");
    scanf("%d", &size);
    printf("Enter movement direction (high 1 and low 0) : ");
    scanf("%d", &dir);
    printf("\nSequence is : \n");
    printf("%d", cp);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                int temp;
                temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }

        }
    }

    int index;
    for (i = 0; i < n; i++) {
        if (cp < req[i]) {
            index = i;
            break;
        }
    }

    // if movement is towards high value
    if (dir == 1) {
        for (i = index; i < n; i++) {
            mov = mov + abs(req[i] - cp);
            cp = req[i];
            printf(" -> %d", cp);
        }

        for (i = index - 1; i >= 0; i--) {
            mov = mov + abs(req[i] - cp);
            cp = req[i];
            printf(" -> %d", cp);
        }
    }
    // if movement is towards low value
    else {
        for (i = index - 1; i >= 0; i--) {
            mov = mov + abs(req[i] - cp);
            cp = req[i];
            printf(" -> %d", cp);
        }

        for (i = index; i < n; i++) {
            mov = mov + abs(req[i] - cp);
            cp = req[i];
            printf(" -> %d", cp);
        }
    }

    printf("\n\nTotal number of seek operations = %d\n", mov);
    return 0;
}