/*

 This algorithm is for Bipartite testing a graph i.e can the Graph be divided into two different sets of nodes
 which have Union as NULL.

 Each Node is given a color, if two adjacent nodes have same color then Bipartition is not possible

*/

#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000]; // Adjacency List
bool m[1000];        // Marking Vector
int l[1000];         // Color Vector
bool test(int n,int c)
{
    m[n]=true;
    l[n]=c;           // Color assignment
    for(auto j : v[n])
    {
        if(m[j]==false)
        {
            if(test(j,c^1)==false)         // Recursive False returning
                return false;
        }
        else
        {
            if(l[j]==l[n])                 // Adjacent nodes having same color
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
        v[a].push_back(b);                  // making of adjacency list
        v[b].push_back(a);
    }
    if(!test(1,0))
        cout << "No";
    else
        cout << "Yes";
}
