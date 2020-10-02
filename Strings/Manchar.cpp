#include <bits/stdc++.h>
using namespace std;

// This is Manachar Algorithm to find
// longest palindromic substring in O(N)

int solve()
{
	string s, check = "";
	cin>>s;
	for(int j = 0; j < s.length(); j++)
	{
		check += "#" + s.substr(j, 1);
	}
	check += "#";
	int n, best = 1, R, C;
	n = check.length();
	vector<int> z(n, 0);
	z[0] = 1;
	for(int i = 1, r = 0, c = 1; i < n; i++)
	{
		if((z[2*c - i] < (2*(c+r+1-i) - 1)) && (i < c + r))
		{
			z[i] = z[2*c - i];
		}
		else
		{
			r = 0;
			c = i;
			while(check[i + r] == check[i - r]) 
			{
				z[i]+=2;
				r++;			
			}
			z[i]--;
			r--;
		}
	}
	int m = 0;
 	for(int l = 0; l < n; l++) 
 	{
		if(best < z[l]) 
 		{
 			best = z[l];
 			R = z[l]/2;
 			C = l;
 		}
 	}
 	best /= 2;
 	cout<<best<<"\n";
 	for(int i = C - R; i < C+R+1; i++)
 	{
 		if(check.substr(i,1) != "#") cout<<check.substr(i,1);
 	}
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    long long t;
    t = 1;
    while(t--)
    {
    	solve();
    	cout<<"\n";
    }

    return 0;
}