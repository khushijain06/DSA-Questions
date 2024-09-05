#include<iostream>
using namespace std;
class solution{
    public:
    double pow(double x,int n){
        double res=1.0;
        if(n==0) return res;
        if(n==1) return x;
        long long nn=n;
        if(n<0) nn=nn*-1;
        while(nn>1){
            if(nn%2!=0){
                res*=x;
            }
            x*=x;
            nn=nn/2;
        }
        return (n<0)?double(1.0)/double(res*x):res*x;
    }
};
int main(){
    solution obj;
   cout<<"Click Enter to x^n";
   cout<<"ENter x: ";
   double x;
   cin>>x;
   cout<<"Enter n: ";
   int n;
   cin>>n;
   cout<<x<<"^"<<n<<" is "<<obj.pow(x,n);
}