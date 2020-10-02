#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
	unordered_map<T,list<pair<T,int>>>m;
    public:
    	void addEdge(T u, T v, int dist, bool dir= true){
            m[u].push_back(make_pair(v,dist));
            if(dir){
            	m[v].push_back(make_pair(u,dist));
            }
    	}
    	void printEdge(){
             //print all key value pair in the map

    		for(auto j:m){
    			cout<<j.first<<"-->";
    		for(auto l:j.second){
    			cout<<"("<<l.first<<" "<<l.second<<")";
    		}
    		cout<<endl;
    	}
    }
    	void dijsktraSSS(T src){
    		unordered_map<T,int>dist;

    		//set all distance to infinity
    		for(auto j:m){
    			dist[j.first]= INT_MAX;
    		}
    		 //make a node to find out the node with min distance

    		set<pair<int,T>>s;
    		dist[src]= 0;
    		s.insert(make_pair(0,src));

    		while(!s.empty()){
    			//find the pair at front

    			auto p= *(s.begin());
    			T node= p.second;
    			int node_dist= p.first;
    			s.erase(s.begin());

    			//Iterate over the neighbours of current node

    			for(auto childPair:m[node]){
    				if(node_dist+ childPair.second< childPair.first){

    					// In the set updation of a particular node is not possible
    					// so we have to remove the old pair,and insert the new pair to simulation updation
                        T dest= childPair.first;
    					auto f= s.find(make_pair(dist[dest],dest));
    					if(f!= s.end()){
    						s.erase(f);
    					}
    					//insert the new Pair

    					dist[dest]= node_dist+ childPair.second;
    					s.insert(make_pair(dist[dest],dest));
    				}
    			}
    		}
    		//Lets print the distances to all other nodes

    		for(auto d:dist){
    			cout<<d.first<<"is located at distance of "<<d.second<<endl;
    		}
    	}
    };

int main(){

	Graph<int>g;
	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(2,3,1);
	g.addEdge(3,4,2);
	g.addEdge(1,4,7);
	g.printEdge();
	g.dijsktraSSS(1);
  return 0;
}
