#include<iostream>
#include<algorithm>
using namespace std;

int trailingZero(int n){
    int countZeros=0;
    while(n>0){
        n/=5;
        countZeros+=n;
    }
    return countZeros;
}

int main(){
    int n;
    cout<<"Enter no: ";
    cin>>n;

    int low=0;
    int high=n*5;
    int ans=-1;

    

    while(low<=high){
        int mid = (low+high)/2;

        int check = trailingZero(mid);

        if(check==n){
            ans=mid;
            high=mid-1;
        }
        else if(check<n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    
    }
    cout<<ans;
}