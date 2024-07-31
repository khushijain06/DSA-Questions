#include<iostream>
#include<vector>
#include<string>
using namespace std;
class solution{
    public:
    string longestPrefix(vector<string>strs){
        string ans=strs[0];
        for(int i=0;i<strs.size();i++){
            string same="";
            int j=0;
            while(j<strs[i].length() && j<ans.size()){
                  if(ans[j]==strs[i][j])
                      same+=ans[j];
                  else break;
                   j++;
        }
        ans=same;
    }
      return ans;
    }
};
int main(){
    solution obj;
    vector<string> str={"flower","flow","flight"};
    string prefix="";
    prefix=obj.longestPrefix(str);
    cout<<"longes prefix is : ";
    for(char c : prefix){
        cout<<c;
    }
    return 0;
}