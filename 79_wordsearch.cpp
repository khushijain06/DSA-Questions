#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class solution{
    bool dfs(vector<vector<char>> board,string word,int i,int j,int ind){
        if(ind==word.size()) return true;
        if(i<0||j<0||i>board.size()||j>board[0].size()||word[ind]!=board[i][j]) return false;
        char temp=board[i][j];
        board[i][j]='*';
        bool found= dfs(board,word,i+1,j,ind+1)||dfs(board,word,i-1,j,ind+1)||dfs(board,word,i,j+1,ind+1)||dfs(board,word,i,j-1,ind+1);
        board[i][j]=temp;
        return found;
    }
    public:
    bool esist(vector<vector<char>>& board,string word){
        unordered_map<char,int> count;
        for(char c:word){
            count[c]++;
        }
        if(count[word[0]]>=count[word[word.size()-1]]) reverse(word.begin(),word.end());
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};
int main(){
    solution obj;
    vector<vector<char>> board={
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word="ABCCED";
    cout<<"Your ";
    cout<<"Word is present ?: "<<obj.esist(board,word);
    return 0;
}