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

int getHitIndex(int data) {
    int hitind;
    for (k = 0; k < frames; k++) {
        if (p[k] == data) {
            hitind = k;
            break;
        }
    }
    return hitind;
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

void secondChance() {
    int usedbit[50];
    int victimptr = 0;
    initialize();
    for (i = 0; i < frames; i++)
        usedbit[i] = 0;

    printf("\n-------------------------\n");
    printf("Ref.str ----- Page Frames");
    printf("\n-------------------------");
    for (i = 0; i < n; i++) {
        printf("\n%d -----", in[i]);
        
        if (isHit( in[i])) {
            printf(" No page fault!");
            int hitindex = getHitIndex( in[i]);
            if (usedbit[hitindex] == 0)
                usedbit[hitindex] = 1;
        } else {
            pageFaultCount++;
            if (usedbit[victimptr] == 1) {
                do {
                    usedbit[victimptr] = 0;
                    victimptr++;
                    if (victimptr == frames)
                        victimptr = 0;
                }
                while (usedbit[victimptr] != 0);
            }
            if (usedbit[victimptr] == 0) {
                p[victimptr] = in[i];
                usedbit[victimptr] = 1;
                victimptr++;
            }
            displayPages();

        }
        if (victimptr == frames)
            victimptr = 0;
    }
    printf("\n-----------------------\n");
    displayPageFaultCount();
}

int main() {
    getData();
    secondChance();
    return 0;
}