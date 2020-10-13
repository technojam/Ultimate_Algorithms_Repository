#include <bits/stdc++.h>
using namespace std;
/*
void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 

    c = getchar(); 
    if (c=='-') 
    { 
        negative = true; 

        c = getchar(); 
    } 
  
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 

    if (negative) 
        number *= -1; 
}
*/

int solve()
{
	string s, check = "";
	cin>>s;
	for(int j = 0; j < s.length(); j++)
	{
		check += "#" + s.substr(j, 1);
	}
	check += "#";
	// In the above code we are adding # with every character of string
	// for example if string is car then check will be #c#a#r#
	// we will iterate over check to count palindromes
	int n, best = 1; // best is to count max length of palindrome in string
	n = check.length();
	vector<int> z(n, 0); // this is container for pailindrome length
	z[0] = 1; // palindrome will be counted and added here
	for(int i = 1, r = 0, c = 1; i < n; i++)
	{
		// Here c represents center to check for painddromic strings
		// and r represents bound of painddrome across c
		// and i is iterator across check srting
		
		// this if below is to check if the pattern across previous occurance 
		// of the string in same palindrome exceeds bounds of current palindrome 
		// with center c and bound r
		// if the palindome exceeds bounds then we have to once again calculate
		// palindrome across that element or else we can simply use previously
		// calculated value
		// calculation of length of palindrome across that element is done in
		// else statement
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
	// here we just simply calculate max of z array which contains 
	// length of palindome across all the elements to get length of 
	// longest palindromic substring
 	for(int l = 0; l < n; l++) 
 	{
		if(best < z[l]) 
 		{
 			best = z[l];
 		}
 	}
 	// as we added "#" b/w each charaters, length of palindrome is calculated
 	// with considering "#" also so to remove them we just simply divide the 
 	// best by 2 to get actual value
 	best /= 2;
 	cout<<best;
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