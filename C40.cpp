#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, t;
    cin >> n >> t;
    vector <int> a(n);
    for (int&x : a) cin >> x;
    long long left = 1, right = 1e18;
    while (left <= right) {
        // cout << left << ' ' << right << endl;
        long long cal = 0;
        long long val = left + (right - left) / 2;
        for (int x : a) {
            cal += val / x;
            if (cal >= t) break;
        }
        if (cal >= t) right = val - 1;
        else left = val + 1;
    }
    cout << left << endl;
    return 0;
}