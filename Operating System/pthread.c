#include<pthread.h>
#include<sys/types.h>
#include<stdio.h>
int sum=0;
void *runner(void *param);
main()
{
int pid;
pthread_t tid;
pid = fork();
if(pid==0)
{
pthread_create(&tid,NULL,runner,10);
pthread_join(tid,NULL);
printf("Child Sum = %d ",sum);
}
else
{
wait(NULL);
print("Parent Sum = %d",sum);
}
}
void *runner(void *param)
{
int i;
for(i=1;i<=param;i++)
{
sum=sum+i;
}
}