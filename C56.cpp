#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int&x : a) cin >> x;
    vector<int> dp(x + 1);
    dp[0] = 0;
    for (int v = 1; v <= x; ++v) {
        dp[v] = -1;
        for (int x : a) {
            if (v >= x) {
                if (dp[v-x] != -1) {
                    if (dp[v] == -1) dp[v] = dp[v-x] + 1;
                    else dp[v] = min(dp[v], dp[v-x] + 1);
                }
            }
        }
        // cout << dp[v] << ' ';
    }
    cout << dp[x] << '\n';
    return 0;
}