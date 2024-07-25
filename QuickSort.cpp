#include<iostream>
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int arr[],int low,int high){
    int pivot=high;
    int i=low-1;
    for(int j=low;j<high;j++){
        if (arr[j]<=arr[pivot]){
            swap(&arr[j],&arr[++i]);
        }
    }
        swap(&arr[i+1],&arr[pivot]);
        return i+1;
    }

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}
void printa(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={5,2,3,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"unsorted array"<<endl;
    printa(arr,n);
    quickSort(arr,0,n-1);
    cout<<"sorted version"<<endl;
    printa(arr,n);
}