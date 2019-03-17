#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
int f1,f2,c;
char buf[1024];
f1=open(argv[1],O_RDONLY);
f2=open(argv[2],O_WRONLY|O_CREAT,S_IRWXU|S_IRGRP| S_IROTH);
while((c=read(f1,buf,1024))>0)
write(f2,buf,c);
close(f1);
close(f2);
return 0;
} 
