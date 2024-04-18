#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (n == 3 || n == 2)cout << "NO SOLUTION";
    else {
        for (int i = 1; i < n; i += 2) cout << i + 1 << ' ';
        for (int i = 0; i < n; i += 2) cout << i + 1 << ' ';

    }
    return 0;
}