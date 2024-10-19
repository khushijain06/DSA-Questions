#include <iostream>
#include<vector>
using namespace std;
class sol{
    void help(int val,int target,int k,vector<vector<int>>&ans,vector<int>sums){
        //if current vector is full i.e k=0
        if(k==0){
            if(target==0) ans.push_back(sums);
            return;
        }
    //adding value still 9 an checking if target=0
        for(int i=val;i<10;i++){
            //if target is negative or current i is greater than target then not possible so break
            if(target<0 || i>target) break;
            sums.push_back(i);
            help(i+1,target-i,k-1,ans,sums);
            sums.pop_back();
        }
    }
   public:
     vector<vector<int>> combinationSum(int k,int n){
        vector<vector<int>> ans;
        vector<int> sums;
        help(1,n,k,ans,sums);
        return ans;
     }
     void print(vector<vector<int>> vec){
        for(int i=0;i<vec.size();i++){
            cout<<"[ ";
            for(int j=0;j<vec[0].size();j++){
                cout<<vec[i][j]<<" , ";
            }
         cout<<"] ";
        }
     }
};
int main(){
    sol obj;
    obj.print(obj.combinationSum(3,9));
}