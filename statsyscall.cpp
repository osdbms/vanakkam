#include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
int main(int argc, char *argv[]){
int i;
struct stat statinfo;
for (i=1; i<argc; i++)
{
if (stat(argv[i], &statinfo)==0)
{
if (S_ISDIR(statinfo.st_mode))
printf("\n%s is a directory", argv[i]);
else
{
if (S_ISREG(statinfo.st_mode))
printf("\n%s is a regular file" , argv[i]);
}
}
else
printf("\n%s is not a file" , argv[i]);
}
return 0;
}

