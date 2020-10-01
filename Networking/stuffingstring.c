#include<stdio.h>
#include<string.h>
int main()
{
	char a[50];
	int n,i,j,count=0;
	printf("Enter the packet : ");
	scanf("%s",a);
	printf("\nEntred packet : %s",a);
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		if(a[i]=='1')
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
			for(j=n;j>i;j--)
			{
				a[j+1]=a[j];
				n++;
			}
			a[i+1]='0';
		}
	}
	printf("\nStuffed data : %s",a);

}