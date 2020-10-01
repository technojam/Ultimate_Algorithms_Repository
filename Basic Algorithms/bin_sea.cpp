#include<iostream>
using namespace std;

class Bsearch{
private:
  int mid,low,high;
public:
  int bsI(int[],int,int);
  int bsR(int[],int,int,int);
  int bsM(int[],int,int);
};

//ITERATIVE WAY

int Bsearch :: bsI(int arr[],int n,int x){
  int low=0;
  int high = n-1;

  while(low<=high){
    int mid  = (low+high)/2;
    if(arr[mid] == x) return arr[mid];
    else if(arr[mid]>x) high = mid-1;
    else low = mid+1;
  }
  return false;
}

//RECURSIVE WAY

int Bsearch :: bsR(int arr[], int i, int l, int n){
  if(l == i) return arr[l] == n;
  else{
    int mid = (l+i)/2;
    if(arr[mid]>n) return bsR(arr,i,mid-1,n);
    else if(arr[mid]<n) return bsR(arr,mid+1,l,n);
    else return arr[mid];
  }
}

//MODIFIED WAY

int Bsearch :: bsM(int arr[],int n,int x){
  int low=0;
  int high = n;

  while(low<(high-1)){
    int mid  = (low+high)/2;
    if(arr[mid]>x) high = mid;
    else low = mid;
  }
  if(arr[low] == x) return 1;
  else return 0;
}

int main(){
  Bsearch b;
  int size,*a,find,ch,low,high,it,re,mo;
  cout<<"Enter size: ";
  cin>>size;
  a = new int[size];
  for(int i = 0;i < size;i ++) cin>>a[i];
  do{
    cout<<"\n1.Iterative\n2.Recursive\n3.Modified\n4.Exit\nEnter: ";
    cin>>ch;
    cout<<"Enter ele to find : ";
    cin>>find;
    switch(ch){
      case 1:
        it = b.bsI(a, size, find);
        if(it) cout<<"\nFOUND\n";
        else cout<<"\nNOT FOUND\n";
        break;
      case 2:
        low=0,high=size-1;
        re = b.bsR(a,low,high,find);
        if(re) cout<<"\nFOUND\n";
        else cout<<"\nNOT FOUND\n";
        break;
      case 3:
        mo = b.bsM(a, size, find);
        if(mo) cout<<"\nFOUND\n";
        else cout<<"\nNOT FOUND\n";
        break;
    }
  }while(ch!=4);
  return 0;
}
