#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class solution{
    public:
    string frequencysort(string s){
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }
        vector<pair<int,char>> srt;
        for(auto [c,val]:freq){
            srt.push_back({val,c});
        }
        sort(srt.begin(),srt.end());
        string res="";
        for(auto [val,c]:srt){
            while(val){
                res+=c;
                val--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
int main(){
    solution obj;
    string s="tree";
    string sorted=obj.frequencysort(s);
    cout<<"after sorting by character : ";
    for(char c:sorted){
        cout<<c;
    }
}
