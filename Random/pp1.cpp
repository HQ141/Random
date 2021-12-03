#include<iostream>
using namespace std;
void print(int *arr,int i,int j){
    cout<<"{";
    for(;i<=j;i++){
        cout<<arr[i]<<',';
    }
    cout<<"}";
}
int main(){
    int * arr=new int [4];
    
    for(int i=0;i<4;i++)
        cin>>arr[i];
    int i=0,j=0;
    int k;
    cin>>k;
    int sum=1;
    for(int a=0;a<4;a++){
        sum=1;
        for(int i=a;i<4;i++){
            sum*=arr[i];
            if(sum<k){
                print(arr,a,i);
            }
        }
    }
}