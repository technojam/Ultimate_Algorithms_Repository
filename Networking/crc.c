#include<stdio.h>
#include<string.h>
int main()
{
	char a[20],r[20],t[20],k[20];
	int n,m,i,j,l,c,u,x,y,z;
	printf("Enter the packet :");
	scanf("%s",a);
	printf("Enter the CRC key : ");
	scanf("%s",k);
	strcpy(t,a);
	n=strlen(t);
	m=strlen(k);
	for (i=n;i<((m+n)-1);i++) 
	{
		t[i]='0';
		printf("%c\n",t[i]);

	}
	t[i]='\0';
	printf("Entered data : %s",a);
	printf("\nModified data : %s",t);
	printf("\nCRC Key : %s\n",k);
	x=m;
	u=m-1;
	while(x<(m+n))
	{
		for(i=0;i<m;i++)
		{
			if(t[i]==k[i])
			{
				t[i]='0';
			}
			else
			{
				t[i]='1';
			}
		}
		j=0;
		while(t[j]=='0')
		{
			for(l=0;l<(m+n)-1;l++)
			{
				t[l]=t[l+1];
			}
			x++;
		}

	}
	printf("Remainder %s\n",t);
	y=strlen(t);
	if(y!=u)
	{
	c=u-y;
	strcpy(r,t);
	for(i=1;i<=c;i++)
	{
		strcat(a,"0");
	}
	strcat(a,r);
	}
	else
	{
		strcat(a,t);
	}
	printf("%s\n",a );

}