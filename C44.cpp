#include <bits/stdc++.h>
using namespace std;
map <int, pair<int,int>> mp;
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int&x : a) cin >> x;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (mp.find(x - a[i] - a[j]) != mp.end()) {
                vector<int> ans;
                ans.push_back(mp[x-a[i]-a[j]].second + 1);
                ans.push_back(mp[x-a[i]-a[j]].first + 1);
                ans.push_back(i+1);
                ans.push_back(j+1);
                // cout << mp[x-a[i]-a[j]].second + 1 << ' ' << mp[x-a[i]-a[j]].first + 1<< ' ' << i + 1<< ' ' << j + 1<< endl;
                sort(ans.begin(), ans.end());
                for (int x : ans) cout << x << ' ' ;
                return 0;
            }
        }
        for (int j = 0; j < i; ++j) {
            mp[a[i] + a[j]] = make_pair(i, j);
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
