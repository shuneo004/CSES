#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <pair<int,int>> a(n);
    for (pair<int,int> &x : a) {
        cin >> x.first >> x.second;
    }
    sort(a.begin(), a.end());
    long long cur = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cur += a[i].first;
        ans += a[i].second - cur;
    }
    cout << ans << endl;
    return 0;
}
