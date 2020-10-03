#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

vector<string> ans;

bool isvalid(string s)                              // validating the parenthesis using stack
{
    stack<char> k;
    for (int i = 0; i < s.length(); i++)
    {
        if (k.empty())
        {
            k.push(s[i]);
        }
        else
        {
            if (s[i] == '(')
                k.push(s[i]);
            else
            {
                if (k.top() == '(')
                    k.pop();
                else
                    return false;
            }
        }
    }
    if (!k.empty())return false;
    return true;                                // return true is valid
}

void solve(vector<string>& ans, string s, int openc, int closec)
{
    if (closec == openc and closec == 0)
    {
        if (isvalid(s))  ans.push_back(s);      // after valid completion pushing it to ans array.
    }
    if (openc > 0 and closec > 0 and closec >= openc) {
        solve(ans, s + '(', openc - 1, closec);
        solve(ans, s + ')', openc, closec - 1);
    }
    if (openc == 0 and closec > 0)
    {
        solve(ans, s + ')', openc, closec - 1);
    }
}

int main()
{
    cout << "Enter n-";
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << n << endl;                  //input
    string s = "";
    solve(ans, s, n, n);                //function to generate all possible answers

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}

