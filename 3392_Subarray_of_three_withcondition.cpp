/* Problem-  Given an integer array nums, return the number of subarrays of
 length 3 such that the sum of the first and third numbers equals exactly half of the second number.
A subarray is a contiguous non-empty sequence of elements within an array */

#include <iostream>
#include<vector>
using namespace std;

class solution{
    public:
    int CountSubarrays(vector<int>& nums){
        int pairs=0;
        int left=0;
        int right=left+2;
        while(right<nums.size()){
            int sum=nums[left]+nums[right];
            if(sum==nums[left+1]/2.0) pairs++;
            left++;
            right++;
        }
        return pairs;
    }
};

int main(){
    vector<int> nums={0,0,0,0,0};
    solution obj;
    cout<<"Number of pairs are "<< obj.CountSubarrays(nums);
}