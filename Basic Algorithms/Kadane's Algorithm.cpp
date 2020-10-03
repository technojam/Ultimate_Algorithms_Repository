//KADANE'S algorithm is able to find the MaximumSum of a Contiguous Subarray in array with the runtime of O(n)...

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1000], cs=0, ms=0;
    for(int i=0, i < n, i++){
        cin>>a[i];
    }
    //Kadane's algorithm for Subarray Sum
    for(int i=0; i<n; i++){
        cs = cs + a[i];
        if(cs<0){
            cs = 0;
        }
        ms = max(cs,ms);
    }
    cout<<"Maximum is"<<ms<<endl;
    return 0;
}

example 1:-
INPUT:-

9
-4  1  3  -2  6  2  -8  -9  4

OUTPUT:-

Maximum is 10

Example 2:-
INput:-

9

-4  1  3  -2  16  2  -8  -9  4

Maximum is 20
