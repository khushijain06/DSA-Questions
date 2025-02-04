#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int mlen=0;
        int mfreq=0;
        unordered_map<char,int>mp;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            mfreq=max(mfreq,mp[s[r]]);
            if((r-l+1)-mfreq>k){
             mp[s[l]]--; 
             l++;
            }       
            else{
                 mlen= max(mlen,r-l); 
            }
        }
        return mlen+1;
    }
};

int main(){
    Solution obj;
    string word="ABAB";
   obj.characterReplacement(word,1);
   cout<<"Longest Repeating Character Replacement: "<<obj.characterReplacement(word,1)<<endl;
    return 0;   
}
