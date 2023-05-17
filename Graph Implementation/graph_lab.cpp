#include <iostream>
#include<list>
#include <vector>

using namespace std;

struct Node{
    int label;
    vector<int> neighbours;
};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    Node* nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i < n;i++){
            nodes[i].label=i+1;
        }
    }

    void addedge(int u, int v){
        //select node u and push v into u's neighbour
        for(auto i = 0; i < n;i++){
            if(nodes[i].label == u)
                nodes[i].neighbours.push_back(v);
        }
        //select node v and push u into v's neighbour
        for(auto i = 0; i < n ; i++){
            if(nodes[i].label == v)
                nodes[i].neighbours.push_back(u);
        }
    }

    void print(){
        //lets iterate through each node and print its neighbours
        for(int i = 0; i < n; i++){
            cout << "vertices " << nodes[i].label << " Connected to ";
            for(auto j = 0; j < nodes[i].neighbours.size(); j++){
                cout << nodes[i].neighbours[j] << ' ';
            }
            cout << endl;
        }

    }
};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g->addedge(1,2);
    g->addedge(1,4);
    g->addedge(1,5);
    g->addedge(1,3);

    g->addedge(2,3);
    g->addedge(2,6);
    
    g->addedge(4,7);
    g->addedge(4,8);
    g->addedge(4,6);

    g->addedge(5,7);
    g->addedge(5,8);
    g->addedge(5,6);

    //print the graph adjaceny list
    g->print();
}
