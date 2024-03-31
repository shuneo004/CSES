#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int&x : a) cin >> x;
    vector<long long> dp(x + 1);
    dp[0] = 1;
    const int MOD = 1e9 + 7;
    for (int v = 1; v <= x; ++v) {
        dp[v] = 0;
        for (int x : a) {
            if (v >= x ) dp[v] += dp[v-x];
            dp[v] %= MOD;
        }
        // cout << dp[v] << '\n';
    }
    cout << dp[x] << '\n';
    return 0;
}