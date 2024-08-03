#include<iostream>
#include<string>
using namespace std;
class solution{
    public:
    int maxDepth(string s){
        int ans=0;
        int skip=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' && skip>0){
                skip--;
                continue;
            }
            else if(s[i]==')') skip++;
            else if(s[i]=='(') ans++;
        }
        return ans;
    }
};
int main(){
    solution obj;
    string nested="(1)+((2))+(((3)))";
    cout<<"Maximumn nested depth is : "<< obj.maxDepth(nested);
    return 0;
}

//for explaination
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/solutions/5577338/simple-linear-time-counter-apprach/