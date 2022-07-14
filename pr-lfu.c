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

void lfu()
{
    int usedcnt[100];
    int least,repin,sofarcnt=0,bn;
    initialize();
    printf("\n-------------------------\n");
    printf("Ref.str ----- Page Frames");
    printf("\n-------------------------");
    for(i=0; i<frames; i++)
        usedcnt[i]=0;
 
    for (i = 0; i < n; i++) {
        printf("\n%d -----", in[i]);
 
        if(isHit(in[i]))
        {
            int hitind=getHitIndex(in[i]);
            usedcnt[hitind]++;
            printf(" No page fault!");
        }
        else
        {
            pageFaultCount++;
            if(bn<frames)
            {
                p[bn]=in[i];
                usedcnt[bn]=usedcnt[bn]+1;
                bn++;
            }
            else
            {
                least=DEF;
                for(k=0; k<frames; k++)
                    if(usedcnt[k]<least)
                    {
                        least=usedcnt[k];
                        repin=k;
                    }
                p[repin]=in[i];
                sofarcnt=0;
                for(k=0; k<=i; k++)
                    if(in[i]==in[k])
                        sofarcnt=sofarcnt+1;
                usedcnt[repin]=sofarcnt;
            }
 
            displayPages();
        }
 
    }
    printf("\n-----------------------\n");
    displayPageFaultCount();
}

int main() {
    getData();
    lfu();
    return 0;
}