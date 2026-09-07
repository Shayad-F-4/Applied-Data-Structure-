#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& arr, int sum) {
    int n = arr.size();

    // dp[i][j] = true if sum j can be formed using first i elements
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Sum 0 can always be formed using an empty subset
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {

            // Don't include current element
            dp[i][j] = dp[i - 1][j];
          
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][sum];
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

    if (subsetSum(arr, sum))
        cout <<"Yes... Subset with given sum exists." << endl;
    else
        cout <<"No... Subset with given sum does not exist." << endl;

    return 0;
}
