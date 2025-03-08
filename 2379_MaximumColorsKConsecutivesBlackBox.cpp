#include <iostream>
#include <string>
using namespace std;

class solution{
    public:
    int minimumRecolors(string blocks,int k){
        int l=0;
        int tot=0;
        int whites=0;
        int minwhite = INT_MAX;
        for(int r=l;r<blocks.size();r++){
            if(blocks[r]=='W') whites++;
            tot++;
            if(tot==k){
                minwhite=min(minwhite,whites);
                char prev=blocks[l];
                l++;
                if(prev=='W') whites--;
                tot--;
            }
        }
        return minwhite;
    }
};
int main(){
    string s;
    int k;
    cout<<"Enter string containing W and B: "<<endl;
    cin>>s;
    cout<<"Enter k i.e consecutive black needed: "<<endl;
    cin>>k;
    solution obj;
    int minwhite=0;
    minwhite=obj.minimumRecolors(s,k);
    cout<<" Min whites required are: "<<minwhite;

}