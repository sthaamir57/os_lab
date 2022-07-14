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

void lru()
{
    initialize();
    printf("\n-------------------------\n");
    printf("Ref.str ----- Page Frames");
    printf("\n-------------------------");

    int least[50];
    for(i=0; i<n; i++)
    {
        printf("\n%d -----", in[i]);
 
        if(isHit(in[i])==0)
        {
 
            for(j=0; j<frames; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i-1; k>=0; k--)
                {
                    if(pg==in[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repIndex;
            for(j=0; j<frames; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repIndex=j;
                }
            }
            p[repIndex]=in[i];
            pageFaultCount++;
 
            displayPages();
        }
        else
            printf(" No page fault!");
    }
    printf("\n-----------------------\n");
    displayPageFaultCount();
}

int main() {
    getData();
    lru();
    return 0;
}