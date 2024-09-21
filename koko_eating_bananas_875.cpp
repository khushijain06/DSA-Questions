#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool find(vector<int> pile,int m,int h){
        int hour=0;
        for(int i=0;i<pile.size();i++){
            hour+=(m+pile[i]-1)/m;
            if(hour>h) return false;
        }
        return true;
    }
   int minEatingTime(vector<int>& pile,int h){
      int high= INT_MIN;
      for(int i=0;i<pile.size();i++){
        high=max(high,pile[i]);
      }
      int low=1;
      while(low<=high){
        int mid=low+(high-low)/2;
        bool hours=find(pile,mid,h);
        if(hours) high=mid-1;
        else low=mid+1;;
      }
      return low;
   }
};
int main(){
     Solution obj;
     vector<int> pile={30,11,23,4,20};
     int ans= obj.minEatingTime(pile,5);
     cout<<"Min k Bananas to eat in each hour is "<<ans<<" ";
    return 0;
}