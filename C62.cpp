#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int32_t main(int32_t argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (i == 0) {
            if (x == 0) {
                for (int j = 1; j <= m; ++j) dp[i][j] = 1;
            } else {
                dp[i][x] = 1;
            }
        } else {
            if (x == 0) {
                for (int j = 1; j <= m; ++j) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] + dp[i-1][j];
                }
            } else {
                dp[i][x] = dp[i-1][x-1] + dp[i-1][x+1] + dp[i-1][x];
            }
        }
        for (int j = 0; j <= m; ++j) dp[i][j] %= MOD;
        // for (int j = 0; j <= m; ++j) cout << dp[i][j] << ' ' ;
        // cout << endl;
    }
    long long ans = 0;
    for (int j = 0; j <= m; ++j) {
        ans += dp[n-1][j];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}