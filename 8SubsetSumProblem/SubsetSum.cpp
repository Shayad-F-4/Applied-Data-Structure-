#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& arr, int n, int sum) {
    // If target sum is 0, subset exists
    if (sum == 0)
        return true;

    // If no elements are left
    if (n == 0)
        return false;

    // If current element is greater than sum, skip it
    if (arr[n - 1] > sum)
        return subsetSum(arr, n - 1, sum);

    // Include or exclude current element
    return subsetSum(arr, n - 1, sum) ||
           subsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main() {
    int n, sum;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> sum;

    if (subsetSum(arr, n, sum))
        cout << "Subset with given sum exists.";
    else
        cout << "Subset with given sum does not exist.";

    return 0;
}
