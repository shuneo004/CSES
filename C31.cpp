#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int total = 1;
    for (int v = 1; v <= n; ++v) {
        if (pos[v] < pos[v-1]) total ++;
    }
    // cout << total << endl;
    while (m -- ) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        swap(pos[a[x]], pos[a[y]]);
        swap(a[x], a[y]);
        cout << a[x] << ' ' << a[y] << endl;
        cout << pos[a[x]] << ' ' << pos[a[y]] << endl;
        if (abs(a[x] - a[y]) == 1 && abs(pos[a[x]] - pos[a[y]]) == 1) {
            if (a[x] < a[y]) total --;
            else total ++;
            cout << "first " << m << endl;
        } else {
            int p1 = pos[a[x] - 1]; // 2
            int p2 = pos[a[x] + 1]; // 0 
            int p3 = pos[a[y] - 1]; // 4
            int p4 = pos[a[y] + 1]; // 3
            int px = pos[a[x]];
            int py = pos[a[y]];
            if (p1 < px && py < p1) total ++;
            if (px < p1 && p1 < py) total --;
            if (px < p2 && p2 < py) total --;
            if (p2 < px && py < p2) total ++; 
            
            if (p3 < py && px < p3) total ++;
            if (py < p3 && p3 < px) total --;
            if (py < p4 && p4 < px) total --;
            if (p4 < py && px < p4) total ++;
            cout << "second " << m << endl;
        }
        for (int i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << endl;
        cout << total << endl;
    }
    return 0;
}