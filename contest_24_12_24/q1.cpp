#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    long long n;
    long long ans=0;
    int steps=0;
    while (t--) {
        cin>>n;
        steps=0;
        while(n!=0){
            n/=4;
            steps++;
        }
        steps--;

        ans=pow(2,steps);
        cout<<ans<<endl;
    }
    return 0;
}