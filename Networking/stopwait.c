#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int r()
{
	int i,num;
    num = (rand() + 1) % (10);
    return num;
}	

int main()
{
	int n,x,i,d;
	printf("Enter the number of frame to be transmitted : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the data to be transmitted frame %d : ",i+1);
		scanf("%d",&d);
	    srand(time(0));
	    x = r();
	    if(x<5)
	    {
	    	printf("The data %d has been sucessfully transmitted \n",d );
	    }
	    else
	    {
	    	i--;
	    	continue;
	    }
	}
}