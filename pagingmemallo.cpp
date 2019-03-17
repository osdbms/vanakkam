#include<stdio.h>
void main()
{
int
memsize,phmem,frame,fno,f[frame],pagesize,nofpage,base,p[100],pr[100],pageno,offset;
int logadd,phyadd,i;
int choice=0;
printf("PAGING MEMORY ALLOCATION-----");
printf("\nEnter the physical memory size: ");
scanf("\n%d",&phmem);
printf("\nEnter the logical memory size: ");
scanf("\n%d",&memsize);
printf("\nEnter page size:");
scanf("%d",&pagesize);
frame=phmem/pagesize;
printf("\nNumber of frames: %d",frame);
nofpage=memsize/pagesize;
printf("\nNumber of pages: %d",nofpage);
for(i=0;i<nofpage;i++)
{
p[i]=-1;
pr[i]=-1;
}
for(i=0;i<frame;i++){
f[i]=-1;
}
for(i=0;i<nofpage;i++) {
printf("
\nEnter the frame of page%d:",i+1);
scanf("%d",&fno);
f[fno]=i;
if(pr[i]==
-1){
p[i]=fno;
if(fno<frame)
pr[i]=1;
}
}
printf("
\nPAGE TABLE
\n");
printf("Pageno. Frameno. PresenceBit
\n
\n");
for(i=0;i<nofpage;i++){
printf("%d
\t
\t%d
\
t
\t%d
\n",i,p[i],pr[i]);
}
printf("
\n
\tFRAME TABLE
\n");
printf("Frameno. Pageno.
\n");
for(i=0;i<frame;i++){
printf("%d
\t
\t%d
\n",i,f[i]);
}
do{
printf("
\nEnter a logical address:");
scanf("%d",&logadd);
printf("
\nEnter a Base address:");
scanf("%d",&base);
pageno=logadd/pagesize;
offset=logadd%pagesize;
if(pr[pageno]==1){
phyadd=base+(p[pageno]*pagesize)+offset;
printf("
\nPage no is:%d",pageno);
printf(
"
\nOffset is:%d",offset);
printf("
\nPhysical address is:%d",phyadd);
}else {
printf("
\nIvalid page reference !!!");
}
printf("
\nDo you want to continue(1/0)?:");
scanf("%d",&choice);
}while(choice==1);
}
