#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    long long k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        unordered_map<int,int> mpp;
        int beauty = 0;
        for(int i = 0; i < 64; i++) mpp[i] = 0;

        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            for(int j = 0; j < 64; j++){
                if(((temp >> j) & 1) == 0) mpp[j]++;
                else beauty++;
            }
        }

        for(int i = 0; i < 64; i++){
            long long cost = 1LL << i;
            while(mpp[i] > 0 && k >= cost){
                k -= cost;
                mpp[i]--;
                beauty++;
            }
        }

        cout << beauty << '\n';
    }
    return 0;
}
