#include<bits/stdc++.h>
#define MAX 20
using namespace std;

int board[MAX][MAX];

bool isSafe(int row,int col,int n)
{
	int i,j;
	//check for upper in that column
	for(i=row;i>=0;i--)
	{
		if(board[i][col])
			return false;
	}

	//check for left diagonal
	for(i=row,j=col;i>=0 and j>=0;i--,j--)
	{
		if(board[i][j])	
			return false;
	}
	//check for right diagonal
	for(i=row,j=col;i>=0 and j<n;i--,j++)
	{
			if(board[i][j])	
				return false;
	}

	return true;
}

//Printing the combination
void printsol(int n)
{
	cout<<"[";
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(board[i][j])
				cout<<j+1<<" ";
		}
	}
	cout<<"] ";
}

//Checking the possible option 
bool solveUtil(int n,int row)
{
	if(row==n)
	{
		printsol(n);
		//cout<<"row==n\n";
		return true;
	}
	bool res = false;
	for(int i=0;i<n;i++)
	{
		if(isSafe(row,i,n))
		{	
			board[row][i]=1;
			res = solveUtil(n,row+1)||res;

			board[row][i]=0; // Backtracking
		}
	}
	return res;
}

void solNQueen(int n)
{
	memset(board,0,sizeof(board));
	if(!solveUtil(n,0))
		cout<<-1;
	
}

int main()
{
	int t;	cin>>t;
	while(t--)
	{
	    //Input for Chessboard Size
		int n;	cin>>n;
		solNQueen(n);
		cout<<endl;
	}
}
