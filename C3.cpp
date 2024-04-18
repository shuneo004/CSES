#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int ans = 0;
    for (int cnt = 0, i = 0; i < s.size(); ++i) {
        if (i == 0) cnt = 1;
        else if (s[i] != s[i-1]) cnt = 1;
        else cnt ++;
        ans = max(cnt, ans);
    }
    cout << ans << endl;
    return 0;
}