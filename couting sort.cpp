#include <iostream>
#include<vector>
using namespace std;

void countingsort(vector<int> &arr){
    int n= arr.size();
    vector<int>output(n);
  
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    vector<int>count(max,0);
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=max;i++){
       count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
void printarr(vector<int> a, int n){
    for(int i=0;i<n;i++){
        cout<< a[i];
    }
}
int main(){
    vector<int> hh={9,0,5,7,8,2};
    countingsort(hh);
     printarr(hh,hh.size());
    
}
    