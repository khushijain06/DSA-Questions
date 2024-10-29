#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class solution{
    public:
    bool wordBreak(string s,vector<string>& wordDict){
        int n=s.length();
        unordered_set<string>wordSet(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && wordSet.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
int main(){
    string s = "catsandog";
    vector<string> wordDic={"cats","sand","and","dog","cat"};
    solution obj;
    if(obj.wordBreak(s,wordDic)){
        cout<<"Yes! , it is breakable";
    }
    else cout<<"No!, not breakable word";
}