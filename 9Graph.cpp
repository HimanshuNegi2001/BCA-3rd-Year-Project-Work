#include <iostream>
#include <vector>
using namespace std;
 
struct Edge {
    int src, dest;
};
 
class Graph{
public:
    vector<vector<int>> adj;
 
    Graph(vector<Edge> const &edges, int n){
        adj.resize(n);
 
        for (auto &edge: edges){
            adj[edge.src].push_back(edge.dest);
        }
    }
};

void DisplayGraph(Graph const &graph, int n){
    for (int i = 0; i < n; i++){

        cout << i << " ——> ";
 
        for (int v: graph.adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}
 
int main(){
    vector<Edge> edges ={
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };

    int n = 6;

    Graph graph(edges, n);
 
    DisplayGraph(graph, n);
 
    return 0;
}