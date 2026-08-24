#include <iostream>
using namespace std;

int main() {
    int h[8];  
    int r[8];

    cout << "Enter 4 data bits (D1 D2 D3 D4): ";
    cin >> h[3] >> h[5] >> h[6] >> h[7];

    h[1] = h[3] ^ h[5] ^ h[7];
    h[2] = h[3] ^ h[6] ^ h[7];
    h[4] = h[5] ^ h[6] ^ h[7];

    cout << "\nGenerated Hamming Code: ";
    for (int i = 1; i <= 7; i++) {
        cout << h[i] << " ";
    }

    cout << "\n\nEnter received 7-bit Hamming code: ";
    for (int i = 1; i <= 7; i++) {
        cin >> r[i];
    }

    //syndrome bits
    int p1 = r[1] ^ r[3] ^ r[5] ^ r[7];
    int p2 = r[2] ^ r[3] ^ r[6] ^ r[7];
    int p4 = r[4] ^ r[5] ^ r[6] ^ r[7];

    //finding the error position 
    int errorPos = p4 * 4 + p2 * 2 + p1;

    if (errorPos == 0) {
        cout << "\nNo Error Detected.";
    } else {
        cout << "\nError Detected at Position: " << errorPos;
        r[errorPos] = r[errorPos] ^ 1;
        
        cout << "\nCorrected Hamming Code: ";
        for (int i = 1; i <= 7; i++) {
            cout << r[i] << " ";
        }
    }

    cout << "\nOriginal Data Bits: ";
    cout << r[3] << " " << r[5] << " " << r[6] << " " << r[7];

    return 0;
}