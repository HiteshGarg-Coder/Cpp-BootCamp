// Dijkstras
#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <set>
using namespace std;

template <typename T>
class Graph{
public:
	map<T,list<pair<T,int> > > h;

	void addEdge(T u,T v,int dist,bool bidir=true){
		h[u].push_back({v,dist});
		if(bidir){
			h[v].push_back({u,dist});
		}
	}

	void Print(){
		for(auto node:h){
			cout<<node.first<<"-->";
			for(auto children:node.second){
				cout<<"("<<children.first<<","<<children.second<<") ";
			}
			cout<<endl;
		}
	}

	int SSSP(T src, T des){

		unordered_map<T,int> dist;
		// Mark the distance of every node as INT_MAX
		for(auto node:h){
			dist[node.first] = INT_MAX;
		}

		dist[src] = 0; // Mark the distance of source node from itself as zero

		set<pair<int,T> > s;
		s.insert({0,src});

		while(!s.empty()){
			auto p = *(s.begin());

			s.erase(s.begin());// Erase function takes the address
			T parent = p.second;
			int parentDist = p.first;

			for(auto children:h[parent]){

				if(dist[children.first]>parentDist + children.second){

					auto f = s.find({dist[children.first],children.first});
					if(f!=s.end()){

						s.erase(f);

					}

					dist[children.first] = parentDist + children.second;
					s.insert({dist[children.first],children.first});
				}
			}
		}

		for(auto node:dist){
			cout<<"Distance of "<<node.first<<" from "<<src<<" is "<<node.second<<endl;
		}
		
		return dist[des];
	}
};

int main(){
	
	Graph<char> g;

	g.addEdge('A','B',1);
	g.addEdge('C','B',2);
	g.addEdge('C','D',3);
	g.addEdge('C','A',4);
	g.addEdge('A','D',8);
	// g.Print();
	g.SSSP('A','D');

	cout<<endl;
	return 0;
}

