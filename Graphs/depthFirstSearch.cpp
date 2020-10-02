#include <bits/stdc++.h>
using namespace std;

// CPP CODE FOR DEPTH FIRST SEARCH ON UNDIRECTED GRAPH
// TIME COMPLEXITY : O(N)  , where N is the number of nodes
// SPACE COMPLEXITY : O(M) , where M is the number of edges
vector<int> graph[10001];
bool visited[10001];
int nodes, edges;

void dfs(int node)
{
    visited[node] = true;
    for (auto child : graph[node])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

void dfs_util(){
    for(int i=1;i<=nodes;++i){
        if(!visited[i]){
            dfs(i);   
        }
    }
}

void input()
{
    cin >> nodes >> edges;
    int u , v;
    //taking input as an adjacency list
    for(int i=0; i<edges; ++i){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int main()
{
    memset(visited, false, sizeof(visited));
    input();
    dfs_util();
    return 0;
}
