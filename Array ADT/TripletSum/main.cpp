#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


void Sort(int *A,int N)
{
    int smallest,pos;
    for(int i=0;i<N-1;i++)
    {
        smallest = A[i];
        pos = i;
        for(int j=i+1;j<N;j++)
        {
            if(A[j]<smallest)
            {
                smallest = A[j];
                pos = j;
            }
        }
        swap(A[pos],A[i]);
    }
}

bool TwoPointerSumFunction(int *A,int N,int i,int x)
{
    int j=N-1;
    while(i<j)
    {
        if(A[i]+A[j]>x)
            j--;
        else if(A[i]+A[j]<x)
            i++;
        else
        {
            cout<<A[i]<<" "<<A[j]<<" "<<-x<<"\n";
            return true;
        }
    }
    return false;
}

void Triplet(int *A,int N)
{
    Sort(A,N);
    bool check = false;
    for(int i=0;i<N-2;i++)
    {
        check = TwoPointerSumFunction(A,N,i+1,-A[i]);
        if(check == true)
        {
            return;
        }
    }
    if(check == false)
        cout<<"Triplets Not Found\n";
}


int main()
{
    int T,N,*A;
    cout<<"Enter the number of test cases\n";
    cin>>T;
    for(int j=0;j<T;j++)
    {
        cout<<"Enter the number of elements in Array for Case "<<j+1<<"\n";
        cin>>N;
        A = new int[N];
        cout<<"Enter the elements\n";
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        Triplet(A,N);
        delete []A;
    }
}
