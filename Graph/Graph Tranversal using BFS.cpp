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

	void Print(){
		for(auto node:adjList){
			cout<<node.first<<"-->";
			for(auto neighbours:node.second){
				cout<<neighbours<<" ";
			}
			cout<<endl;
		}
	}

	void BFS(T start){
		unordered_map<T,bool> visited;
		queue<T> q;

		q.push(start);
		visited[start] = true;

		while(!q.empty()){
			auto node = q.front();
			q.pop();
			cout<<node<<" ";

			for(auto children:adjList[node]){
				if(!visited[children]){
					visited[children] = true;
					q.push(children);
				}
			}
		}
		cout<<endl;
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

	g.BFS(0);

	g.Print();

	cout<<endl;
	return 0;
}
