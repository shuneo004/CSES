#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t --) {
        int x, y;
        cin >> x >> y;
        long long layer = max(x, y);
        long long lower = (layer - 1) * (layer - 1);
        long long upper = layer * layer;
        if (layer % 2 == 1) {
            if (x < y) cout << upper - x + 1;
            else cout << lower + y;
        } else {
            if (x < y) cout << lower + x;
            else cout << upper - y + 1;
        }
        cout << '\n';
    }
    return 0;
}