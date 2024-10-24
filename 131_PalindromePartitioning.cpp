#include<iostream>
#include<string>
#include<vector>
using namespace std;

class solution{
    bool ispalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void find(vector<vector<string>> &partitions,vector<string>&palindromes,int start,string s){
        if(start==s.size()){
            partitions.push_back(palindromes);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(ispalindrome(start,i,s)){
                palindromes.push_back(s.substr(start,i-start+1));
                find(partitions,palindromes,i+1,s);
                palindromes.pop_back();
            }
        }
    }
     public: 
     vector<vector<string>> partition(string s){
        vector<vector<string>> partitions;
        vector<string> palindromes;
        find(partitions,palindromes,0,s);
        return partitions;
     }
     void print(vector<vector<string>> p){
        cout<<"[";
         for(int i=0;i<p.size();i++){
            cout<<"[ ";
            for(int j=0;j<p[i].size();j++){
                cout<<p[i][j]<<" , ";
            }
            cout<<"]";
         }
         cout<<"]";
     }
};
int main(){
    solution obj;
    obj.print(obj.partition("a"));
    return 0;
}
