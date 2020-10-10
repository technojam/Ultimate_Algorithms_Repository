#include <bits/stdc++.h>
using namespace std;

// CPP CODE FOR DEPTH FIRST SEARCH ON UNDIRECTED GRAPH
// TIME COMPLEXITY : O(N)
// SPACE COMPLEXITY : O(N^2) , where N is the number of nodes
vector<int> graph[10001];
bool visited[10001];
int nodes;

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

void input()
{
    cin >> nodes;
    int curr;
    //taking input as an adjacency matrix and converting it into an adjacency list
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            cin >> curr;
            if (curr)
            {
                graph[i].push_back(j);
            }
        }
    }
}

int main()
{
    memset(visited, false, sizeof(visited));
    input();
    dfs(1);
    return 0;
}