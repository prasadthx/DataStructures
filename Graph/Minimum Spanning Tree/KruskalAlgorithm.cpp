#include<iostream>
#include<algorithm>

using namespace std;

struct Edge{
    int source;
    int destination;
    int weight;

    Edge(int source, int destination, int weight){
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    };

    Edge(){};
};

struct Graph{

    Edge *edges;

    int counter;

    int vertices;

    Edge *MST;

    int *parentArray;

    Graph(int edges, int vertices){
        this->edges = new Edge[edges];
        this->vertices = vertices;
        this->MST = new Edge[vertices];
        this->parentArray = new int[vertices - 1];
        for(int index=0; index < vertices; index++){
            this->parentArray[index] = -1;
        }
        counter = 0;
    };

    void PrintGraph(){
        for(int i = 0; i < counter ; i++){
            cout << edges[i].source << " " << edges[i].destination << " " << edges[i].weight << endl;
        }
        return;
    };

    void AddWeightedEdge(int source, int destination, int weight){
        Edge temp(source, destination, weight);
        edges[counter] = temp;
        counter++;
    }

    int findParent(int value){
        if(parentArray[value] == -1){
            return value;
        }
        return findParent(parentArray[value]);
    }
};

bool comparator(Edge a, Edge b){
    return a.weight < b.weight;
};


void KruskalAlgorithm(Graph &graph){
    sort(graph.edges, graph.edges + graph.counter, comparator);
    int count = 0;
    int index = 0;
    while(count != graph.vertices - 1){
        if(index > graph.counter){
            cout << "MST can't exist" << endl;
            break;
        }
        Edge currentEdge = graph.edges[index];

        int sourceParent = graph.findParent(currentEdge.source);
        int destinationParent = graph.findParent(currentEdge.destination);

        if (sourceParent != destinationParent){
            graph.MST[count] = currentEdge;
            count++;
            graph.parentArray[sourceParent] = destinationParent;
        }

        index++;
    }
    for(int i=0; i < graph.vertices-1 ; i++){
        cout << graph.MST[i].source << " " << graph.MST[i].destination << " " << graph.MST[i].weight << endl;
    }
}

int main() {
    Graph g(15, 6);
    g.AddWeightedEdge(0, 1, 4);
    g.AddWeightedEdge(0, 2, 4);
    g.AddWeightedEdge(1, 2, 2);
    g.AddWeightedEdge(1, 0, 4);
    g.AddWeightedEdge(2, 0, 4);
    g.AddWeightedEdge(2, 1, 2);
    g.AddWeightedEdge(2, 3, 3);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 2, 3);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(4, 2, 4);
    g.AddWeightedEdge(4, 3, 3);
    g.AddWeightedEdge(5, 2, 2);
    g.AddWeightedEdge(5, 4, 3);

    KruskalAlgorithm(g);

    return 0;
}

//clang++ KruskalAlgorithm.cpp -o KruskalAlgorithm.exe && KruskalAlgorithm.exe