#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
int dp[N];
vector<int> decomposition(int n) {
    vector<int> res;
    while (n > 0) {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) dp[i] = 1e6;
    dp[n] = 0;
    queue<int> container;
    container.push(n);
    while (!container.empty()) {
        int cur = container.front();
        vector<int> comp = decomposition(cur);
        for (int x : comp) {
            if (x == 0) continue;
            if (dp[cur-x] > dp[cur] + 1) {
                dp[cur-x] = dp[cur] + 1;
                container.push(cur-x);
            }
        }
        container.pop();
    }
    cout << dp[0] << '\n';
    return 0;
}