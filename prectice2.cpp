#include<iostream>
#include<vector>
using namespace std;

int firstOcc(vector<int> &vect, int n, int x){
    int low=0;
    int high = n-1;
    int ans=-1;

    while(low<=high){
        int mid =high - (low+high) / 2;
        if(vect[mid]==x){
            ans=vect[mid];
            high = mid-1;
        }else if(vect[mid]<x){
            low = mid+1;
        }else{
            high =mid-1;
        }
    }
    return ans;
}
int lasttOcc(vector<int> &vect, int n, int x){
    int low=0;
    int high = n-1;
    int ans2=-1;

    while(low<=high){
        int mid =high - (low+high) / 2;
        if(vect[mid]==x){
            ans2=vect[mid];
            low=mid+1;
        }else if(vect[mid]<x){
            low = mid+1;
        }else{
            high =mid-1;
        }
    }
    return ans2;
}
int main(){
    int n;
    cout<<"N: ";
    cin>>n;
    vector<int> vect(n);

    for(int i=0; i<n; i++){
        cin>>vect[i];
    }

    int x;
    cout<<"X: ";
    cin>>x;

    int first = firstOcc(vect,n,x);
    int last = lasttOcc(vect,n,x);

    if(first==-1){
        cout<<0;
    }else{
        cout<<"ans: "<<last-first+1;
    }
    return 0;
}