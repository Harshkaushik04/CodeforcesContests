#include<bits/stdc++.h>
using namespace std;

int minimizeCost(vector<int> arr, int k) {
    int n = arr.size();
    int moveCost = 0;

    while (true) {
        bool changed = false;
        // Try all pairs
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i] > arr[j]) {
                    int diff = arr[i] - arr[j] - k;
                    if (diff <= 0) continue;

                    int alpha = diff / 2;
                    if (alpha == 0) continue;

                    arr[i] -= alpha;
                    arr[j] += alpha;
                    moveCost += alpha * k;
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }

    int valCost = 0;
    for (int x : arr) {
        valCost += x * (x + 1) / 2;
    }

    return valCost + moveCost;
}

int main(){
    int n,k,t,temp;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin>>temp;
            arr.emplace_back(temp);
        }
        int ans=minimizeCost(arr,k);
        cout<<ans<<endl;
    }
    return 0;
}
