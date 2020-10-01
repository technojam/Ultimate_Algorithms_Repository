#include <iostream>
#include<algorithm>
using namespace std;
int get_change(int money, int dp[]) {
   int coins[] = {1,3,4};
   
   //checking whether we reached at end means we have changed all money with our denominations
   if(money==0)
   return 0;
   
   int ans = -1;  // -1 is Just Indication or Flag to be used later
   
   // when coins are variable change 3 to number of coins
   for(int i=0;i<3;i++) 
   {
   	    if(money - coins[i] >= 0)
   	    {
   	    	int subAns = 0;   //Initializing with 0 or can say simply creating a variable which can hold the value of subAns of Problem
   			
			//Main Recursion 
			if(dp[money-coins[i]] != -1 )    //if DP array has already a value stored for any money then simply use it 
			subAns = dp[money - coins[i]];
			
			//otherwise do recursion
			else{
			subAns = get_change(money-coins[i],dp);
			}
			
			//if ans is not filled yet or filled but more subAns has more optimal answer then update it 
			if(subAns+1 < ans || ans ==-1)
			ans = subAns+1;
		}
   	    
   }
    //Storing the optimal number of coins to change for that money at the index
  	dp[money]=ans;  
  	return ans;
	//Reduce Steps using 
	return dp[money] = ans;
}

int main() {
  int m;
  std::cin >> m;
  //Just more than one the money to change because we are initalizing with 0 for 0
  int dp[m+1];  
  
  //Filling -1 in every index just to indicate that subproblem is not calculated yet
  fill(dp,dp+m+1,-1);

  int ans = get_change(m,dp);
  std::cout << ans << '\n';
}
