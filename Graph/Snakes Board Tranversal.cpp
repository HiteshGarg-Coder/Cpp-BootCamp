// GenericGraph
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph{
public:
	unordered_map<T,list<T> > adjList;

	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	int SSSP(T src,T des){
		unordered_map<T,int> dist;
		unordered_map<T,T> parent;

		// Mark the distance of every node as INT_MAX
		for(auto node:adjList){
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0;
		parent[src] = src;

		queue<T> q;
		q.push(src);

		while(!q.empty()){
			auto node = q.front();
			q.pop();
			for(auto children:adjList[node]){
				if(dist[children] == INT_MAX){
					dist[children] = 1 + dist[node];
					q.push(children);
					parent[children] = node;
				}
			}
		}

		// for(auto node:dist){
		// 	cout<<"Distance of "<<node.first<<" from "<<src<<" : "<<node.second<<endl;
		// }

		// Printing the path
		cout<<"Path Followed : ";
		T temp = des;
		while(temp!=src){
			cout<<temp<<"<--";
			temp = parent[temp];
		}
		cout<<src<<endl;

		return dist[des];
	}
};

int main(){
	
	Graph<int> g;
	// Graph<string> g;
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17]=-13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for(int u=0;u<=36;u++){
		for(int dice = 1;dice<=6;dice++){
			int v = u+dice + board[u+dice];
			g.addEdge(u,v,false);
		}
	}
	
	int ans = g.SSSP(0,36);
	cout<<"Minimum Moves of 0 and 36 is "<<ans<<endl;
	
	return 0;
}
