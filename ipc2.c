#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int turn = 1;
void * thread1f(void * arg) {
  int a = 0;
  while (a++ < 20) {
    while (turn != 1);
    fputc('b', stderr);
    turn = 0;
  }
}
void * thread2f(void * arg) {
  int b = 0;
  while (b++ < 20) {
    while (turn != 0);
    fputc('a', stderr);
    turn = 1;
  }
}

int main() {
  pthread_t thid1;
  pthread_t thid2;
  pthread_create( & thid1, NULL, & thread1f, NULL);
  pthread_create( & thid2, NULL, & thread2f, NULL);
  pthread_join(thid1, NULL);
  pthread_join(thid2, NULL);
  return 0;
}