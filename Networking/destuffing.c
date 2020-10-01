#include<stdio.h>
int main()
{
	int bit[100];
	int i,n,j,count=0;
	printf("Enter the size of packet : ");
	scanf("%d",&n);
	printf("\nEnter the packet : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bit[i]);
	}
	printf("The packet before de-stuffing :");
	for(i=0;i<n;i++)
	{
		printf("%d",bit[i]);
	}
	for(i=0;i<n;i++)
	{
		if(bit[i]==1)
		{
			count++;
		}
		else
		{
			count=0;
		}
		if(count==5)
		{
			count=0;
			for(j=i+1;j<n;j++)
			{
				bit[j]=bit[j+1];
			}
			n--;
			
		}
		

	}
	printf("\nThe packet after de-stuffing :");
	for(i=0;i<n;i++)
	{
		printf("%d",bit[i]);
	}
	printf("\n");
}