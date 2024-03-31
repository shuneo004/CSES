#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    const int MOD = 1e9 + 7;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[0] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 1; j <= min(i, 6); ++j) {
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
        // cout << i << ' ' << dp[i] << '\n';
    }
    cout << dp[n] << '\n';
    return 0;
}