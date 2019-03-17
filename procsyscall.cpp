#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
 int pid;
 pid = fork();
 if (pid == 0){
 printf("child --> pid = %d and ppid = %d\n",
 getpid(), getppid());
 }
 else{
 printf("parent --> pid = %d\n", getpid());
 }
 return 0;
} 
