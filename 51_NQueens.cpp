#include<iostream>
#include<vector>
#include<string>
using namespace std;
class solution{
    bool isValid(vector<string> board,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
   void placeQ(vector<vector<string>> &result,vector<string>board,int row,int n){
    if(row==n) {
        result.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(isValid(board,row,j,n)){
             board[row][j]='Q';
             placeQ(result,board,row+1,n);
             board[row][j]='.';
        }
    }
   }
    public:
    vector<vector<string>> solvenQueens(int n){
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
        placeQ(result,board,0,n);
        return result;
    }
    void print(vector<vector<string>> boards,int n){
        for(int i=0;i<n;i++){
            cout<<"[";
            for(string s:boards[i]){
                cout<<s<<" , ";
            }
            cout<<"]";
            cout<<endl;
        }
    }
};
int main(){
    solution obj;
    obj.print(obj.solvenQueens(5),5);
}