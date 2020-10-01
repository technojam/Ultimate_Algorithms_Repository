#include<stdio.h>
#include<dirent.h>
int main()
{
    char dirname[20];
    DIR *p;
    struct dirent *d;
    printf("Enter Directory Name\n");
    scanf("%s",dirname);
    p=oprndir(dirname);
    if(p==NULL)
    {
        perror("cannot find DIR");
        exit(-1);
    }
    while(d=readdir(p))
    {
        printf("%s\n",d->d_name);
        return 0;
    }
}