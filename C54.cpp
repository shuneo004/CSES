#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    long long ans = -1e15;
    vector <long long> sum(n + 1, 0);
    multiset<long long> container;
    for (int i = 0; i < n; ++i) {
        sum[i+1] = sum[i] + arr[i];
        if (a <= i + 1) container.insert(sum[i+1-a]);
        // for (int x : container) cout << x << ' ';
        // cout << endl;
        if (b <= i) container.erase(container.find(sum[i-b]));
        if (!container.empty()) {
            ans = max(sum[i+1] - *container.begin(), ans);
            // cout << i + 1 << ' ' << sum[i+1] << ' ' << *container.begin() << ' '  << endl;

        }
    }
    cout << ans << '\n';
    return 0;
}