#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int&x : a) cin >> x;
    vector <int> cnt(n + 1, 0);
    cnt[0] = 1;
    int sum = 0;
    long long ans = 0;
    for (int x : a) {
        sum += x;
        sum %= n;
        sum = (sum + n) % n;
        ans += cnt[sum] ++;
    }
    cout << ans << endl;
    return 0;
}
