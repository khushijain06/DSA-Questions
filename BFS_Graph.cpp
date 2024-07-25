#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> bfs(vector<int>adj[],int n){
    vector<int> traversal;
    queue<int> q;
    vector<int> isvisit(n,0);
    q.push(0);
    isvisit[0]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        traversal.push_back(node);
        for(auto it: adj[node]){
            if(!isvisit[it]){
                q.push(it);
                isvisit[it]=1;
            }
        }
    }

return traversal;
}
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int>bfs){
    for(int i=0;i<bfs.size();i++){
        cout<<bfs[i];
    }
}
int main(){
    vector<int> adj[5];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,2,4);
   vector<int> ans= bfs(adj,5);
   print(ans);
   return 0;
}