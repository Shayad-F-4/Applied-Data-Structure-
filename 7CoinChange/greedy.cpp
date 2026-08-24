#include <iostream>
#include <vector>
using namespace std;

int numOfCombinationSum(vector<int>& arr, int target){
    vector<int> dp(target + 1, 0);

    dp[0] = 1;

    for (int t = 1; t <= target; t++){
        for (int num : arr){
            if (t - num >= 0){
                dp[t] += dp[t - num];
            }
        }
    }

    return dp[target];
}

int main() {
    vector<int> arr = {1, 2, 3};

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    cout << "Number of combinations: "
         << numOfCombinationSum(arr, target);

    return 0;
}