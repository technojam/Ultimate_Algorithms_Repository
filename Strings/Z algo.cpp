#include <bits/stdc++.h>
using namespace std;

// This is Z algorithm to find the count pattern string 
// in any test string in order of O(N) only!!!! 

void ZA(string pat, string t)
{
    string h = pat + "$" + t; // Conactenating pattern with test string to make process easy
    int len = h.size(), count = 0, pat_len = pat.size();
    vector<int> z(len, 0); // this is Z array which we will create to count pattern string in test string
    for(int i = 1, lower_bound = 0, upper_bound = 0; i < len; i++)
    {   
        // lower bound is the bound which is used to retain lower bound of pattern string in test string       
        // similarly upper bound is to retain upper bound of pattern string
        if(i>upper_bound) // if the current held position of charater of string h is greater than upper bound 
        {
            lower_bound = upper_bound = i; // make the lower bound and upper bound equal to i
            while(upper_bound < len && h[upper_bound] == h[upper_bound - lower_bound]) upper_bound++; // count the length which is similar to pattern striing (staring string before $)
            z[i] = upper_bound-lower_bound;// store length of simillar part length (is this length == patern length therefore pattern found)
            upper_bound--;//upper bound is 1 more than actual position of upper bound so subtracting 1 form it
        }
        else // if i < upper bound so to minimize loop we will use previously calculated z values(if possible) 
        {
            int index = i - lower_bound; // index from starting position
            if(z[index] < upper_bound - i + 1) z[i] = z[index]; // if this z index is less than upper bound - i then we can use pre calculated value of Z
            else // else we will have to calculate the z index as shown in above if statement
            {
                // simmilar to above if statement (here we don't require to change upper bound because string b/w lower and upper bound is already similar to pattern for some charaters)
                lower_bound = i;
                while(upper_bound < len && h[upper_bound] == h[upper_bound - lower_bound]) upper_bound++;
                z[i] = upper_bound-lower_bound;
                upper_bound--;
            }
        }
    }
    for(int i = 0; i < len; i++) // now count where this array z is same as pattern length and print or use it
    {
        if(z[i] == pat_len) count++;
    }
    cout<<count;
}
int solve()
{
    string pat, t;
    cin>>pat>>t; // taking input of pattern and test string
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