Link:https://www.codechef.com/SEPT20B/problems/ADAMAT
#include <bits/stdc++.h>
using namespace std;
int main(){
   long long  int t1;
    cin>>t1;
    while(t1--){
        long long int   n1;
        cin>>n1;
         long long int  arr[n1][n1],i1,j1,rem,s1,c1=0,tr1,k1;;
        for( i1=0;i1<n1;i1++){
            for( j1=0;j1<n1;j1++){
                cin>>arr[i1][j1];
            }
        }
        
      // long long int 
        for( k1=n1-1;k1>0;k1--){
            rem=arr[k1][k1-1]+1;
            if(rem!=arr[k1][k1]){
                c1++;
                s1=k1+1;
            for(i1=0;i1<s1;i1++){
                 for( j1=i1;j1<s1;j1++){
                      tr1=arr[i1][j1];
                      arr[i1][j1]=arr[j1][i1];
                      arr[j1][i1]=tr1;
                 }
            }
            }
        }
            cout<<c1<<"\n";
               
            }
    

	return 0;
}
