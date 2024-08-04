#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;
void QuickSort(vector<int>&arr,int L,int R){
    int x=arr[(L+R)/2];
    int i=L;
    int j=R;
    do{
        while(arr[i]<x) i++;
        while(arr[j]>x) j--;
        if(i<=j){
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;j--;
        }
    }while(i<=j);
    if(L<j) QuickSort(arr,L,j);
    if(i<R) QuickSort(arr,i,R);
}
// void check(vector<int>arr){
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 int temp=arr[i];
//                 arr[i] = arr[j];
//                 arr[j]=temp;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }
int Max(int a,int b){
    if(a>b)
        return a;
    return b;
}
int pickingNumbers(vector<int> arr) {
    QuickSort(arr,0,arr.size()-1);
    
    cout<<endl;
    int max=0;
    for(int i=0;i<arr.size();i++){
        int cnt=0;
        for(int j=i;j<arr.size();j++){
            if(abs(arr[i]-arr[j])<=1){
                cnt++;
            }
        }
        if(max<cnt){    
            max=cnt;
        }
    }
    cout<<max<<endl;
    return max;
}

int main(){
    int n;
    cout<<"Nhap N = ";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){   
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<pickingNumbers(arr);
    return 0;
}