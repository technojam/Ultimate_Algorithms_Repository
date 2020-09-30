/*Given 2 matrices, find the product.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define outer1 for(int i=0;i<r1;i++)
#define inner1 for(int j=0;j<c1;j++)

#define outer2 for(int i=0;i<r2;i++)
#define inner2 for(int j=0;j<c2;j++)

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


int main() {
    fio;
    
    int t;
    cin>>t;
    while(t--){
        int r1,c1;
        cin>>r1>>c1;
        
        int a[r1][c1];
        outer1{
            inner1{
                cin>>a[i][j];
            }
        }
        
        int r2,c2;
        cin>>r2>>c2;
        
        int b[r2][c2];
        
        outer2{
            inner2{
                cin>>b[i][j];
            }
        }
        
        
        int prod[r1][c2];
        
        outer1{
            inner2{
                prod[i][j]=0;
                for(int k=0;k<c1;k++){
                    prod[i][j]+=a[i][k]*b[k][j];
                    
                }
            }
        }
        
        
        outer1{
            inner2{
                cout<<prod[i][j]<<" ";
            }
            
            cout<<endl;
        }
    }
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
