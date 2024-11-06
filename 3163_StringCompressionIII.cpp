#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
    string compressedString(string word){
       string comp="";
       int cnt=1;
       for(int i=1;i<word.length();i++){
        while(i<word.length() && cnt<9 && word[i]==word[i-1]){
            cnt++;
            i++;
        }
        comp.push_back(cnt+'0');
        comp.push_back(word[i-1]);
        cnt=1;
       }
       return comp;
    }
    void print(string s){
        for(char c:s){
            cout<<c;
        }
    }
};
int main(){
    solution obj;
    string compressed;
    obj.print(obj.compressedString("aaaaaaaaaaaaaabeee"));;
}
