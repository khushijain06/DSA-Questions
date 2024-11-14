#include <iostream>
using namespace std;

class sol{
    public:
    void bitManipulation(int num,int i){
        int ibit = num>>(i-1) & 1;
        int setbit = num | (1<<i-1);
        int clear = num & ~(1<<i-1);
        cout<<ibit<<" "<<setbit<<" "<<clear;
    }
};
int main(){
    sol obj;
    obj.bitManipulation(8,1);;
}