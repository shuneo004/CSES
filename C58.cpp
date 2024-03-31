#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int&x : a) cin >> x;
    vector<long long> dp(x + 1, 0);
    dp[0] = 1;
    const int MOD = 1e9 + 7;
    for (int aa : a) {
        for (int v = aa; v <= x; ++v) {
            dp[v] += dp[v-aa];
            dp[v] %= MOD;
        }
    }
    cout << dp[x] << '\n';
    return 0;
}