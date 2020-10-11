//This program takes a string as input and reverse every word of that string.
/*eg. : input : 'This is a tree'
        output : 'tree a is This'
It uses stack data structure to reverse the words of string.
*/
#include <bits/stdc++.h>
using namespace std;

string util(string s){
    stack<string>temp;
    stringstream str(s);
    string word;
    while(str>>word)
        temp.push(word);
    string res="";
    while(!temp.empty()){
        res+=temp.top()+' ';
        temp.pop();
    }
    return res.substr(0,res.size()-1);
}

int main() {
    string s = "This is a tree";
    cout<<util(s)<<endl;
}

