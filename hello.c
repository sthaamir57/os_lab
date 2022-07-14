// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>


// int ps(){
//     int val = system("ps -el");
//     return val;
// }

// int main(){
//     for(int i=0; i<=0;i++ ){
//         ps();
//         sleep(10);
//     }
// }

#include<stdio.h>
#include<unistd.h>
int main()
{

  printf("Process ID: %d\n", getpid() );
  printf("Parent Process ID: %d\n", getppid() );

  return 0;
}