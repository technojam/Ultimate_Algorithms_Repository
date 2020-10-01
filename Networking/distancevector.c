#include<stdio.h>
int main()
{
	int a[20][20];
	int i,j,n,c,e=0,d;
	printf("Enter the number of nodes \n");
	scanf("%d",&n);
	printf("Enter the elements in the form of matrix ! \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("You have entered the following :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	while(e==0)
	{
		e=1;
		for(d=1;d<n;d++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if((d!=1)&&(i!=j)&&(a[d][j]!=0)&&(a[d][j]!=-1)&&(a[i][d]!=-1))
					{
						c=a[i][d]+a[d][j];
						if(a[i][j]==-1||c<a[i][j])
						{
							a[i][j]=c;
							a[j][i]=c;
							e=0;
						}
					}
				}
			}
		}


	}
	printf("The updated matrix is :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}


}