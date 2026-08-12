#include<iostream>
#include<vector>
using namespace std;

int BuySell(vector<int>&prices, int n){
    int maxprice=prices[n-1];
    int profit=0;
    int i=n-2;
    
    while(i>=0){
        if(prices[i]<maxprice){
            profit+=maxprice-prices[i];
        }else{
            maxprice=prices[i];
        }
        i--;
    }
    return profit;
}
int main(){
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;

    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int ans = BuySell(prices,n);
    cout<<"maximum profit will be "<<ans;
    return 0;
}