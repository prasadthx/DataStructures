//
// Created by Prasad on 6/1/2021.
//

#include<iostream>
#include<map>
#include<queue>
#include<list>

using namespace std;

template<typename T>
class Graph{

    map< T, list<T> > adjacencyList;

public:

    void addEdge(T x, T y){
        adjacencyList[x].push_back(y);
        adjacencyList[y].push_back(x);
    }

    void breadthFirstSearch(T src){

        map< T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout << node << " ";
            for(int nbr:adjacencyList[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main(){
    Graph<int> G;
    G.addEdge(0, 1);
    G.addEdge(1, 2);
    G.addEdge(0, 3);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.breadthFirstSearch(0);
    return 0;
}

//clang++ Graph_BFS.cpp -o Graph_BFS.exe && Graph_BFS.exe