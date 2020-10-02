/*Take a variable currSum.
Make the sum of the entire array considering all zeroes as -1 and 1 as 1.
Simultaneously keep updating the value of hashmap as you traverse through the array.
Now traverse through the hashmap and look if any value of currSum appears more than once.
Why do we do this?
Imagine an array like this: [1, 0, 0, 1, 0, 1, 1]
Making all zeroes as -1.
[1, -1, -1, 1, -1, 1, 1]
Now the hashmap would have values such as this:
-1 --- 2
0 --- 3
1 --- 2
Now as if we encounter the same sum more than twice, that means the value of the subarray between the two indices is zero. So we add that to our answer.
Finally add the hashmap value of 0 to our answer as the subarray with zero-sum also need to be counted.*/

#include <bits/stdc++.h> 
using namespace std; 
  
int countSubarrWithEqualZeroAndOne(int arr[], int n){ 
  map<int,int> mp; 
  int currSum=0; 
  int count=0; 
   for (int i = 0; i < n; i++) { 
            //Replacing 0's in array with -1 
            if (arr[i] == 0) 
                arr[i] = -1; 
  
            currSum+= arr[i]; 
  
            //If sum = 0, it implies number of 0's and 1's are 
            //equal from arr[0]..arr[i] 
            if (currSum == 0) 
                count++; 
  
            if (mp[currSum]) 
                count += mp[currSum]; 
            if(mp[currSum]==0) 
                mp[currSum]=1; 
            else
                mp[currSum]++; 
  
        } 
  return count; 
} 
  
int main() 
{ 
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
  cin>>a[i];
  }
  cout<<countSubarrWithEqualZeroAndOne(a, n); 
} 

/*
Sample Input:
7
1 0 0 1 0 1 1
Sample Output:
8
*/
