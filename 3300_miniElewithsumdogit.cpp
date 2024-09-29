#include<iostream>
#include<vector>
using namespace std;
class solution{
  int sum(int n){
    int sum=0;
    while(n!=0){
        sum+=n%10;
        n=n/10;
    }
    return sum;
  }
  public:
  int minElement(vector<int>& nums){
     int mini=1e9+1;
     for(int i=0;i<nums.size();i++){
        mini=min(mini,sum(nums[i]));
     }
     return mini;
  }
  void printarr(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
   cout<<endl;
  }
};
int main(){
    solution obj;
    vector<int> arr={999,19,199};
    cout<<"minimum sum of sigit is "<<obj.minElement(arr);
}