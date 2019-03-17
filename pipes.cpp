#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
int n,fd[2];
int pid;int size;
char line[20];
printf("\nIpc using pipes:");
if(pipe(fd)<0)
printf("\nPipe error");
else
if((pid=fork())<0)
printf("\nFork error");
else
if(pid>0){
close(fd[0]);
printf("\nParent is sending the message:");
write(fd[1],"hai",3);
}
else{
close(fd[1]);
printf("\nChild is receiving the message");
n=read(fd[0],line,sizeof(line));
write(1,line,n);
}
return 0;}
