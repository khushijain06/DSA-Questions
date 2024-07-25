#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> pascalTriangle(int rows){
      vector<vector<int>> pascal;
      for(int i=0;i<rows;i++){
        pascal.push_back(vector<int>(i+1,1));
      }
      for(int i=2;i<rows;i++){
        for(int j=1;j<pascal[i].size()-1;j++){
            pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
      }
      return pascal;
}
int main(){
    vector<vector<int>> traingle;
    traingle=pascalTriangle(5);
    for(const auto rows:traingle){
        for(const int num:rows){
            cout<<num<<" ";
        }
        cout<<"\n";
    }
};
