#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int lower[4*N], upper[4*N];
int base[N], inv_base[N];
void build(int a[], int id, int l, int r) {
    if (l == r) {
        a[id] = 1;
        return ;
    }
    int mid = l + (r - l) / 2;
    build(a, id * 2 + 1, l, mid);
    build(a, id * 2 + 2, mid + 1, r);
    a[id] = a[id*2+1] + a[id*2+2];
}
void remove(int a[], int id, int l, int r, int v) {
    if (v > r || v < l) return ;
    if (l == r) {
        a[id] = 0;
        return ;
    }
    int m = l + (r - l ) / 2;
    remove(a, id * 2 + 1, l, m, v);
    remove(a, id * 2 + 2, m + 1, r, v);
    a[id] = a[id*2+1] + a[id*2+2];
}
int getTotal(int a[], int id, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return a[id];
    int m = l + (r-l) / 2;
    return getTotal(a, id * 2 + 1, l, m, u, v) + getTotal(a, id * 2 + 2, m + 1, r, u, v);
}
int main() {
    int n;
    cin >> n;
    vector <pair<int,int>> a(n);
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
        cin >> a[i].first >> a[i].second;
        base[i] = i;
    }

    sort(order.begin(), order.end(), [&](int x, int y) {
        if (a[x].second == a[y].second) return a[x].first > a[y].first;
        return a[x].second < a[y].second;
    });
    reverse(order.begin(), order.end());
    build(upper, 0, 0, n-1);
    build(lower, 0, 0, n-1);

    sort(base, base + n, [&](int x, int y) {    
        if (a[x].first == a[y].first) return a[x].second > a[y].second;
        return a[x].first < a[y].first;
    });
    vector<int> ans[2] = {vector <int>(n), vector<int>(n)};
    for (int i = 0; i < n; ++i) {
        inv_base[base[i]] = i;
        // cout << a[base[i]].first << endl;
        // cout << a[order[i]].first << ' ' << a[order[i]].second << endl;
    }
    // cout << base[0] << endl;
    for (int i = 0; i < n; ++i) {
        // cout << getTotal(upper, 0, 0, n-1, base[0], n-1) << endl;
        int position = inv_base[order[i]];
        // cout << position << endl;
        remove(upper, 0, 0, n-1, position);
        ans[0][order[i]] = getTotal(upper, 0, 0, n-1, position, n-1);
    }
    reverse(order.begin(), order.end());
    // sort(base, base + n, [&](int x, int y) {    
    //     if (a[x].first == a[y].first) return a[x].second < a[y].second;
    //     return a[x].first < a[y].first;
    // });
    for (int i = 0; i < n; ++i) {
        int position = inv_base[order[i]];
        remove(lower, 0, 0, n-1, position);
        ans[1][order[i]] = getTotal(lower, 0, 0, n-1,0, position);
    }
    for (int i = 0; i < 2; ++i) {
        for (int x : ans[i]) cout << (x > 0) << ' ';
        cout << endl;
    }
    return 0;
}