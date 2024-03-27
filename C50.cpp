#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int&x : a) cin >> x;
    long long sum = 0;
    int theMax = a[0];
    for (int x : a) theMax = max(x, theMax);
    for (int x : a) sum += x;
    long long lhs = theMax, rhs = sum;
    long long ans = -1;
    while (lhs <= rhs) {
        long long valueChecker = lhs + (rhs - lhs) / 2;
        int cnt = 0;
        long long cur_sum = 0;
        for (int x : a) {
            if (cur_sum + x <= valueChecker) cur_sum += x;
            else {
                cur_sum = x;
                cnt ++;
            }
        }
        cnt += (cur_sum > 0);
        if (cnt <= k) ans = valueChecker, rhs = valueChecker - 1;
        else lhs = valueChecker + 1;
    }
    assert(ans != -1);
    cout << ans << endl;
    /*
    we can possible remove ans variable, but need note that 
    - whether removed ans, we couldnt know the final answer found or didn't find
    - if always exist the final answer, remove ans, the final answer is rhs + 1 (left = right + 1), it final point
    */
    return 0;
}
