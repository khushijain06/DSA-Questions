#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return (atmost(nums, k) - atmost(nums, k - 1));
        } 
        int atmost(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            int l = 0;
            int cnt = 0;
            for (int r = 0; r < nums.size(); r++) {
                mp[nums[r]]++;
                while (mp.size() > k) {
                    mp[nums[l]]--;
                    if (mp[nums[l]] == 0)
                        mp.erase(nums[l]);
                    l++;
                }
                cnt += r - l + 1;
            }
            return cnt;
        }
    };

int main(){
    Solution obj;
    vector<int> n={1,2,1,2,3};
    int ans = obj.subarraysWithKDistinct(n,2);
    cout<<"Subarrays with k diff integers: "<<ans;
    return 0;
}