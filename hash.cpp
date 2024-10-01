#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int hash[13]={};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    cout<<"take input of the number present in the array"<<endl;
    int res;
    cin>>res;
    cout<<hash[res-1];
}