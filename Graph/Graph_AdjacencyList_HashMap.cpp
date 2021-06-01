//
// Created by Prasad on 6/1/2021.
//

#include<iostream>
#include<list>
#include<unordered_map>
//#include<cstring>

using namespace std;

class Graph{

    unordered_map<string, list< pair< string, int > > > adjacencyList;

public:

    void addEdge(string x, string y, bool isBidirectional, int weight){
        adjacencyList[x].push_back(make_pair(y, weight));
        if(isBidirectional){
            adjacencyList[y].push_back(make_pair(x, weight));
        }
    }

    void printAdjacencyList(){
        for(auto p:adjacencyList){
            string a = p.first;
            list<pair<string, int>> nbrs = p.second;

            cout << a << " -> ";
            for(auto nbr:nbrs){
                string dest = nbr.first;
                int dist = nbr.second;

                cout << dest << " " << dist << " ,";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph G1;
    G1.addEdge("A", "B", true, 20);
    G1.addEdge("B", "D", true, 40);
    G1.addEdge("A", "C", true, 10);
    G1.addEdge("C", "D", true, 40);
    G1.addEdge("A", "D", false, 50);

    G1.printAdjacencyList();
    return 0;
}

//clang++ Graph_AdjacencyList_HashMap.cpp -o Graph_AdjacencyList_HashMap.exe && Graph_AdjacencyList_HashMap.exe
