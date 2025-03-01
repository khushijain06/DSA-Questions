#include<iostream>
#include<vector>
using namespace std;

class sol{
    public:
    vector<int> applyOperations(vector<int> &nums){
        int i=0;
        int j=0;
        int n=nums.size();
        vector<int> opr(n,0);
        while(i<n){
            if(nums[i]!=0){
                if(i<n-1 && nums[i]==nums[i+1]){
                    opr[j]=nums[i]*2;
                    i++;
                }
                else{
                    opr[j]=nums[i];
                }
                j++;
            }
            i++;
            }
            return opr;
        }
    };
    int main(){
        vector<int> nums ={ 0,2,2,3,1,1,0,0};
        sol obj;
        vector<int> ans;
       ans =  obj.applyOperations(nums);
       for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
       }
       return 0;
    }
