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
	int x;
	srand(time(0));
	x = r();
	printf("%d",x);
	return 0;
}