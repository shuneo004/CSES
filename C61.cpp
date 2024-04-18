#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    vector<int> price(n), number(n);
    for (int &x : price) cin >> x;
    for (int &x : number) cin >> x;
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int v = x; v >= price[i]; --v) {
            dp[v] = max(dp[v], dp[v-price[i]] + number[i]);
        }
    }
    // for (int v = 0; v <= x; ++ v) cout << dp[v] << ' ';
    // cout << endl;
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}