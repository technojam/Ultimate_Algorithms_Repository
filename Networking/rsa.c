#include<stdio.h>

int prime(int x);

int main()
{
	int n,a;
	printf("Enter the number\n");
	scanf("%d",&n);
	a = prime(n);
	printf("%d",a);
}

int prime(int x)
{
	int i;
	for(i=2;i<x/2;i++)
	{
		if(x%i==0)
		{
			return 0;
			break;
		}
			
	}
	return 1;
}