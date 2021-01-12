#include <iostream>
#include <list>
using namespace std;

class Graph{
public:
	list<int> *adjList;
	int n;
	Graph(int N){
		n = N;
		adjList = new list<int>[n];
	}

	void addEdge(int u,int v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void Print(){
		for(int i=0;i<n;i++){
			cout<<i<<"->";
			for(auto node:adjList[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}

};

int main(){
	Graph g(4);

	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(2,3);

	g.Print();

	cout<<endl;
	return 0;
}
