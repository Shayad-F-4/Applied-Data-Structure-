#include <iostream>
using namespace std;

int main() {
    int s[7];
    for(int i=0; i<8; i++){
        cin>>s[3]>>s[5]>>s[6]>>s[7];
    }
    int s[1] = s[3] ^ s[5] ^ s[7];
    int s[2] = s[3] ^ s[6] ^ s[7];
    int s[4] = s[5] ^ s[6] ^ s[7];

    for(int i=1; i<=7; i++){
        cout<<s[i]<<" ";
    }

    int arr[7];

    for(int i=1; i<=7; i++){
        cin>>arr[i];
    }

    int p1 = arr[1] ^ arr[3] ^ arr[5] ^ arr[7]; 
    int p2 = arr[2] ^ arr[3] ^ arr[6] ^ arr[7]; 
    int p4 = arr[4] ^ arr[5] ^ arr[6] ^ arr[7]; 
    
    int error_pos = p4*4 + p2*2 + p1; 
    cout<<error_pos;
    return 0;
}

