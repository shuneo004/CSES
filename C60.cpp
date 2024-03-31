#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string mat[n];
    int dp[n][n];
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }
    int const MOD = 1e9+ 7;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == '*') dp[i][j] = 0;
            else if (i == 0 && j == 0) dp[i][j] = 1;
            else if (i == 0) {
                dp[i][j] = dp[i][j-1];
            } else if (j == 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            dp[i][j] %= MOD;
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }
    cout << dp[n-1][n-1] << '\n';
    return 0;
}