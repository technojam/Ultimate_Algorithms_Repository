#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000];
bool m[1000];
int l[1000];
bool test(int n,int c)
{
    m[n]=true;
    l[n]=c;
    for(auto j : v[n])
    {
        if(m[j]==false)
        {
            if(test(j,c^1)==false)
                return false;
        }
        else
        {
            if(l[j]==l[n])
                return false;
        }

    }
    return true;
}
int main()
{
    int i,n,a,b;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(!test(1,0))
        cout << "No";
    else
        cout << "Yes";
}
