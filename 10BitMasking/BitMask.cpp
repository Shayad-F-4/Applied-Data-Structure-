#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<vector<int>> subsets;

    // Generate all subsets using bit masking
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
            }
        }

        subsets.insert(subset);
    }

    // Print distinct subsets
    for (auto subset : subsets) {
        cout << "{ ";

        for (int x : subset) {
            cout << x << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}