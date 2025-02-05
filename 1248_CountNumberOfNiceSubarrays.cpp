#include<iostream>
#include<vector>
using namespace std;
class solution{
    int lessorequal(vector<int>nums,int k){
         int l=0;
        int oddcnt=0;
        int subarrays=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2) oddcnt++;
            while(oddcnt>k){
                if(nums[l]%2) oddcnt--;
                l++;
            }
            subarrays+=r-l+1;
        }
        return subarrays;
    }
  public:
    int numberoFSubarrays(vector<int>& nums,int k){
       return lessorequal(nums,k)-lessorequal(nums,k-1);
    }
};

int main(){
    solution obj;
    vector<int> nums={2,2,2,1,2,2,1,2,2,2};
    int ans=obj.numberoFSubarrays(nums,2);
    cout<<"SUBARRAYS COUNT IS: "<<ans; 
}