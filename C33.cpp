#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    multiset<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        auto it = a.upper_bound(x);
        if (it == a.end()) {
            a.insert(x);
        } else {
            a.erase(it);
            a.insert(x);
        }
    }
    cout << a.size() << endl;
    return 0;
}