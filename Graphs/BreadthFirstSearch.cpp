#include <bits/stdc++.h>
using namespace std;

// CPP CODE FOR BREADTH FIRST SEARCH ON UNDIRECTED GRAPH
// TIME COMPLEXITY : O(N)  , where N is the number of nodes
// SPACE COMPLEXITY : O(M) , where M is the number of edges
const int MAXN=100005, inf = 1000000007;
vector<int> graph[MAXN];
int dis[MAXN];
int nodes, src, edges;

void bfs(int node)
{
    dis[node]=0;
    queue<int> q;
    q.push(node);
    int x;
    while(!q.empty){
        x = q.front();
        q.pop();
        for(auto &y : graph[x]){
          if(dis[y] > dis[x]+1){
            dis[y] = dis[x]+1;
            q.push(y);
          }
        }
    }
}


void input()
{
    cin >> nodes >> edges;
    int u, v;
    for(int i=0;i<edges;++i){
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    cin >> src;
}

int main()
{
    memset(dis, inf, sizeof(dis));
    input();
    bfs(src);
    return 0;
}
