#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    long long sum = 1LL * n * (n + 1) / 2;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        sum -= x;
    }
    cout << sum << endl;
    return 0;
}