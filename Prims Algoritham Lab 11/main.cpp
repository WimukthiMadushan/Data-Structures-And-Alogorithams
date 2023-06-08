#include <iostream>
#include <vector>

using namespace std;


int minKey(int key[], bool mstSet[],int size){
    //find min value......
    int min = INT_MAX;
    int minIndex;

    for (int v = 0; v < size; v++)
        if (!mstSet[v] && key[v] < min){
            min = key[v];
            minIndex = v;
        }
    return minIndex;
}

void printMST(int parent[],vector<vector<int>> graph,int size){
    cout << "Minimum spanning tree source node is 0 " << endl;
    cout << "Edge " << ':' << " Weight " << endl;
    for (int i = 1; i < size; i++)
        cout << parent[i] << " - " << i << ": "
             << graph[i][parent[i]]<< endl;
}

void BuildMST(vector<vector<int>> graph){
    int parent[graph.size()];
    bool MST[graph.size()];
    int key[graph.size()];

    //Initialize arrays....
    for(int vertex = 0; vertex < graph.size()-1; vertex++){
        key[vertex] = INT_MAX;
        MST[vertex] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    int k;
    for(int vertex = 0 ; vertex < graph.size()-1; vertex++){
        k = minKey(key, MST,graph.size());
        MST[k] = true;
        for(int v = 0; v < graph.size(); v++){
            if(graph[k][v] < key[v] && graph[k][v] && graph[k][v] && !MST[v]){
                key[v] = graph[k][v];
                parent[v] = k;
            }
        }
    }
    printMST(parent,graph,graph.size());
}

int main() {
    vector<vector<int>> graph = {
                                {0,3,0,0,0,1},
                                {3,0,2,1,10,0},
                                {0,2,0,3,0,5},
                                {0,1,3,0,5,0},
                                {0,10,0,5,0,4},
                                {1,0,5,0,4,0}
                                };
    BuildMST(graph);
    return 0;
}
