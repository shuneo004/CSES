#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int,int> mp;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int left = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        mp[a[i]] ++;
        while (mp[a[i]] > 1) mp[a[left++]] --;
        ans = max(ans, i - left + 1);
    }
    cout << ans << endl;
    return 0;
}