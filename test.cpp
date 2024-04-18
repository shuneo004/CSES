#include <bits/stdc++.h>

using namespace std;

// Custom comparison struct for pairs
    // Define value_type typedef required by std::vector

    bool cmp (pair<int,int>lhs, pair<int,int> rhs)  {
        if (lhs.second - lhs.first == rhs.second - rhs.first) return lhs.first < rhs.first;
        return lhs.second - lhs.first > rhs.second - rhs.first;
    }


int main() {
    vector<pair<int,int>> a;
    sort(a.begin(), a.end(), cmp);
    // Rest of your code...
    return 0;
}
