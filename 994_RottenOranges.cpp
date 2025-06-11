#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    int orangesRotting(vector<vector<int> >& grid){
        int n= grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> rotten;
        int total=0;
        int count=0;
        int min=0;
        int dz[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i =0 ;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }
        while(!rotten.empty()){
            int k = rotten.size();
            count+=k;
            while(k--){
                int z= rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++){
                    int nz = z+dz[i];
                    int ny= y+dy[i];
                    if(nz>=n || ny>=m || nz<0 || ny<0) continue;
                    if(grid[nz][ny]==1){
                        grid[nz][ny]=2;
                        rotten.push({nz,ny});
                    }
                }
            }
            if(!rotten.empty()) min++;
        }
        return count==total?min:-1;
    }
};
int main(){
    Solution obj;
    vector<vector<int> > grid = {
     {2,1,1},{0,1,1},{1,0,1}
    };  
    int minutes = obj.orangesRotting(grid);
    cout<<"DAYS TAKEN  TO ROTTEN ALL ORANGES :"<<minutes;
}