#include <iostream>
#include<queue>
using namespace std;

class Solution{
    public:
    int prims(vector<vector<pair<int,int>>> adj,int v){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            vector<int> vis(v,0);
            pq.push({0,0});
            int sum = 0;
            while(!pq.empty()){
                auto it  = pq.top();
                pq.pop();
                int node = it.second;
                int wt = it.first;
                if(vis[node]) continue;
                vis[node]=1;
                sum+=wt;
                for(auto it: adj[node]){
                    int adjnode = it.first;
                    int edw = it.second;
                    if(!vis[adjnode])
                        pq.push({edw,adjnode});
                
            }
    }
    return sum;
}
};

int main(){
    int v =5;
    vector<vector<int>> edges = {
        {0,1,2},
        {0,2,1},
        {1,2,1},
        {2,3,2},
        {3,4,1},
        {4,2,2}
    };
    vector<vector<pair<int,int>>> adj(v);
    for(vector<int> edge:edges){
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
        }
    Solution obj;
    cout<<obj.prims(adj,v);

}