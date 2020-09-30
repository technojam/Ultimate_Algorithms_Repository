#include<iostream>
using namespace std;
void create(int ar[],int start,int end)
{

    if(start > end)
      return;
       
    int mid = (start+end)/2;
    cout<<ar[mid]<<" ";
    
     create(ar,start,mid-1);
     create(ar,mid+1,end);

  
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	   int n;
	   cin>>n;
	   int a[n];
	   for(int i=0;i<n;i++)
	   {
	       cin>>a[i];
	   }
	   
	 create(a,0,n-1);
	   
	   
	   cout<<endl;
	}
}
