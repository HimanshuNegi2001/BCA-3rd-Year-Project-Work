#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	void addEdge(int v, int w);

	void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

int main()
{
	Graph gh;
	gh.addEdge(0, 1);
	gh.addEdge(0, 2);
	gh.addEdge(1, 2);
	gh.addEdge(2, 0);
	gh.addEdge(2, 3);
	gh.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";
	gh.DFS(2);

	return 0;
}


