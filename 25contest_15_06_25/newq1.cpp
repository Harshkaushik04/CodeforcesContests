#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        int ans = 0;

        if ((long long)x * (b - a) > (long long)y * (a - b)) {
            swap(a, b);
            swap(x, y);
        }

        while (true) {
            if (k >= a && k >= b) {
                if (x < y) {
                    int cnt = (k - a) / x + 1;
                    ans += cnt;
                    k -= cnt * x;
                } else {
                    int cnt = (k - b) / y + 1;
                    ans += cnt;
                    k -= cnt * y;
                }
            } else if (k >= a) {
                int cnt = (k - a) / x + 1;
                ans += cnt;
                break;
            } else if (k >= b) {
                int cnt = (k - b) / y + 1;
                ans += cnt;
                break;
            } else {
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
