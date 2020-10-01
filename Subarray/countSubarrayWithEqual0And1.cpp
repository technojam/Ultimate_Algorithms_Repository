#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first
#define s second

using namespace std;

int countSubarrays(int a[],int n){
	map<int,int> m;
	int cursum=0;
	for(int i=0;i<n;i++){
		if(a[i]==0){
			cursum+=-1;
		}
		else{
			cursum+=a[i];
		}
		m[cursum]++;
	}
	int count=0;
	for(auto i=m.begin();i!=m.end();i++){
		if(i->second > 1){
			count+=(i->second*(i->second-1))/2;
		}
	}
	if(m.find(0)!=m.end()){
		count+=m[0];
	}
	return count;
}
int main(){
	std::ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
	freopen("input.txt", "r", stdin);
    // for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans=countSubarrays(a,n);
	cout << ans << endl;
	return 0;
}