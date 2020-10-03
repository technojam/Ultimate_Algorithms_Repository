#include<bits/stdc++.h>
using namespace std;
int kadane(int array[],int length) 
{
   int highest = 0;
   int cuurMax = 0;
   for(int i = 0; i < length; i++){
      cuurMax=max(array[i],cuurMax + array[i]) ;
      highest=max(highest,cuurMax);
   }
   return highest;
}
int main() {
   cout<<"Enter the array size: ";
   int l;
   cin>>l;
   int Array[l];
   cout<<"Enter the elements: ";       // Taking user input
   for (int i = 0; i < l; i++) {
      cin>>Array[i];
   }
   cout<<"Max Sum "<<kadane(Array,l)<< endl;
   return 0;
}