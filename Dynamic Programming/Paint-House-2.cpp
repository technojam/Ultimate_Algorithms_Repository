// Problem Statement
// There are a row of n houses, each house can be painted with one of the k colors.
// The cost of painting each house with a certain color is different. 
// You have to paint all the houses such that no two adjacent houses have the same color.
// The cost of painting each house with a certain color is represented by a n x k cost matrix. 
// For example, costs[0][0] is the cost of painting house 0 with color 0;
// costs[1][2] is the cost of painting house 1 with color 2, and so on... 
// Find the minimum cost to paint all houses.
#include <bits/stdc++.h>
using namespace std;
int minCostII(vector<vector<int>>& costs) {
 
    int n = costs.size();
    if(n == 0)return 0;
    int k = costs[0].size();
    vector<vector<int>> dp(n+1,vector<int>(k,0));
    // dp[i+1][j] stores the minimum cost of painting the house i with colour j
    
    //dp[i+1][j] = costs[i][j] + min(dp[i][0,....(j-1),(j+1)...,k]),i.e, the minimum cost of 
    // painting the house i-1 with any cost other than j cuz we cannot paint 2 
    // consequtive houses with the same colour

    int res= INT_MAX;
    for(int i= 0;i < n;i++ )
    {
        vector<int> mn;
       for(int j= 0 ; j < k;j++)
       {
           mn.push_back(dp[i][j]);
       }
        sort(mn.begin(),mn.end());
        for(int j = 0 ;j < k;j++)
        {
            int mindp = mn[0];
            if(dp[i][j]== mn[0] && k > 1)mindp = mn[1];
            dp[i+1][j] = costs[i][j]+mindp;
            
            if(i == n-1)res = min(res,dp[i+1][j]);
        }
        
        
    }
    return res;   
}
int main() {
ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n , k;
    cout << "Enter the number of houses :" << endl;
    cin >> n;
    cout<<  "Enter the number of colours :" << endl;
    cin >> k;
    cout << "Enter the cost to paint a particular house with a particular colour : " << endl;
    vector<vector<int>> costs(n,vector<int>(k));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin >> costs[i][j];
        }
    }
    int mincost = minCostII(costs);
    cout << "Minimun cost to paint the houses : " << mincost << endl;

 return 0;
}