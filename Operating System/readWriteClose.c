#include<stdio.h>
#include<fcntl.h>
main()
{
int fd;
char buf[]="Hello";
char buf1[20];
fd=open("A.txt",O_WRONLY);
if(fd==-1)
{
printf("file not open");
}
write(fd,buf,sizeof(buf));
close(fd);
fd=open("A.txt",O_RDONLY);
read(fd,buf1,sizeof(buf1));
printf("%s\n",buf1);
close(fd);
}
