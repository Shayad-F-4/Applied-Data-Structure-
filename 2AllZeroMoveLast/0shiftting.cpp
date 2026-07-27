#include <iostream>
#include <algorithm>
using namespace std;

void shiftZeroEndAndSort(int arr[], int n){
    sort(arr, arr + n);
    
    int idx = 0;
    for(int i=0;i<n; i++){
        if (arr[i] != 0) {
            arr[idx] = arr[i];
            idx++;
        }
    }
    while(idx < n){
        arr[idx] = 0;
        idx++;
    }
    for(int i=0; i<n; i++){                                                                                                                                                                                                                                                                                                                                                                                     
      
        cout<<arr[i]<<" ";
    }


}

int main() {
    int n = 6;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    shiftZeroEndAndSort(arr, n);
}
