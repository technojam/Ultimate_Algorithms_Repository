#include <iostream>
using namespace std;
int c=0;
bool isSafe(int board[][10],int i,int j,int n)
{
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    //left diagnol
    int x=i;
    int y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    //right diagnol
     x=i;
     y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solveNqueen(int board[][10],int i,int n)
{
    if(i==n)
    {
        c++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    cout<<"{"<<i+1<<"-"<<j+1<<"}"<<"  ";
                }
                
            }
            
        }
        
        return false;
    }
    for(int j=0;j<n;j++)
    {
        if(isSafe(board,i,j,n))
        {
            board[i][j]=1;
            
            bool nextQueenRakhpaye=solveNqueen(board,i+1,n);
            if(nextQueenRakhpaye)
            {
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;
}
int main(int argc, char **argv)
{
	int n;
    cin>>n;
    int board[10][10]={0};
    solveNqueen(board,0,n);
    cout<<endl;
    cout<<c;
	return 0;
}
