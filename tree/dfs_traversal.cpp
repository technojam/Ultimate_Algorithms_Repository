#include<bits/stdc++.h>
using namespace std;

/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void solve(vector<int> g[],vector<int>& res,vector<bool>& isVis,int curr){
    res.push_back(curr);
    isVis[curr] = true;
    for(auto i : g[curr]){
        if(!isVis[i])
            solve(g,res,isVis,i);
    }
}
vector <int> dfs(vector<int> g[], int N)
{
    
    vector<int> res;
    vector<bool> isVis(N,false);
    for(int i=0;i<N;i++){
        if(!isVis[i]){
            solve(g,res,isVis,i);
        }    
    }
    return res;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  