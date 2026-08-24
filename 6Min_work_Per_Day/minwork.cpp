#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool checking(vector<int> vect, int cap, int days, int n){
    int sum=0;
    int daysreq=1;

        for(int i=0; i<n; i++){
            if(sum+vect[i]<=cap){
                sum+=vect[i];
            }else{
                daysreq++;
                sum=vect[i];
            }
        }
    return daysreq<=days;
}


int main(){
     int n;
    cout<<"Enter the N size: ";
    cin>>n;

    int days;
    cout<<"Enter no. of days: ";
    cin>>days;

    vector<int> vect(n);
    int tsum=0;
    for(int i=0; i<n; i++){
        cout<<"enter total tasks have to do on "<<i+1<<" num: ";
        cin>>vect[i];
        tsum+=vect[i];
    }


    int low = *max_element(vect.begin(), vect.end());
    int high = tsum;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;

        bool check = checking(vect, mid, days, n);

        if(check){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans;
}