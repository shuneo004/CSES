#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    // k people, n movies
    int k = 1, n;
    cin >> n;
    vector <pair<int,int>> a(n);
    for (auto &x : a) cin >> x.first >> x.second;
    sort(a.begin(), a.end(), [](pair<int,int> a, pair<int,int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    multiset<int> container;
    container.insert(0);
    int ans = n;
    for (int i = 0; i < n; ++i) {
        // cout << i << ' ' << a[i].first << ' ' << a[i].second << endl;
        auto it = container.upper_bound(a[i].first);
        if (it == container.begin()) {
            // cout << "inner 1\n";
            if (container.size() < k) {
                container.insert(a[i].second);
            } else ans --;
        } else {
            // cout << "inner 2\n";
            --it;
            container.erase(it);
            container.insert(a[i].second);
        }
        // cout << container.size() << endl;
    }
    cout << ans << '\n';
    return 0;
}