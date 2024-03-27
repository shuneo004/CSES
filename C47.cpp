#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    vector <pair<long long, int> > a(n + 1);
    a[0].first = 0;
    a[0].second = 0;
    for (int i = 1; i <= n; ++i) {
        a[i].second = i;
        cin >> a[i].first;
        a[i].first += a[i-1].first;
    }
    sort(a.begin(), a.end(), [](pair<long long, int > a, pair<long long, int> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    // for (int i = 0; i <= n; ++i) {
    //     cout << a[i].first << ' ' << a[i].second << endl;
    // }
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        // cout << i << "dong \n";
        // cout << a[i].first << ' ' << a[i].second << endl;
        auto it = equal_range(a.begin(), a.end(), make_pair(a[i].first + x, a[i].second),[](pair<long long, int > a, pair<long long, int> b) {
            return a.first < b.first;
        });
        auto it2 = lower_bound(it.first, it.second, make_pair(a[i].first + x, a[i].second), [](pair<long long, int> a, pair<long long, int> b) {
            return a.second < b.second;
        });
        ans += it.second - it2;
        // int st = it.first - a.begin();
        // int fi = it.second - a.begin();
        // cout << st << ' ' << fi << endl;
        // for (int j = st; j < fi; ++j) {
        //     cout << a[j].first << ' ' << a[j].second << endl;
        // }
        // cout << endl;
    }
    cout << ans - (n + 1) * (x == 0)<< endl;
    return 0;
}
