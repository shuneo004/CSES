#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> prime;
void sieve() {
    bool isPrime[N];
    for(int i = 2; i < N; ++i) isPrime[i] = true;
    for (int i = 2; i*i < N; ++i) {
        if (isPrime[i] == true) {
            for (int j = i * i; j < N; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i < N; ++i) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
}
long long cal(long long a, long long b) {
    int k = 1;
    while (a * k <= b) {
        k *= 4;
    }
    return a * k;
}
int main(int argc, char const *argv[])
{
    sieve();
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        int cnt = 0;
        if (a <= 1) {
            long long root = sqrt(b) + 1;
            cout << root * root << '\n';
        } else {
            int checker = 0;
            long long split = 1;
            for (int i : prime) {
                if (a % i == 0) checker = 1;
                while (a % i == 0) {
                    if (a % (i * i) == 0) {
                        a /= i;
                        a /= i;
                    } else {
                        a /= i;
                        split *= i;
                    }
                }
            }
            if (checker == 0) {
                long long root = sqrt(a);
                if (root * root == a) {
                    cout << cal(1, b) << '\n';
                } else {
                    cout << cal(a, b) << '\n';
                }
            } else {
                cout << cal(split, b) << '\n';
            }
        }
    }
    return 0;
}