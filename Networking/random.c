#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[100];
void r(int count)
{
	int i,num,j=0;
	for(i=0;i<count; i++)
	{
		 num = (rand() + 1) % (10);
		 a[j]=num;
		 j++;

	}
}	

int main()
{
	int count,i;
	srand(time(0));
	r(6);
	for(i=0;i<6;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}