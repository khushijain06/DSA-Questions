#include<iostream>
#include<string>
using namespace std;
string removeouter(string s){
    int brkt=0;
    string str="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            if(brkt>0){
                str+=s[i];
            }
            brkt++;
        }
        else{
            brkt--;
            if(brkt>0){
                str+=s[i];
            }
        }
        }
        return str;
}
int main(){
    string s="(()())(())";
    string removedouter=removeouter(s);
    cout<<"string after removing outer paranthesis"<<"\n";
    for(char c:removedouter){
        cout<<c<<" ";
    }
    return 0;
}