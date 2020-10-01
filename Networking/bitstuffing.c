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
	printf("The packet before stuffing :");
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
			for(j=n-1;j>i;j--)
			{
				bit[j+1]=bit[j];
			}
			bit[i+1]=0;
			n++;
			
		}
		

	}
	printf("\nThe packet after stuffing :");
	for(i=0;i<n;i++)
	{
		printf("%d",bit[i]);
	}
	printf("\n");
}