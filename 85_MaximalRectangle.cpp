#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class sol{
   public:
     int maximalRectangle(vector<vector<char>> & matrix){
        int row = matrix.size();
        int col= matrix[0].size();
        int maxlen=0;
        vector<int>len(col+1,0);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                len[j]=matrix[i][j]=='1'?len[j]+1:0;
            }
            stack<int> stk;
            for(int j=0;j<len.size();j++){
                while(!stk.empty() && len[stk.top()]>=len[j]){
                       int ht= len[stk.top()];
                       stk.pop();
                       int wd= stk.empty()?j:j-stk.top()-1;
                       maxlen=max(maxlen,ht*wd);
                 }
                 stk.push(j);
            }
        }
        return maxlen;
     }
};

int main(){
    sol obj;
    vector<vector<char>> mat={
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}};
   int area= obj.maximalRectangle(mat); 
   cout<<"Max Area: "<<area;
}