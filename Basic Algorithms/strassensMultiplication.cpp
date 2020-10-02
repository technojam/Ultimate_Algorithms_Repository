#include<bits/stdc++.h>

using namespace std;

int ** allocate(int m)
{
	int **arr=new int*[m];
	for (int i = 0; i < m; ++i)
	{
		arr[i]=new int[m];
	}
	return arr;

	
}
int **add(int** a,int** b,int n)
{
	int **arr=allocate(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[i][j]=a[i][j]+b[i][j];
		}
	}
   
	return arr;
}
int **sub(int** a,int** b,int n)
{
	int **arr=allocate(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[i][j]=a[i][j]-b[i][j];
		}
	}
   
	return arr;
}
int **strassen(int **A,int **B,int n)
{
   int ** C=allocate(n);
    if(n==1)
    {
      	C[0][0]=A[0][0]*B[0][0];

    }
    
    else{
    	int row=n/2;
        int** a11=allocate(row);
        int** a12=allocate(row);
        int** a21=allocate(row);
        int** a22=allocate(row);
        int** b11=allocate(row);
        int** b21=allocate(row);
        int** b12=allocate(row); 
        int** b22=allocate(row); 
      
       

        for(int i=0;i<row;i++)
        {
        	for (int j = 0; j< row; ++j)
        	{
        		a11[i][j]=A[i][j];
        		a12[i][j]=A[i][j+row];
        		a21[i][j]=A[i+row][j];
        		a22[i][j]=A[i+row][j+row];
        		b11[i][j]=B[i][j];
        		b12[i][j]=B[i][j+row];
        		b21[i][j]=B[i+row][j];
        		b22[i][j]=B[i+row][j+row];

        	}
        }

        int **p1=strassen(add(a11,a22,row),add(b11,b22,row),row);
        int **p2=strassen(add(a21,a22,row),b11,row);
        int **p3=strassen(a11,sub(b12,b22,row),row);
        int **p4=strassen(a22,sub(b21,b11,row),row);
        int **p5=strassen(add(a11,a12,row),b22,row);
        int **p6=strassen(sub(a21,a11,row),add(b11,b12,row),row);
        int **p7=strassen(sub(a12,a22,row),add(b21,b22,row),row);

        int **c11=add(sub(add(p1,p4,row),p5,row),p7,row);
        int **c12=add(p3,p5,row);
        int **c21=add(p2,p4,row);
        int **c22=add(sub(add(p1,p3,row),p2,row),p6,row);

        for (int i = 0; i < row; ++i)
        {
        	for (int j = 0; j < row; ++j)
        	{
        		C[i][j]=c11[i][j];
        		C[i][row+j]=c12[i][j];
        		C[i+row][j]=c21[i][j];
        		C[i+row][j+row]=c22[j][j];
        		
        	}
        	
        } 
    }
    return C;
}

int main()
{
	int m,n,k;
	
	cout<<"Enter value of k: ";
	cin>>k;
    m=pow(2,k);
	int **a=allocate(m);
	int **b=allocate(m);

    cout<<"Enter elements in Matrix A : ";
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
            cin>>a[i][j];
		}
	}

	cout<<"Enter elements in Matrix B : ";
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
            cin>>b[i][j];
	    }
	}
    cout<<"A :- \n";
    for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<" "<<a[i][j]  ;
		}

		cout<<"\n";
	}

    cout<<"B :-\n";
    for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<" "<<b[i][j] ;
		}

		cout<<"\n";
	}

	int** c=strassen(a,b,m);
    

    cout<<"RESULT (AB) :-\n";
    for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<" "<<c[i][j] ;
		}

		cout<<"\n";
	}

}
