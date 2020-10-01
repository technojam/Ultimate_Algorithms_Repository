#include<stdio.h>
#include<string.h>
void rem(char[],char[],int);
int main()
{
	char data[20],temp[20],trans[20],r[20],key[20];
	int n,m,i,j,k,x,u,g,f,t;
	printf("Enter the data :     ");
	scanf("%s",data);
	printf("Enter the CRC Key :  ");
	scanf("%s",key);
	n=strlen(data);
	m=strlen(key);
	strcpy(temp,data);
	strcpy(trans,data);
	for(i=0;i<(m-1);i++)
	{
		temp[n+i]='0';
	}
	printf("\nEntered data : %s",data );
	printf("\nModified data : %s",temp );
	printf("\nCRC Key: %s\n",key);
	x=m;
	u=m-1;
	while(x<(m+m))
	{
		printf("hi\n");
		for(i=0;i<u;i++)
		{

			if(temp[i]==key[i])
			{
				temp[i]='0';
			}
			else
			{
				temp[i]='1';
			}
		}
		    j=0;

			while(temp[j]=='0')
			{
				for(k=0;k<(m+n)-1;k++)
				{
					temp[k]=temp[k+1];
					
				}
				x++;
			}
	}
	printf("Remainder %s\n",temp);
	f=strlen(temp);
	if(f!=u)
	{
		g=u-f;
		strcpy(r,temp);
		for(i=1;i<=g;i++)
		{
			strcat(trans,"0");
		}
		strcat(trans,temp);
		strcpy(temp,trans);
	}
	printf("Transmitted data : %s",temp);

	return 0;
}