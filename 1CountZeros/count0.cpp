#include<iostream>
using namespace std;

int countZero(int arr[], int n){
    
    int low=0;
    int high=n-1;
    int firstzero=-1;
    
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==0){
            firstzero=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(firstzero==-1){
        return 0; // No zeros found
    }
    return n-firstzero; //Time C = O(logn)
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     cout<<"Total zero is: "<<countZero(arr,n);
}