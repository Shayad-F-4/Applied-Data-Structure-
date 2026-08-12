#include<iostream>
#include<vector>
using namespace std; 

int MaxShopVisit(vector<int> &StartingTime, vector<int> &EndingTime, vector<string> &Shops, int n, int k){

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(EndingTime[j]<=EndingTime[i]){
                swap(EndingTime[i],EndingTime[j]);
                swap(StartingTime[i],StartingTime[j]);
                swap(Shops[i],Shops[j]);
            }
        }
    }

    vector<int> person(k,-1);
    vector<int> countByperson(k,0);

    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            if(person[j]<=StartingTime[i]){
                cout<<"person "
                <<j+1<<" Visits Shop "<< Shops[i] 
                <<" At [ Starting Time: "<<StartingTime[i]<<" - Ending Time: "<<EndingTime[i]<<" ]"<<endl;
                person[j]=EndingTime[i];
                countByperson[j]++;
                count++;
                break;
            }
        }
    }
    for(int i=0; i<k; i++){
        cout<<"person "<<i+1<<" visits "<<countByperson[i]<<" Shops "<<endl;
    }
    
    return count;
}
int main(){
    int n;
    int k;


    cout<<"Enter the number of shops: ";
    cin>>n;

    cout<<"Enter number of persons: ";
    cin>>k;

    vector<int> StartingTime(n);
    vector<int> EndingTime(n);
    vector<string> Shops(n);

    for(int i=0; i<n; i++){
        cout<<"Shop Name:(A,B,C or 1,2,3)";
        cin>>Shops[i];
        cout<<"Strting Time: ";
        cin>>StartingTime[i];
        cout<<"Ending Time: ";
        cin>>EndingTime[i];
    }

    int ans = MaxShopVisit(StartingTime, EndingTime, Shops, n, k);
    cout<<"Total Visited shops(in min time): "<<ans;
    
    return 0;
}