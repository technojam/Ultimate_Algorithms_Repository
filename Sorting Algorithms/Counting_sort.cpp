/* 

Only used when numbers are small enough like at max 10^7 or difference between
max and min is ~ 10^7

Eg:
v = {5, .. . ., 10000005}

we can map numbers by subtracting the samllest term 

v = {0,. .. . ., 10000000}

now sort


-------------------------Time and Space------------------------

Time - O(n+k) 
Space - O(n+k)

---------------------------------------------------------------

*/

#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &v)
{
    int mx=numeric_limits<int>::min();
    for(auto u:v) mx=max(mx,u);

    int n=v.size();
    vector<int> tmp(n);
    vector<int> cnt(mx+1,0);

    for(auto u:v) cnt[u]++;
    for(int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--)
    {
            tmp[cnt[v[i]]-1]=v[i];
            cnt[v[i]]--;
    }

    v.clear();
    v=tmp;
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL);

    int n=0;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    count_sort(v);
    
    for(auto u:v) cout<<u<<" ";
    cout<<"\n";

    return 0;
}
