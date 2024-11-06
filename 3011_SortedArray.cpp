#include<iostream>
#include<vector>
using namespace std;
class solution{
    int setbits(int n){
        int setbit=0;
        while(n){
            n=n&(n-1);
            setbit++;
        }
        return setbit;
    }
    public:
    bool canSortArray(vector<int>& nums){
        int prev=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int mini=nums[i];
            int largi=nums[i];
            while(i+1<nums.size() && setbits(nums[i])==setbits(nums[i-1])){
                mini=min(mini,nums[i+1]);
                largi=max(largi,nums[i+1]);
                i++;
            }
            if(prev>mini) return false;
            prev=largi;
        }
        return true;
    }
};
int main(){
    solution obj;
    vector<int>nums={1,2,3,4,5};
    if(obj.canSortArray(nums)) {cout<<"Yes, it can be sorted";}
    else {cout<<"NO, cant be sorted!";}
}