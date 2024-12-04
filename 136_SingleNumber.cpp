#include<iostream>
#include<vector>
using namespace std;
class sol{
    public:
int SingleNumber(vector<int>& nums){
    int ans=nums[0];
    for(int i=1;i<nums.size();i++){
        ans^=nums[i];
    }
    return ans;
}

};

int main(){
    vector<int> nums={4,1,2,1,2};
    sol obj;
    cout<<"Single number is :"<<obj.SingleNumber(nums);
}