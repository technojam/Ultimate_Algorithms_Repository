#include<stdio.h>
#include<dirent.h>
main()
{
DIR *d;
struct dirent *dir;
d=opendir(".");
if(d)
{
while(dir=readdir(d)!=NULL)
{
printf("%s",dir->d_name);
}
closedir(d);
}
}