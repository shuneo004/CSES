#include <bits/stdc++.h>

using namespace std;

// Custom comparison struct for pairs
struct cmp {
    bool operator ()(const pair<int,int>& lhs, const pair<int,int>& rhs) const {
        if (lhs.second - lhs.first == rhs.second - rhs.first) return lhs.first < rhs.first;
        return lhs.second - lhs.first > rhs.second - rhs.first;
    }
};

int main() {
    int x, n;
    cin >> x >> n;

    // Read input data
    vector<int> a(n);
    for (int& elem : a) 
        cin >> elem;

    // Initialize sets and lists
    set<pair<int,int>, cmp> container;
    set<int> listed;
    // container.insert({0, x});
    listed.insert(0);
    listed.insert(x);

//     container.erase({0, x});
//     for (auto x : container) cout << x.first << ' ' << x.second << endl;
//     cout << endl;
//     container.insert({0, 3});
//     for (auto x : container) cout << x.first << ' ' << x.second << endl;
//     cout << endl;    container.insert({3, x});
//     for (auto x : container) cout << x.first << ' ' << x.second << endl;
//     cout << endl;    container.erase({3, x});
//     for (auto x : container) cout << x.first << ' ' << x.second << endl;
//     cout << endl;    container.insert({3, 6});
//     for (auto x : container) cout << x.first << ' ' << x.second << endl;
//     cout << endl;    container.insert({6, x});
//     for (auto x : container) cout << x.first << ' ' << x.second << endl;
//     cout << endl;
//     container.insert({6, 9});
//         for (auto x : container) cout << x.first << ' ' << x.second << endl;
//     cout << endl;
//     container.insert({4, 10});
//         for (auto x : container) cout << x.first << ' ' << x.second << endl;
//     cout << endl;
//     // Process the input data
    for (int i = 0; i < n; ++i) {
        auto upper = listed.lower_bound(a[i]);
        auto lower = prev(upper);
        
        // Calculate the interval size
        int interval_size = *upper - *lower;

        // Erase the interval from the set and the list
        int old_x = *lower;
        int old_y = *upper;
        // cout << container.size() << endl;

        container.erase({old_x, old_y});
        // listed.erase(lower);
        
        // Insert new intervals formed by the current element
        // cout << container.size() << endl;

        container.insert({old_x, a[i]});
        // container.insert({3, 6});
        // cout << container.size() << endl;

        container.insert({a[i], old_y});
        // cout << "remove " << old_x << ' ' << old_y << endl;
        // cout << "add " << old_x << ' ' << a[i] << endl;
        // cout << "add " << a[i] << ' ' << old_y << endl;
        listed.insert(a[i]);

        // cout << container.size() << endl;
        // Output the maximum interval size
        // for (auto x : container) {
        //     cout << x.first << ' ' << x.second << '\n';
        // }
        cout << (*container.begin()).second -  (*container.begin()).first << ' ';
        // cout <<endl;
    }

    cout << endl;

    return 0;
}
