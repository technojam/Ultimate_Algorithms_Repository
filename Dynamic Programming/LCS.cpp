#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
/* 
    Were going to fill the table bottom up then recursively search for lcs top down 
    using the values from the table we filled.
*/
// define max length of strings x and y
#define MAX 120
int table[MAX][MAX];

// recursive call to find lcs of string x[0.. m-1] & y[0.. n-1]
vector<string> lcs(string x, string y, int m, int n) {
    // return empty string if we reach the end of either sequence.
    if(m==0 || n ==0){
        vector<string> v(1); return v;
    }
    // if the last character of x and y match
    if(x[m-1] == y[n-1]){
        // ignore them and find all lcs of 
        //substr x[0..m-2], y[0..n-2] and store it in a vector
        vector<string> LCS = lcs(x,y,m-1,n-1);
        // append current char x[m-1] or y[n-1] to all lcs of
        //substr x[0..m-2] & y[0..n-2]
        for(string &s : LCS)
            s.push_back(x[m-1]);

        return LCS;
    }
    // otherwise last char are different
    // if the upper cell of the current cell value is larger then the left cell
    // then ignore current character of string x and find all lcs od 
    // substr x[0..m-2], y[0..n-1]
    if(table[m-1][n] > table[m][n-1])
        return lcs(x,y,m-1,n);
    // if the left cell of the current cells value is larger then the upper cell
    // then ignore current character of string x and find all lcs of 
    // substr x[0..m-1], y[0..n-2]
       if(table[m-1][n] > table[m-1][n])
        return lcs(x,y,m,n-1);

        // if thupper cell has equal val to the left cell then consider both characters
        vector<string> upper = lcs(x,y,m-1,n);
        vector<string> left = lcs(x,y,m,n-1);
        // merge and return
        upper.insert(upper.end(), left.begin(), left.end());
        return upper;
}
// fill the table by finding the length of lcs x[0..m-1], y[0.. n-1].
void lcslen(string x, string y, int m, int n){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(x[i-1] == y[j-1])
                table[i][j] = table[i-1][j-1] +1;
            else
                table[i][j] = max(table[i-1][j], table[i][j-1]); 
        }
    }
}
//  return all possible longest sequences
set<string> lcs2(string x, string y){
    int m = x.length(), n = y.length();
    lcslen(x,y,m,n);
    vector<string> vec = lcs(x,y,m,n);
    set<string> lcset(make_move_iterator(vec.begin()),
                                make_move_iterator(vec.end()));
    return lcset;
}
// test drive
int main(){
string b = "ABCBDAB", d = "BDCABA";
set<string> longestCommonSeq = lcs2(b,d);
for(string s:longestCommonSeq)
    cout << s << "\n";
    return 0;
}