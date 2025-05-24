#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n / 2; ++i) {
            a[i] = i + 1;
            a[n - i - 1] = i + 1;
        }
        if (n % 2 != 0) {
            a[n / 2] = n / 2 + 1;
        }

        for (int x : a) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
