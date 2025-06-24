#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        
        unordered_map<int, pair<int, int>> first_last;
        for (int i = 0; i < n; i++) {
            if (first_last.find(a[i]) == first_last.end()) {
                first_last[a[i]] = {i, i};
            } else {
                first_last[a[i]].second = i;
            }
        }
        
        long long min_cost = LLONG_MAX;
        for (auto &[val, pos] : first_last) {
            int left_count = pos.first;
            int right_count = n - pos.second - 1;
            long long cost = 1LL * left_count * val + 1LL * right_count * val;
            min_cost = min(min_cost, cost);
        }
        
        cout << min_cost << endl;
    }
    return 0;
}