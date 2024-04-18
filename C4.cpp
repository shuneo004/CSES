#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    long long ans = 0;
    int prev ;
    cin >> prev;
    for (int next, i = 1; i < n; ++i) {
        cin >> next;
        ans += (prev > next) * (prev - next);
        prev = max(next, prev);
    }
    cout << ans << endl;
    return 0;
}