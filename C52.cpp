#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    multiset<int> s1, s2;
    long long sum1 = 0, sum2 = 0;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; ++i) {
        if (k <= i) {
            if (s2.find(a[i-k]) != s2.end()) {
                s2.erase(s2.find(a[i-k]));
                sum2 -= a[i-k];
            } else {
                s1.erase(s1.find(a[i-k]));
                sum1 -= a[i-k];
            }
        }
        s1.insert(a[i]);
        sum1 += a[i];
        // make balanced size
        while (s1.size() > s2.size() + 1) {
            sum1 -= *s1.rbegin();
            sum2 += *s1.rbegin();
            s2.insert(*s1.rbegin());
            s1.erase(prev(s1.end()));
        }
        // make balanced value
        while (!s1.empty() && !s2.empty() && *s1.rbegin() > *s2.begin()) {
            int x = *s1.rbegin();
            int y = *s2.begin();
            s1.erase(prev(s1.end()));
            s2.erase(s2.begin());
            s1.insert(y);
            s2.insert(x);
            sum1 += y - x;
            sum2 += x - y;
        }
        // cout << i << ' ' << s1.size() << ' ' << s2.size() << endl;
        if (k <= i + 1) {
            // cout << s1.size() << ' ' << s2.size() << endl;
            //cout << *s1.rbegin() << '\n';
            cout << s1.size() * *s1.rbegin() - sum1 + sum2 - *s1.rbegin() * s2.size() << ' ';
        }
    }
    return 0;
}