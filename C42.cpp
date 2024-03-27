#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <int> a(n);
    for (int&x : a) cin >> x;
    long long thesum = 0;
    long long themax = 0;
    for (int x : a) thesum += x;
    for (int x : a) themax = max((int)themax, x);
    cout << max(themax * 2, thesum) << endl;
    return 0;
}
