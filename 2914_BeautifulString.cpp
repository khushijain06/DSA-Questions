#include<iostream>
using namespace std;

class solution{
    public:
    int minChanges(string s){
        int i=0;
        int changes=0;
        while(i<s.size()-1){
            if(s[i]!=s[i+1]) changes++;
            i++;
        }
        return changes;
    }
};

int main(){
    solution obj;
    cout<<"Minimum Required changes to make string beautiful are: "<< obj.minChanges("1001");
    return 0;
}