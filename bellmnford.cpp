#include <iostream>
#include<vector>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
    int wt;
};

class Graph{
    public:
    int vertices;
    int edges;
    vector<Edge> EdgeList;

    Graph(int v,int e){
        vertices=v;
        edges=v;
        EdgeList.reserve(edges);
    }

    void addEdge(int src,int dest,int wt){
        Edge edge={src,dest,wt};
        EdgeList.push_back(edge);
    }
    void bellmanford(int startvertex){
        vector<int> dist(edges,INT_MAX);
        dist[startvertex]=0;
        for(int i=1;i<vertices-1;i++){
            for(Edge edge: EdgeList){
                int u=edge.src;
                int v=edge.dest;
                int wgt=edge.wt;
                if(dist[u]!=INT_MAX && dist[u]+wgt<dist[v])
                     dist[v]=dist[u]+wgt;
            }
        }
//check negative cycle
      for(Edge edge: EdgeList){
                int u=edge.src;
                int v=edge.dest;
                int wgt=edge.wt;
                if(dist[u]!=INT_MAX && dist[u]+wgt<dist[v])
                    cout<<"Graph contains negative cycle!";
            }

            printdist(dist);
    }
 private:
  void printdist(vector<int> dist){
      cout<<"Vertex\tDistance From the source"<<endl;
      for(int i=0;i<dist.size();i++){
        cout<<i<<"\t"<<dist[i]<<endl;
      }
  }


};

int main(){
    Graph g(5,8);
    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);
    g.bellmanford(0);
}