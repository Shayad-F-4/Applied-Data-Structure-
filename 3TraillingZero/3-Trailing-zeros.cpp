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
    int check=-1;
    int ans=-1;

    if(5+(n-1)*6 == n){
        return -1;
    }

    while(low<=high){
        int mid = (low+high)/2;

        check = trailingZero(mid);

        if(check==n){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans;
}