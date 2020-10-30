// Taking a string of open and close paranthesis and telling if they are balanced

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

#define SIZE 1000000

int main()
{
    char arr[SIZE];
    cin >> arr;
    ll len = strlen(arr), i;
    stack<char> s;
    for (i = 0; i < len; i++)
    {
        if (arr[i] == '<' || arr[i] == '[' || arr[i] == '{' || arr[i] == '(')
            s.push(arr[i]);
        else if (s.empty())
            break;
        else if (arr[i] == ')' && s.top() == '(')
            s.pop();
        else if (arr[i] == '>' && s.top() == '<')
            s.pop();
        else if (arr[i] == '}' && s.top() == '{')
            s.pop();
        else if (arr[i] == ']' && s.top() == '[')
            s.pop();
        else
            break;
    }

    if (!s.empty() || i != len)
        cout << "Not balanced \n";
    else
        cout << "Balanced\n";
    return 0;
}