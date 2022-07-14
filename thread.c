//gcc thread.c -o thread -lpthread

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NO_OF_THREADS 5
void *print_hello_world(void *tid)
{
printf(" thread count= %d\n\n", *((int *)tid));
pthread_exit(NULL);
}
int main()
{
pthread_t threads[NO_OF_THREADS];
int status, i;
for (i = 1; i <= NO_OF_THREADS; i++)
{
printf("Creating thread %d\n", i);
pthread_create(&threads[i], NULL, &print_hello_world, &i);
pthread_join(threads[i], NULL);
}
return 0;
}