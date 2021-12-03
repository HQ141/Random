#include<iostream>
using namespace std;
#define io 7
void percdown(int *arr,int i,int n){
    int child=0;
    int temp;
    for(temp=arr[i];2*i+1<n;i=child){
        child = 2 * i + 1;
        if(child<n-1&&arr[child]>arr[child+1])
        child++;
        if(temp>arr[child])
            arr[i]=arr[child];
        else
        break;
    }
    arr[i]=temp;
}
void sort(int *arr){
    for (int i = io / 2-1 ; i >= 0; i--) {
        percdown(arr, i, 7);
        for (int i = 0; i < 7; i++) 
            cout << arr[i] << " ";
        cout << endl;
    }
    cout << endl;
    for(int j=io-1;j>0;--j){
        swap(arr[0],arr[j]);   
        percdown(arr,0,j);
        for (int i = 0; i < 7; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}
void shellsort(int * arr,int n) {
    int gap = 1;
    while (gap < n / 3)
        gap = gap * 3 + 1;
    for()
}
int main(){
    int *arr=new int[7];
    arr[0]=90;
    arr[1]=78;
    arr[2]=65;
    arr[3]=1009;
    arr[4]=98;
    arr[6] = 69;
    arr[5] = 85;
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    cout << endl;
    sort(arr);
    for(int i=0;i<7;i++)
        cout<<arr[i]<<" ";
}