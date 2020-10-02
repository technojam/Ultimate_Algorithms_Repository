#include <bits/stdc++.h>
using namespace std;
#include <chrono> 
using namespace std::chrono; 

// This is Z algorithm to find the count pattern string 
// in any test string in order of O(N) only!!!! 

void ZA(string pat, string t)
{
    string h = pat + "$" + t;
    int len = h.size(), count = 0, pat_len = pat.size();
    vector<int> z(len, 0);
    for(int i = 1, lower_bound = 0, upper_bound = 0; i < len; i++)
    {          
        if(i>r)
        {
            lower_bound = upper_bound = i;
            while(upper_bound < len && h[upper_bound] == h[upper_bound - lower_bound]) upper_bound++;
            z[i] = upper_bound-lower_bound;
            upper_bound--;
        }
        else
        {
            int index = i - lower_bound;
            if(z[index] < upper_bound - i + 1) z[i] = z[index];
            else
            {
                lower_bound = i;
                while(upper_bound < len && h[upper_bound] == h[upper_bound - lower_bound]) upper_bound++;
                z[i] = upper_bound-lower_bound;
                upper_bound--;
            }
        }
    }
    for(int i = 0; i < len; i++)
    {
        if(z[i] == pat_len) count++;
    }
    cout<<count;
}
int solve()
{
    string pat, t, h;
    cin>>pat>>t;
    vector<int> z;
    ZA(pat, t);
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