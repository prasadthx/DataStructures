//
// Created by Prasad on 5/25/2021.
//

#include<iostream>
#include<list>

using namespace std;

class Graph{

    int Vertices;
    list<int> *adjacencyList;

public:

    Graph(int Vertices){
        this->Vertices = Vertices;
        adjacencyList = new list<int>[Vertices];
    }

    void addEdge(int x, int y){
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    void printAdjacencyList(){
        for(int i = 0; i < Vertices; i++){
            cout << "Vertex " << i << "-> " ;
            for(int j : adjacencyList[i]){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph G1(4);
    G1.addEdge(0, 1);
    G1.addEdge(0, 2);
    G1.addEdge(2, 3);
    G1.addEdge(1, 2);

    G1.printAdjacencyList();
    return 0;
}

//clang++ Graph.cpp -o Graph.exe && Graph.exe
