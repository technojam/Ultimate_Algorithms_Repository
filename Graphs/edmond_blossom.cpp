#include<bits/stdc++.h>
using namespace std;
#define loop1(size) for(int i=0;i<size;i++)
#define M 10
#define N 10
int match[N];
int fun1(int adj_mat[][N],int size1,int size2,int u,int seen[])
{
		for(int v=0;v<size2;v++)	//looping through all jobs
		{
			if(adj_mat[u][v]==1 && seen[v]==0)
			{
				seen[v]=1;
				if(match[v]<0 || fun1(adj_mat,size1,size2,match[v],seen)==1)
				{
					match[v]=u;		// candidate u assigned to job v
					return 1;
				}
			}
		}
		return 0;	// no more matching can be found
}
int max_bpm(int adj_mat[][N],int size1,int size2)
{
		int seen[N],res=0;
		loop1(size1)
		{
			match[i]=-1;
		}
		for(int u=0;u<size1;u++)
		{
			for(int k=0;k<size2;k++)
				seen[k]=0;
			if(fun1(adj_mat,size1,size2,u,seen))	// to check if applicant u can be given a job
			{
				res+=1;
			}
		}
		return res;
}
int main()
{
		int size1,size2,t,y;
		cout<<"ENTER THE NUMBER OF APPLICANTS :";
		cin>>size1;
		cout<<"ENTER THE NUMBER OF JOBS :";
		cin>>size2;
		int adj_mat[M][N];
		for(int i=0;i<size1;i++)
		{
			for(int j=0;j<size2;j++)
				adj_mat[i][j]=0;
		}
		loop1(size1)
		{
				cout<<"VERTEX "<<i<<" :\n";
				cout<<"ENTER NUMBER OF EDGES FOR VERTEX "<<i<<" ";
				cin>>t;
				for(int j=0;j<t;j++)
				{
					cout<<"ENTER Y:";
					cin>>y;
					adj_mat[i][y]=1;
				}
		}
		cout<<"ADJ_MATRIX :\n";
		for(int i=0;i<size1;i++)
		{
			for(int j=0;j<size2;j++)
				cout<<adj_mat[i][j]<<"\t";
			cout<<"\n";
		}
		cout<<"\n";
		cout<<"MAXIMUM MATCHING :"<<max_bpm(adj_mat,size1,size2);
		int in;
		cin>>in;
}
