#include <iostream>
#include <vector>

using namespace std;

int min(int distance[], bool visited[],int size){
    int min = INT_MAX;
    int minIndex;

    for(int i = 0; i < size;i++){
        if(!visited[i] && distance[i] <= min){
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void print(int distance[], int size){
    for(int i = 0; i < size; i++){
        cout << "To City " << i << " Distance is " << distance[i] << endl;
    }
}

void SSSP(vector<vector<int>> graph,int sourceNode){
        int distance[graph.size()];
        bool visited[graph.size()];

        //This is vertex Initialize step...
        for(int vertex = 0; vertex < graph.size(); vertex++){
            distance[vertex] = INT_MAX;
            visited[vertex] = false;
        }
        distance[sourceNode] = 0; //because distance is 0 from start node ti=o itself...

        for(int i = 0; i < graph.size(); i++){
            int k = min(distance, visited,graph.size());
            visited[k] = true;
            //This is relaxation step....
            for(int i = 0; i < graph.size(); i++){
                if(!visited[i] &&
                    graph[k][i] &&
                    distance[i] > graph[k][i] + distance[k] &&
                    distance[k] != INT_MAX){
                    distance[i] = distance[k] + graph[k][i];
                }
            }
        }
        cout << "Distance from the city " << sourceNode << endl;
        print(distance, graph.size());

}

int main() {
    vector<vector<int>>  graph = {{0,10,0,0,15,5},
                                  {10,0,10,30,0,0},
                                  {0,10,0,12,5,0},
                                  {0,30,12,0,0,20},
                                  {5,0,0,20,0,0}
                                  };
    //Enter the starting node....
    SSSP(graph,4);

    return 0;
}
