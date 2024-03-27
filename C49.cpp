#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector <pair<int,int> > a(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = i;
        cin >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });
    for (int value = 0, i = 0; i < n; ++i) {
        if (i == n-1 || a[i].second == a[i+1].second) a[i].second = value;
        else a[i].second = value ++;
    }
    int cnt[a[n-1].second + 1];
    for (int i = 0; i < a[n-1].second + 1; ++i) cnt[i] = 0;
    sort(a.begin(), a.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.first < b.first;
    });
    int diff_value = 0;
    
    long long ans = 0;
    for (int left = 0, i = 0; i < n; ++i) {
        cnt[a[i].second] ++;
        if (cnt[a[i].second] == 1) diff_value += 1;
        while (diff_value > k) {
            cnt[a[left].second] --;
            if (cnt[a[left].second] == 0) diff_value -= 1;
            left ++;
        }
        ans += i - left + 1;
    }
    cout << ans << endl;
    // vector<int> a(n);
    // for (int&x : a) cin >> x;

    // multiset <int> container;
    // long long ans = 0;
    // int diff_value = 0;
    // for (int left = 0, right = 0; right < n; ++right) {
    //     container.insert(a[right]);
    //     if (container.count(a[right]) == 1) diff_value ++;
    //     while (diff_value > k) {
    //         container.erase(container.find(a[left]));
    //         if (container.count(a[left]) == 0) diff_value --;
    //         left ++;
    //     }
    //     ans += right - left + 1;
    // }
    // cout << ans << endl;
    return 0;
}
