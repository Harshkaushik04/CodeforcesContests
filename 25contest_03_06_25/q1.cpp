#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int n = 0;
        while (pow(2,n)-1< x) {
            n++;
        }
        cout << 2 * n + 1 << endl;
    }
    return 0;
}