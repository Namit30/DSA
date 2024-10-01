#include<iostream>
using namespace std;

void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
       int curr=arr[i];
       for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
       }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    

}



int main(){
    int n;
    cin>>n;
    int* arr= new int [n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubblesort(arr,n);    
}