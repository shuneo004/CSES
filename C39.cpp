#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<pair<pair<int,int>, int>> cus(n);
    for (int i = 0; i < n; ++i) {
        auto &a = cus[i].first;
        cus[i].second = i;
        cin >> a.first >> a.second;
    }
    sort(cus.begin(), cus.end(), [](pair<pair<int,int>,int> a, pair<pair<int,int>, int> b) {
        if (a.first.second == b.first.second) return a.first.first < b.first.first;
        return a.first.second < b.first.second;
    });
    set<pair<int,int>> st;
    vector<int> ans(n);
    int number = 0;
    for (int i = 0; i < n; ++i) {
        auto a = cus[i].first;
        auto it = st.lower_bound({a.first, 0});
        if (it != st.begin() && !st.empty()) {
            --it;
            
            // st.insert({a.second, (*it).second});
            ans[cus[i].second] = (*it).second;
            st.erase(it);
            st.insert({a.second, ans[cus[i].second]});
        } else {
            ans[cus[i].second] = st.size() + 1;
            st.insert({a.second, ans[cus[i].second]});
        }
        // cout << st.size() << endl;
        number = max(number, static_cast<int>(st.size()));
    }
    // cout << ans << endl;
    cout << number << endl;
    for (int x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}