// GenericGraph
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

template<typename T>
class Graph{
	void DFSHelper(T node,unordered_map<T,bool> &visited){
		cout<<node<<' ';
		visited[node] = true;

		for(auto children:adjList[node]){
			if(!visited[children]){
				DFSHelper(children,visited);
			}
		}
	}

public:
	unordered_map<T,list<T> > adjList;

	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void Print(){
		for(auto node:adjList){
			cout<<node.first<<"-->";
			for(auto neighbours:node.second){
				cout<<neighbours<<" ";
			}
			cout<<endl;
		}
	}


	void DFS(T src){
		unordered_map<T,bool> visited;
		int component = 1;
		DFSHelper(src,visited);

		for(auto node:adjList){
			if(!visited[node.first]){
				DFSHelper(node.first,visited);
				component++;
			}
		}
		cout<<endl<<"Number of Components "<<component<<endl;
		return;
	}
};

int main(){
	
	Graph<int> g;

	g.addEdge(1,0);
	g.addEdge(1,2);
	g.addEdge(4,2);
	g.addEdge(3,2);
	g.addEdge(4,0);
	g.addEdge(4,3);
	g.addEdge(5,3);
	g.addEdge(101,111);
	g.addEdge(112,111);
	g.addEdge(1120,1110);
	g.addEdge(1121,1112);

	g.DFS(0);
	cout<<endl;
	return 0;
}
