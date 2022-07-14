#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
int lock = 0;
void *thread1f(void *arg)
{
int a = 0;
while (a++ < 800)
{
if (lock == 0)
{
lock = 1;
fputc('b', stderr);
lock = 0;
}
else
while (lock != 0);
}
}
void *thread2f(void *arg)
{
int b = 0;
while (b++ < 800)
{
if (lock == 0)
{
lock = 1;
fputc('a', stderr);
lock = 0;
}
else
while(lock!= 0);
}
}
int main()
{
pthread_t thid1;
pthread_t thid2;
pthread_create(&thid1, NULL, &thread1f, NULL);
pthread_create(&thid2, NULL, &thread2f, NULL);
pthread_join(thid1, NULL);
pthread_join(thid2, NULL);
printf("\n");
return 0;

}