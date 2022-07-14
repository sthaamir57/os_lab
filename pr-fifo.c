#include<stdio.h>

#define DEF 9999
int n, frames;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pageFaultCount = 0;

void getData() {
    printf("\nEnter the number of pages:");
    scanf("%d", & n);
    printf("\nEnter reference string values:");
    for (i = 0; i < n; i++)
        scanf("%d", & in[i]);
    printf("\nEnter no. of frames:");
    scanf("%d", & frames);
}

void initialize() {
    pageFaultCount = 0;
    for (i = 0; i < frames; i++)
        p[i] = DEF;
}

int isHit(int data) {
    hit = 0;
    for (j = 0; j < frames; j++) {
        if (p[j] == data) {
            hit = 1;
            break;
        }

    }
    return hit;
}

void displayPages() {
    for (k = 0; k < frames; k++) {
        if (p[k] != DEF)
            printf(" %d ", p[k]);
    }
}

void displayPageFaultCount() {
    printf("\nTotal no of page faults:%d\n", pageFaultCount);
}

void fifo() {
    initialize();
    printf("\n-------------------------\n");
    printf("Ref.str ----- Page Frames");
    printf("\n-------------------------");
    for (i = 0; i < n; i++) {
        printf("\n%d -----", in[i]);

        if (isHit( in[i]) == 0) {
            for (k = 0; k < frames - 1; k++)
                p[k] = p[k + 1];

            p[k] = in[i];
            pageFaultCount++;
            displayPages();
        } else
            printf(" No page fault");
    }
    printf("\n-----------------------\n");
    displayPageFaultCount();
}

int main() {
    getData();
    fifo();
    return 0;
}