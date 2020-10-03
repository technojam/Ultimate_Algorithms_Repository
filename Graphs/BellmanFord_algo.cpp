This algorithm calculates distance and also checks if there is a negative wight cycle and return false neg weight cycle found.
#include<bits/stdc++.h>
using namespace std;

bool bellman_ford(vector<tuple<int,int,int>> vect,int V,int E,int dist[])
{
    int i,j,u,v,w;
    for(i=0;i<V-1;i++)
    {
        for(j=0;j<E;j++)
        {
            u = get<0>(vect[j]);
            v = get<1>(vect[j]);
            w = get<2>(vect[j]);
            
            if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
                dist[v] = dist[u]+w;
            //cout<<dist[v]<<endl;*/
        }
    }
    
    for(j=0;j<E;j++)
    {
            u = get<0>(vect[j]);
            v = get<1>(vect[j]);
            w = get<2>(vect[j]);
            
            if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
                return true;
            
    }
    return false;
}

int main()
{
    int t;  cin>>t;
    while(t--)
    {
        int V,E,i,x,y,w;    cin>>V>>E;
    
        int dist[V];
        for(i=0;i<V;i++) dist[i] = INT_MAX;
        dist[0]=0;
        
        vector<tuple<int,int,int>> vect;
        for(i=0;i<E;i++)
        {
            cin>>x>>y>>w;
            vect.push_back(make_tuple(x,y,w));
        }
        
        cout<<bellman_ford(vect,V,E,dist)<<endl;
        
    }
}
