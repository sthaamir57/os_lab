#include <stdio.h>
#include <stdlib.h>
#define M 100
#define MIN 1000
int main() {
    int req[M], i, n, mov = 0, cp, count = 0;
    printf("Enter no. of requests : ");
    scanf("%d", &n);
    printf("Enter requests in sequence : ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("Enter current position : ");
    scanf("%d", &cp);
    printf("\nSequence is : \n");
    printf("%d", cp);
    while (count != n) {
        int min = MIN, d, index;
        for (i = 0; i < n; i++) {
            d = abs(req[i] - cp);
            if (min > d) {
                min = d;
                index = i;
            }
        }
        mov = mov + min;
        cp = req[index];
        printf(" -> %d", cp);
        req[index] = MIN;
        count++;
    }
    printf("\n\nTotal number of seek operations = %d\n", mov);
    return 0;
}