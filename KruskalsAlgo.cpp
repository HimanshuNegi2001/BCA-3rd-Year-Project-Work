#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
        int source;
        int dest;
        int weight;
};

bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent){
    if(parent[v] == v){
        return v;
    }
    return findParent(parent[v], parent);
}



void kruskalsAlgo(Edge *input, int v, int E){
    sort(input, input + E, compare);

    Edge *output = new Edge[v-1];

    int *parent = new int[v];

    for(int i=0; i<v; i++){
        parent[i] = i;
    }

    int count=0;
    int i=0;
    while(count != v-1){
        Edge currentEdge = input[i];

        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destParent){
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;

    }
    
    cout<<"Entered Edges are:\n";
    
    for(int i=0; i<v-1; i++){
    	if(output[i].source < output[i].dest){
    		cout << output[i].source << " "<< output[i].dest << " " << output[i].weight <<endl;    		
		}
		else{
			cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
		}
	}
}

int main(){
    int i;
    int V,E;
    cout<<"Enter the number of Vertices:";
    cin>>V;
    cout<<"Enter the number of Edges:";
    cin>>E;
    Edge *input = new Edge[E];
	cout<<"Enter the Sources, Destinations and Weights respectively:\n";
    for(i=0; i<E; i++){
        cin>>input[i].source;
        cin>>input[i].dest;
        cin>>input[i].weight;
    }

    kruskalsAlgo(input , V, E);
}

