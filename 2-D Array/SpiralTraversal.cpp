/*Given a 2D square matrix, print the matrix in a spiral order. 
Refer examples for more details. From interviews point of view, 
after you scan the matrix in a 2D array, try to print the matrix
 in a spiral order without using any extra space.*/

 /*Sample Input 
4
1
1
2
1 2
4 3
3
1 2 3
8 9 4
7 6 5
5
-44 25 -52 69 -5 
17 22 51 27 -44 
-79 28 -78 1 -47 
65 -77 -14 -21 -6 
-96 43 -21 -20 90 

Sample Output 
1 
1 2 3 4 
1 2 3 4 5 6 7 8 9 
-44 25 -52 69 -5 -44 -47 -6 90 -20 -21 43 -96 65 -79 17 22 51 27 1 -21 -14 -77 28 -78 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n;
        scanf("%d",&n);
        
        int a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        
        int top=0,b=n-1,l=0,r=n-1;
        
        while(top<=b && l<=r){
            
            for(int i=l;i<=r;i++){
                printf("%d ",a[top][i]);
            }
            top++;
            
            for(int i=top;i<=b;i++){
                printf("%d ",a[i][r]);
            }
            r--;
            
            for(int i=r;i>=l;i--){
                printf("%d ",a[b][i]);
            }
            
            b--;
            
            for(int i=b;i>=top;i--){
                printf("%d ",a[i][l]);
            }
            
            l++;
        }
        printf("\n");
    }
    return 0;
}
