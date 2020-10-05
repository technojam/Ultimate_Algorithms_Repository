/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
//Runtime: 164 ms, faster than 46.03% of C++ online submissions for Wildcard Matching.
//Memory Usage: 27.9 MB, less than 10.58% of C++ online submissions for Wildcard Matching.
class Solution {
public:
    bool isMatch(string s, string p) {
        int size1=s.length(),size2=p.length();
        vector<vector<int>> temp(size1+1,vector<int>(size2+1));
        temp[0][0]=1;
        for(int i=1;i<=size2;i++)    // special case
        {
            if(p[i-1]!='*')
                break;
            else
                temp[0][i]=1;
        }
        for(int i=1;i<=size1;i++)
        {
            for(int j=1;j<=size2;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    temp[i][j]=temp[i-1][j-1];
                else if(p[j-1]=='*')
                    temp[i][j]=max(temp[i-1][j],temp[i][j-1]);
                else
                    temp[i][j]=0;
            }
        }
        /*
        for(int i=0;i<=size1;i++)
        {
            for(int j=0;j<=size2;j++)
                cout<<temp[i][j]<<" ";
            cout<<"\n";
        }*/
        return temp[size1][size2];
        }
};
