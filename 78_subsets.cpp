#include<iostream>
#include<vector>
using namespace std;
class solution{
    void helper(vector<vector<int>>& powerset,vector<int>& set,int i,vector<int>nums){
        if(nums.size()==i){
            powerset.push_back(set);
            return;
        }
        set.push_back(nums[i]);
        helper(powerset,set,i+1,nums);
        set.pop_back();
        helper(powerset,set,i+1,nums);
    }
  public:
   vector<vector<int>> subsets(vector<int> nums){
     vector<vector<int>> powerset;
     vector<int> set;
     helper(powerset,set,0,nums);
     return powerset;
   }
   void two_D(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        cout<<"[";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<",";
        }
        cout<<"]";
        cout<<endl;
    }
   }

};
int main(){
    vector<int> nums={1,2,3};
    solution obj;
    vector<vector<int>> ans;
    ans=obj.subsets(nums);
    obj.two_D(ans);

}