#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
int a[4*N];
void build(int id, int l, int r);
void remove(int id, int l, int r, int u);
int total(int id, int l, int r, int u, int v);
int find(int id, int l, int r, int u, int v, int x);
int main() {
    int n, k = 1;
    cin >> n;
    // n = 7, k = 2;
    build(0, 0, n - 1);
    // cout << total(0, 0, n-1, 0, 3) << endl;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        int cur = k % (n - i);
        cur ++;     
        if (total(0, 0, n-1, start, n-1) < cur) {
            cur -= total(0, 0, n-1, start, n-1);
            start = 0;
        } 
        int v = find(0, 0, n-1, start, n - 1, cur);
        remove(0, 0, n-1, v);
        // cout << cur << ' ' << start << ' ' << v << endl;
        start = v;
        cout << v + 1 << ' ';
    }
    // cout << total(0, 0, n-1, 0, 6) << endl;
    // cout << find(0, 0, n-1, 0, n-1, 2) << endl;
    return 0;
}
void build(int id, int l, int r) {
    if (l == r) {
        a[id] = 1;
        return ;
    }
    int m = l + (r - l) / 2;
    build(id * 2 + 1, l, m);
    build(id * 2 + 2, m + 1, r);
    a[id] = a[id*2+1] + a[id*2+2];
}
void remove(int id, int l, int r, int u) {
    if (u < l || u > r) return ;
    if (l == r) {
        a[id] = 0;
        return ;
    }
    int m = l + (r - l) / 2;
    remove(id * 2 + 1, l, m, u);
    remove(id * 2 + 2, m + 1, r, u);
    a[id] = a[id*2+1] + a[id*2+2];
}
int total(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return a[id];
    int m = l + (r - l) / 2;
    return total(id * 2 + 1, l, m, u, v) + total(id * 2 + 2, m + 1, r, u, v);
}
int find(int id, int l, int r, int u, int v, int x) {
    int lhs = u, rhs = v;
    while (lhs <= rhs) {
        int m = lhs + (rhs - lhs) / 2;
        // cout << lhs << ' ' << m << ' ' << rhs << ' '<< total(id, l, r, lhs, m) << ' ' << x << '\n';
        if (total(id, l, r, lhs, m) < x) {
            x -= total(id, l, r, lhs, m);
            lhs = m + 1;
        } else rhs = m - 1;
    }
    return lhs;
}
