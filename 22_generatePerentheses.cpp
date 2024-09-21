#include<iostream>
#include<vector>
#include<string>
using namespace std;
class solution{
    void helper(vector<string>&Parantheses,int op,int cl,string str,int n){
        if(op==n && cl==n){
            Parantheses.push_back(str);
            return;
        }
        if(cl<op){
            helper(Parantheses,op,cl+1,str+")",n);
        }
        if(op<n){
            helper(Parantheses,op+1,cl,str+"(",n);
        }
    }
    public:
    vector<string> generateParentheses(int n){
        vector<string> Parantheses;
        int op=0,cl=0;
        helper(Parantheses,op,cl,"",n);
        return Parantheses;
    }
    void printarr(vector<string> v){
        cout<<"[";
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<",";
        }
      cout<<"]";
    }
};
int main(){
    vector<string> parantheses;
    solution obj;
    parantheses =obj.generateParentheses(3);
    obj.printarr(parantheses);

}