#include<stdio.h>
void main()
{
    int array[100][100];
    int e,n;
    printf("Enter no of nodes and edges: ");
    scanf("%d%d",&n,&e);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
          array[i][j]=0;
        }
    }
    int a,b;
    for(int i=0;i<e;i++)
    {
        printf("enter two points of edges: ");
        scanf("%d%d",&a,&b);
        array[a][b]=array[b][a]=1;

    }
    printf("enter the two nodes you want to check: ");
    scanf("%d%d",&a,&b);

    if(array[a][b]||array[b][a])
        printf("yes\n");
    else
        printf("no\n");
    return;
}