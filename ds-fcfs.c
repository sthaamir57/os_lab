#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int i,n,req[50],mov=0,cp;
    printf("Enter no. of requests : ");
    scanf("%d",&n);
    printf("Enter requests in sequence : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter current position : ");
    scanf("%d",&cp);
    mov=mov+abs(cp-req[0]);
    printf("\nSequence is : \n");
    printf("%d -> %d",cp,req[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(req[i]-req[i-1]);
        printf(" -> %d",req[i]);
    }
    printf("\n\nTotal number of seek operations = %d\n",mov);
    return 0;
}