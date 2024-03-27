#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> a(n);
    vector<int> ans(n);
    for (int&x : a) cin >> x;
    vector <int> container;
    for (int i = n-1; i > -1; --i) {
        while (!container.empty() && a[i] < a[*container.rbegin()]) {
            ans[*container.rbegin()] = i;
            container.pop_back();
        }
        container.push_back(i);
    }
    for (int x : container) ans[x] = -1;
    for (int x : ans) cout << x + 1 << ' ' ;
    cout << endl;
    return 0;
}
